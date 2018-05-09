#include<iostream>
using namespace std;

double cf(double f){
	return (5.0/9.0)*(f-32);
}

int main(){
	double c;
	double f;
	cout<<"请输入华氏温度：";
	cin>>f;

	c=cf(f);

	cout<<"输入的华氏温度为"<<f<<",转换成摄氏温度为"<<c<<endl;


	return 0;
}