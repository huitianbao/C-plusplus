#include<iostream>
using namespace std;

double cf(double f){
	return (5.0/9.0)*(f-32);
}

int main(){
	double c;
	double f;
	cout<<"�����뻪���¶ȣ�";
	cin>>f;

	c=cf(f);

	cout<<"����Ļ����¶�Ϊ"<<f<<",ת���������¶�Ϊ"<<c<<endl;


	return 0;
}