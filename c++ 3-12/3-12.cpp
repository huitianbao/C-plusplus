#include<iostream>
using namespace std;

int f(int a){
	if(a==1){
		return 1;
	}
	else{
		return f(a-1)+a;
	}
}


int main(){
	cout<<"ÇëÊäÈë n";
	int n;
	cin>>n;

	int s=f(n);
	cout<<s;



	return 0;
}