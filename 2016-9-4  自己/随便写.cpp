#include<iostream>
using namespace std;

#include<string>

int main()
{
	cout<<"����Ŀ¼�ͼ۸�"<<endl;
    
    cout<<"1 �Ͼ�--100"<<endl<<"2 �Ϻ�--200"<<endl<<"3 ����--300"<<endl<<"4 ���--400"<<endl<<"5 �人--500"<<endl<<"6 ����--600"<<endl;

	cout<<"��ѡ����Ҫ���εĳ�����ȷ��·��,��������һ���ص����ֱ�ż���, ����0����"<<endl;

	int a[10];  //123
	int index;
	cin>>index;

	while(index!=0)
	{
		static int i=0;
		a[i]=index;
		i++;
		cout<<"Do you want to choose another city,if no please input 0(ling),choose 1~6 to go on"<<endl;
		
	}

	








return 0;
}

