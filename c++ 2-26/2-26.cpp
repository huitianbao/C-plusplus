#include<iostream>
using namespace std;

int main(){
	char ch;//  ��һ��bug  ���� cccccc   ���� while(getchar()!='\n');����������ͺ���
	do{
		
		cout<<"����������:��������Y/N�� ";
		cin>>ch;
		 while(getchar()!='\n');
		if(ch=='N'){
			cout<<"����û������"<<endl;
			break;
		}
		else if(ch=='Y'){
			cout<<"������������"<<endl;
			break;
		}
		

	}while((ch!='N')||(ch!='Y'));
	return 0;

}