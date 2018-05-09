#include<iostream>
using namespace std;

int main(){
	unsigned int x;
	unsigned int y=100;
	unsigned int z=50;

	x=y-z;
	cout<<"Different is:"<<x<<endl;

	x=z-y;

	cout<<"\nNow different is:"<<x<<endl;   //没有负数

	return 0;
}