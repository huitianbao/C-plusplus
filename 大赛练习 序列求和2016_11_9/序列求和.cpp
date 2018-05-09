#include<iostream>
using namespace std;

long long getResult(long long n){
	return (1+n)*n*0.5;

}
int main(){
	long long n;

	cout<<"please input n:"<<endl;
	cin>>n;
	long long result =getResult(n);
	cout<<"1+2+.....+"<<n<<"="<<result<<endl;
	



	return 0;
}