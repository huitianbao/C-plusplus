#include<iostream>
using namespace std;

int main(){
	char ch;//  有一个bug  输入 cccccc   加了 while(getchar()!='\n');清除缓冲区就好了
	do{
		
		cout<<"现在下雨吗？:（请输入Y/N） ";
		cin>>ch;
		 while(getchar()!='\n');
		if(ch=='N'){
			cout<<"现在没有下雨"<<endl;
			break;
		}
		else if(ch=='Y'){
			cout<<"现在正在下雨"<<endl;
			break;
		}
		

	}while((ch!='N')||(ch!='Y'));
	return 0;

}