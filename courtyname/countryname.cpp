#include<iostream>
using namespace std;

/*
������
     ���������������ң�
	 �����롿America
	 �������ȷ������ America? ����c/C ȷ��,����r/R��ʾ��������
	 �����롿 c
	 ��������Ƿ�������룿����y/Y��ʾ����������n/N��ʾ����
	 �����롿y
	 �������������������
	 �����롿England
	 �������ȷ������ England? ����c/C ȷ�ϣ�����r/R��ʾ��������
	 �����롿 c
	 ��������Ƿ�������룿����y/Y��ʾ����������n/N��ʾ����
	 ..........(����������  Australia  ,Sweden ,Finland ,N)

	 ���������ʼ˳��
	          America         
	          England
		      Australia
		      Sweden
		      Finland

			  ����֮��
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

cout<<"���������:"<<endl;

char c='c';
do{
	int i=0;
	
	cout<<"ȷ������"<<name[i]<<"?"<<"����c /C ȷ��"<<"����r/R��ʾ��������"<<endl;//������������⣬��Ҫ�ǲ����� �أ�
	cin>>c;
	if(c=='c'||'C'){
    cin>>name[i];
	//pstr[i]=name[i];
	}
	if(c=='r/R'){
		cout<<"����������"<<endl;
	    cin>>name[i];
	}
	cout<<"�Ƿ�������룿����y/Y��ʾ����������n/N��ʾ����"<<endl;

	cin>>c;
	if(c=='y'||c=='Y')
		cout<<"��������"<<endl;
	cin>>name[i];


	i++;
}while(c!='n'||c!='N');

return 0;
}