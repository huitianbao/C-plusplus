#include<iostream>
using namespace std;

void isZhiShu(int a){
	if(a<=1){
		cout<<a<<"��������"<<endl;
	}

	else{

	int i;
	for(i=2;i<=a;i++){
		if(a%i==0)
			break;
	}
	if(i==a){
		cout<<a<<" ������"<<endl;
	}
	else{
		cout<<a<<"  ��������"<<endl;
	}
	}

}



int main(){
	cout<<"������һ��������:";
	int a;
	cin>>a;

	isZhiShu(a);
	//����


	for(int i=1;i<101;i++){
		isZhiShu(i);
	}

	return 0;
}

