#include<iostream>
using namespace std;

#include<string>

int main()
{
	cout<<"城市目录和价格"<<endl;
    
    cout<<"1 南京--100"<<endl<<"2 上海--200"<<endl<<"3 北京--300"<<endl<<"4 天津--400"<<endl<<"5 武汉--500"<<endl<<"6 杭州--600"<<endl;

	cout<<"请选择您要旅游的城市以确定路线,请先输入一个地点数字标号即可, 输入0结束"<<endl;

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

