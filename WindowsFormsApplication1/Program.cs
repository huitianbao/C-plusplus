using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

            schedul sch = new schedul();
            sch.main();
            Thread.Sleep(10000);//10秒后结束

                public class schedul
    {
        public enum state//enum：枚举
        {
            ready,   //就绪
            execute, //执行
            block,   //阻塞
            finish   //完成
        }
        public struct processcontrolblock//结构声明
        { //进程控制块结构
            public string name;
            public int TimeComing;//到达时间
            public int TimeServer;//服务时间
            public int TimeBegin;//开始时间
            public int TimeEnd;//结束时间
            public int TimeCycle;//周转时间
            public double rate;
            public bool finish; 
        }
        private int TimeEnd = 0;
        public processcontrolblock pcb1 = new processcontrolblock();        
        public void main()
        {
            display_menu();//显示菜单
            int k;
            int NumPcb = 0;
            k = int.Parse(Console.ReadLine());
            Console.Clear();
            Console.WriteLine("请输入进程的个数:");
            NumPcb = int.Parse(Console.ReadLine());
            processcontrolblock[] m_pcb = new processcontrolblock[NumPcb];
            switch (k)//k为选择，控制菜单
            {
                case 1:              
                    FCFS(ref m_pcb); //调用先来先服调度函数
                    break;
                case 2:
                    processcontrolblock[] m_pcb1 = new processcontrolblock[NumPcb]; 
                    SJF(ref m_pcb1);  //调用轮转调度函数
                    break;
                case 3:
                    processcontrolblock[] m_pcb2 = new processcontrolblock[NumPcb];
                    HRRN(ref m_pcb2);
                    break;           
                case 4:
                    break;//退出
                default:
                    Console.WriteLine("Input error!");
                    break;
            }
        }

        public void display_menu()//显示菜单的构造函数
        {
            Console.WriteLine("请选择调度算法:" + "\n");
            Console.WriteLine("1 先来先运行");//先来先服务
            Console.WriteLine("2 最短作业优先");//最短作业优先
            Console.WriteLine("3 响应比高者优先");//响应比高者优先
            Console.WriteLine("4 退出");//退出
        }
        // 先来先服务 
        // <param name="m_pcb"></param>
        public void FCFS(ref processcontrolblock[] m_pcb) 
        {  
            Time(ref m_pcb);  //数据输入函数
            int n = 0;//保存先来的服务的索引
            for (int j = 0; j < m_pcb.Length; j++)
            {
                n = FirstIn(ref m_pcb); //求最先到达的服务
                int k = m_pcb[n].TimeServer;  //服务时间

                if (j != 0)  //不是第一个来的
                {
                    m_pcb[n].TimeBegin = TimeEnd;
                    TimeEnd += m_pcb[n].TimeServer;
                    m_pcb[n].TimeEnd = m_pcb[n].TimeBegin + m_pcb[n].TimeServer;   
                }
                else if (j == 0)  //第一个来的
                {
                    m_pcb[n].TimeBegin = m_pcb[n].TimeComing;
                    m_pcb[n].TimeEnd = m_pcb[n].TimeComing + m_pcb[n].TimeServer;
                    TimeEnd = m_pcb[n].TimeEnd;
                }
                m_pcb[n].TimeCycle = m_pcb[n].TimeEnd - m_pcb[n].TimeComing;
                m_pcb[n].finish = true;
                for (int i = 0; i < k; i++)
                {
                    Thread.Sleep(500);//if 无 一开始就结束
                    Console.Clear();  //清屏
                    m_pcb[n].TimeServer--;  //还需要的服务时间，循环一次，自减。
                    display(m_pcb);
                }
            }
        }
        // 最短作业优先
        // <param name="m_pcb"></param>
        public void SJF(ref processcontrolblock[] m_pcb)//最短作业优先带参数的构造函数
        {
            Time(ref m_pcb);  //数据输入函数
            int n = 0;//保存先来的服务的索引

            for (int j = 0; j < m_pcb.Length; j++)
            {
                n = Shortest(ref m_pcb); //求最先到达的服务
                int k = m_pcb[n].TimeServer;  //服务时间

                if (j != 0)  //不是第一个来的
                {
                    m_pcb[n].TimeBegin = TimeEnd;
                    TimeEnd += m_pcb[n].TimeServer;
                    m_pcb[n].TimeEnd = m_pcb[n].TimeBegin + m_pcb[n].TimeServer;
                }
                else if (j == 0)  //第一个来的
                {
                    m_pcb[n].TimeBegin = m_pcb[n].TimeComing;
                    m_pcb[n].TimeEnd = m_pcb[n].TimeComing + m_pcb[n].TimeServer;
                    TimeEnd = m_pcb[n].TimeEnd;
                }
                m_pcb[n].TimeCycle = m_pcb[n].TimeEnd - m_pcb[n].TimeComing;
                m_pcb[n].finish = true;

                for (int i = 0; i < k; i++)
                {
                    Thread.Sleep(500);
                    Console.Clear();  //清屏
                    m_pcb[n].TimeServer--;  //还需要的服务时间，循环一次，自减。
                    display(m_pcb);
                }
            }
        }
        // 最高响应比算法
        // <param name="m_pcb"></param>
        public void HRRN(ref processcontrolblock[] m_pcb)//响应比高者优先
        {
            Time(ref m_pcb);  //数据输入函数
            int n = 0;//保存先来的服务的索引

            for (int j = 0; j < m_pcb.Length; j++)
            {
                n = Highest(ref m_pcb); //求最先到达的服务
                int k = m_pcb[n].TimeServer;  //服务时间

                if (j != 0)  //不是第一个来的
                {
                    m_pcb[n].TimeBegin = TimeEnd;
                    TimeEnd += m_pcb[n].TimeServer;
                    m_pcb[n].TimeEnd = m_pcb[n].TimeBegin + m_pcb[n].TimeServer;
                }
                else if (j == 0)  //第一个来的
                {
                    m_pcb[n].TimeBegin = m_pcb[n].TimeComing;
                    m_pcb[n].TimeEnd = m_pcb[n].TimeComing + m_pcb[n].TimeServer;
                    TimeEnd = m_pcb[n].TimeEnd;
                }
                m_pcb[n].TimeCycle = m_pcb[n].TimeEnd - m_pcb[n].TimeComing;
                m_pcb[n].finish = true;

                for (int i = 0; i < k; i++)
                {
                    Thread.Sleep(500);
                    Console.Clear();  //清屏
                    m_pcb[n].TimeServer--;  //还需要的服务时间，循环一次，自减。
                    display(m_pcb);
                }
            }
        }
        // 数据输入函数
        // <param name="m_pcb">进程控制块信息数组</param>
        public void Time(ref processcontrolblock[] m_pcb)
        {
            for (int i = 0; i < m_pcb.Length; i++)
            {
                int m = i + 1;
                Console.WriteLine("输入第" + m + "个进程名称、到达时间、服务时间：");
                m_pcb[i].name = Console.ReadLine();  //输入进程名
                m_pcb[i].TimeComing = int.Parse(Console.ReadLine()); //输入进程到达时间
                m_pcb[i].TimeServer = int.Parse(Console.ReadLine()); //输入进程服务时间
            }
            Console.Clear();
        }
        // 求最早到达时间的作业，返回此作业在进程控制块数组中的索引号。
        // <param name="m_pcb">进程控制块信息数组</param>
        private int FirstIn(ref processcontrolblock[] m_pcb)
        {
            int n = 0;
            int m = 1000;  //设置最大服务时间1000个单位
            for (int j = 0; j < m_pcb.Length; j++)
            {
                if (m >= m_pcb[j].TimeComing && !m_pcb[j].finish) //求到达时间最小、并且是没完成的作业。
                {
                    m = m_pcb[j].TimeComing; //到达时间最小的作业的到达时间赋给m
                    n = j;//保存最小到达时间的索引号
                }
            }
            return n;
        }
        // 求最短服务时间的作业，返回此作业在进程控制块数组中的索引号。
        // <param name="m_pcb">进程控制块信息数组</param>
        private int Shortest(ref processcontrolblock[] m_pcb)
        {
            int n = 0;
            int TimeServer = 1000;//设置最短服务时间为1000个单位
            for (int j = 0; j < m_pcb.Length; j++)
            {
                //作业已经到时开始了
                if (m_pcb[j].TimeComing <= TimeEnd && TimeServer >= m_pcb[j].TimeServer && !m_pcb[j].finish)
                {
                    TimeServer = m_pcb[j].TimeServer;  //保存最小的服务时间
                    n = j;
                }
            }
            return n;
        }
        // 最高响应比
        // <param name="m_pcb"></param>
        private int Highest(ref processcontrolblock[] m_pcb)
        {
            int n = 0;
            double TimeDelay = 0.0;
            for (int j = 0; j < m_pcb.Length; j++)
            {
                //作业已经到时开始了
                int TimeWait = TimeEnd - m_pcb[j].TimeComing; //计算等待时间
                if (TimeWait >= 0 && !m_pcb[j].finish && TimeDelay <= TimeWait / m_pcb[j].TimeServer)
                {
                    TimeDelay = TimeWait / m_pcb[j].TimeServer;
                    n = j;
                }
            }
            return n;
        }
        public void display(processcontrolblock[] m_pcb)//展示结果
        {
            newmethond();
            for (int i = 0; i < m_pcb.Length; i++)
            {
                Console.WriteLine(m_pcb[i].name + "\t" + m_pcb[i].TimeComing + "\t"
                               + m_pcb[i].TimeServer + "\t" + m_pcb[i].TimeBegin + "\t"
                               + m_pcb[i].TimeEnd + "\t" + m_pcb[i].TimeCycle);
            }
        }
        public void newmethond() {
            Console.WriteLine("进程" + "\t" + "到达" + "\t" + "服务" + "\t" + "开始" + "\t" + "结束" + "\t" + "周转");
        }
    }
        }


    }

