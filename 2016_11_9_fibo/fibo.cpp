#include<iostream>
using namespace std;
//int get_fn(int x);

int main(){
	// ¸öÊı  n


	int f1=1;
	int f2=1;
	int tmp;
	cout<<"please input n:"<<endl;


	int n;
	cin>>n;
	int result;

	int get_fn(int x){

		do{
			int f1=1;
			int f2=1;
			int tmp;

			f2=tmp;
			tmp=f1+f2;
			result=tmp;
			n++;
		}while(x<=n+1);

		return tmp;

	}


	if(n==1){
		cout<<"result="<<1%10007<<endl;
	}
	if(n==2){
		cout<<"result="<<1%10007<<endl;
	}

	if(n>2){
		result=get_fn(n);
		cout<<"result="<<result%10007<<endl;
	}



	return 0;

}


