#include<iostream>
#include<iomanip>

using namespace std;

	double getArea(int r){
		double s=3.1415926*r*r;
		return s;
	}

int main(){
	cout<<"please input radius (����)"<<endl;
	int r;
	cin>>r;

	cout<<"���"<<getArea(r)<<endl;
	cout<<"���"<<setprecision(20)<<getArea(r)<<endl;
	
	return 0;
}