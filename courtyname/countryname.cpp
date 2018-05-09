#include<iostream>
using namespace std;

/*
案例：
     【输出】请输入国家：
	 【输入】America
	 【输出】确认输入 America? 输入c/C 确认,输入r/R表示重新输入
	 【输入】 c
	 【输出】是否继续输入？输入y/Y表示继续，输入n/N表示结束
	 【输入】y
	 【输出】请继续输入国家
	 【输入】England
	 【输出】确认输入 England? 输入c/C 确认，输入r/R表示重新输入
	 【输入】 c
	 【输出】是否继续输入？输入y/Y表示继续，输入n/N表示结束
	 ..........(再依次输入  Australia  ,Sweden ,Finland ,N)

	 【输出】初始顺序
	          America         
	          England
		      Australia
		      Sweden
		      Finland

			  排序之后
			  America  
		      Australia
			  England
			  Finland
			  Sweden
*/

const int MaxLength=50;
const int N=40;

int main(){

char name[N][MaxLength];

//char *pstr[N];

cout<<"请输入国家:"<<endl;

char c='c';
do{
	int i=0;
	
	cout<<"确认输入"<<name[i]<<"?"<<"输入c /C 确认"<<"输入r/R表示重新输入"<<endl;//这里好像有问题，我要是不输入 呢？
	cin>>c;
	if(c=='c'||'C'){
    cin>>name[i];
	//pstr[i]=name[i];
	}
	if(c=='r/R'){
		cout<<"请重新输入"<<endl;
	    cin>>name[i];
	}
	cout<<"是否继续输入？输入y/Y表示继续，输入n/N表示结束"<<endl;

	cin>>c;
	if(c=='y'||c=='Y')
		cout<<"继续输入"<<endl;
	cin>>name[i];


	i++;
}while(c!='n'||c!='N');

return 0;
}