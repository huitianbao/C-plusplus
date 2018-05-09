#include<iostream>
#include<math.h>

using namespace std;

int main(){
	cout<<"ÊäÈë:";
	long a;
	cin>>a;
	//cout<<pow(2.0,3);      //2.0   de 3===8

	/*
	for(int i=0;pow(i,2.0)<10;i++){
	cout<<i<<endl;
	}
	*/

	//do{

	double k,j;
	for(j=a;a>0;a=a-pow(k-1,2.0)){


		for(k=0;pow(k,2.0)<a;k++){
		}
		cout<<"k==========="<<k-1<<endl;

		//a=a-pow(k-1,2.0);
		cout<<"a=a-pow(k-1,2.0);   "<<a<<endl;

	}

	//}while(a>0);


	/*
	do{

	int i=0;
	for(i=0;pow(i,2.0)<a;i++){
	}
	cout<<"i====="<<i-1<<endl;

	a=a-pow(i-1,2.0);
	}while(a>0);


	*/


	return 0;
}