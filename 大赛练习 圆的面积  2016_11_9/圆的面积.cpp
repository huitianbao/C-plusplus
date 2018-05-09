#include<iostream>
#include<iomanip>

using namespace std;

	double getArea(int r){
		double s=3.1415926*r*r;
		return s;
	}

int main(){
	cout<<"please input radius (屁方)"<<endl;
	int r;
	cin>>r;

	cout<<"中持"<<getArea(r)<<endl;
	cout<<"中持"<<setprecision(20)<<getArea(r)<<endl;
	
	return 0;
}