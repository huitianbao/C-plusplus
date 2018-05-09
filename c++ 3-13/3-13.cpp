#include<iostream>
using namespace std;
int f(int a);


int main(){
	for(int i=1;i<10;i++){

	cout<<"f("<<i<<")="<<f(i)<<endl;
	}


	return 0;
}



	int f(int a){
	if(a==1){
		return 1;
	}

	if(a==2){
		return 1;
	}

	else{
		return f(a-1)+f(a-2);
	}
}
