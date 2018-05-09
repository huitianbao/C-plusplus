#include<iostream>

using namespace std;
                                          //  ¿âº¯Êý     pow£¨£©
int getPower(int x,int y);
double getPower(double x,int y);

int main(){

	int a=getPower(2,3);
	cout<<"int a=getPower(2,3);     "<<a<<endl;
	double b=getPower(2.1,3);
	cout<<"double b=getPower(2.1,3);  "<<b<<endl;


	return 0;
}


int getPower(int x,int y){
	if(y<0){
	return 0;
	}

	else{
		int sum=1;
		for(int i=1;i<=y;i++){

			sum=sum*x;
		}

		return sum;
	}
}



double getPower(double x,int y){
	double s=1;

	for(int i=1;i<=y;i++){
		s=s*x;
	}

	return s;
}



		
