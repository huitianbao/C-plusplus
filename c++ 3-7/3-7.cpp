#include<iostream>
using namespace std;
short int hanshu(unsigned short int a,unsigned short int b);

int main(){
	unsigned short int a1=5;
	unsigned short int b1=6;
	short int c1;


	unsigned short int a2=6;
	unsigned short int b2=0;
	short int c2;


	c1=hanshu(a1,b1);
	c2=hanshu(a2,b2);

	cout<<"unsigned short int a1=5"<<endl;
	cout<<"unsigned short int b1=6"<<endl;
	cout<<c1<<endl;

	cout<<endl<<endl;

	cout<<"unsigned short int a2=6"<<endl;
	cout<<"unsigned short int b2=0"<<endl;
	cout<<c2<<endl;
	return 0;
}


short int hanshu(unsigned short int a,unsigned short int b){
	if(b==0){
		return -1;
	}
	else{
		return a/b;
	}

}