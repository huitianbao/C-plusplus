#include<iostream>
using namespace std;

int main(){
	cout<<"你考试考了多少分:";              //  如何测试？  2017_1_5
	int s;
	cin>>s;
	int a=s/10;

	for(int i=10;i<101;i=i+10){
		
		switch(i/10);
	}

	switch(a){
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		cout<<"差"<<endl;
		break;
	case 6:
	case 7:
		cout<<"中"<<endl;
		break;
	case 8:
		cout<<"良"<<endl;
		break;
	case 9:
	case 10:
		cout<<"优"<<endl;
		break;
	default:
		cout<<"请输入 1~100 之间的分数：";
	}



	cout<<"测试"<<endl;

	


	return 0;
}