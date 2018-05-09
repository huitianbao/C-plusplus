#include<iostream>
#include<stdio.h>
#include<time.h>
#define random(x)(rand()%x)

using namespace std;

int main(){
	srand((int)time(0));
	int i=random(100);
	cout<<"待猜的数是"<<i<<endl;

	/*
	for(int i=0;i<20;i++){
	cout<<random(100)<<endl;
	}
	*/
	int a;
	cin>>a;
	
		if(a>i){
			cout<<"大了,重新输入";
		}

		if(a<i){
			cout<<"小了重新输入";
		}
		if(a==i){
			cout<<"猜对了";
		}
	

	return 0;
}