#include<iostream>
using namespace std;

void isZhiShu(int a){
	if(a<=1){
		cout<<a<<"不是质数"<<endl;
	}

	else{

	int i;
	for(i=2;i<=a;i++){
		if(a%i==0)
			break;
	}
	if(i==a){
		cout<<a<<" 是质数"<<endl;
	}
	else{
		cout<<a<<"  不是质数"<<endl;
	}
	}

}



int main(){
	cout<<"请输入一个正整数:";
	int a;
	cin>>a;

	isZhiShu(a);
	//测试


	for(int i=1;i<101;i++){
		isZhiShu(i);
	}

	return 0;
}

