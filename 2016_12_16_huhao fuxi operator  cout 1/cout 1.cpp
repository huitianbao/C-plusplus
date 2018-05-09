#include<iostream>
using namespace std;
//      <<   operator succeed   2016_12_16
//      ++   operator failed    2016_12_16

/*
int main(){

	int m=5;

	cout<<"++m ="<<++m<<endl;

	cout<<"m++ ="<<m++<<endl;

	++m;
	cout<<"after ++m, m="<<m<<endl;

	++m=4;
	cout<<"++m=4"<<"   m="<<m<<endl;//  m=4

	//m++=4;  error


	return 0;

}


*/

class Compare{
private :
	int real,im;

public:
	Compare(int newreal,int newim){
		real=newreal;
		im=newim;
	}
	Compare(){
		real=0;im=0;
	}


	Compare operator =(Compare c){
		real=c.real;
		im=c.im;
	}

	friend ostream& operator <<(ostream& os,const Compare c);
	Compare& operator++(Compare c,int i);
	
};


ostream& operator <<(ostream& os,const Compare c){
	cout<<c.real<<"+"<<c.im<<"i";


	return os;
}


Compare::Compare& operator++(Compare c,int i){
	//c++
	c.real=c.real+1;
	return *this;
}




int main(){

	Compare c1(1,2);
	Compare c2(3,4);

	Compare c3;

	cout<<c1<<endl<<c2<<endl;



	c3=c1++;
	cout<<c1<<endl;

	return 0;
}


