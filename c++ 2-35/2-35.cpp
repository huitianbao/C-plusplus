#include<iostream>
using namespace std;
int main(){

	for(int i=1;i<10;i++){
		for(int j=1;j<=i;j++){
			cout<<i<<"x"<<j<<"="<<i*j<<"    ";
		}
		cout<<endl;
	}

	cout<<endl<<endl;

	for(int i=9;i>=1;i--){
		for(int j=1;j<=i;j++){
			cout<<i<<"x"<<j<<"="<<i*j<<"    ";
		}
		cout<<endl;
	}

	return 0;
}