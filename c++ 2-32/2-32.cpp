#include<iostream>
#include<stdio.h>
#include<time.h>
#define random(x)(rand()%x)

using namespace std;

int main(){
	srand((int)time(0));
	int i=random(100);
	cout<<"���µ�����"<<i<<endl;

	/*
	for(int i=0;i<20;i++){
	cout<<random(100)<<endl;
	}
	*/
	int a;
	cin>>a;
	
		if(a>i){
			cout<<"����,��������";
		}

		if(a<i){
			cout<<"С����������";
		}
		if(a==i){
			cout<<"�¶���";
		}
	

	return 0;
}