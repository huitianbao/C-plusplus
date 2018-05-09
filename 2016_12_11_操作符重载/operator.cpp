#include<iostream>
using namespace std;

class Complex{

public:
	Complex(int newReal,int newIm){
		real=newReal;
		im=newIm;
	}

	Complex(){
		real=0;
		im=0;
	}

	int getReal(){
		return real;
	}

	int getIm(){
		return im;
	}



	Complex operator +(const Complex &c1){

		return Complex(c1.real+real,c1.im+im);
	}

	Complex operator -(const Complex &c2){
		return Complex(c2.real-real,c2.im-im);
	}

	Complex operator *(const Complex &c3){
		return  Complex(real*c3.real-im*c3.im,real*c3.im+c3.real*im);
	}

	private: int real,im;

};



int main(){
	Complex c1(1,3);
	Complex c2(1,2);
	Complex c3;
	c3=c2.operator+(c1);

	cout<<"c1="<<c1.getReal()<<"+"<<c1.getIm()<<"i"<<endl;
	cout<<"c2="<<c2.getReal()<<"+"<<c2.getIm()<<"i"<<endl;
	cout<<"c3="<<c3.getReal()<<"+"<<c3.getIm()<<"i"<<endl;

	int c1r,c1m,c2r,c2m;

	cout<<"������ c1��ʵ�����鲿:";
	cin>>c1r>>c1m;
	cout<<"������ c2��ʵ�����鲿:";
	cin>>c2r>>c2m;

	Complex c4(c1r,c1m);
	Complex c5(c2r,c2m);
	Complex c6=c4.operator-(c5);


	cout<<"c4="<<c4.getReal()<<"+"<<c4.getIm()<<"i"<<endl;
	cout<<"c5="<<c5.getReal()<<"+"<<c5.getIm()<<"i"<<endl;
	cout<<"c6="<<c6.getReal()<<"+"<<c6.getIm()<<"i"<<endl;


	cout<<"������ c7��ʵ�����鲿:";
	cin>>c1r>>c1m;
	cout<<"������ c8��ʵ�����鲿:";
	cin>>c2r>>c2m;

	Complex c7(c1r,c1m);
	Complex c8(c2r,c2m);
	Complex c9=c7.operator*(c8);


	cout<<"c7="<<c4.getReal()<<"+"<<c4.getIm()<<"i"<<endl;
	cout<<"c8="<<c5.getReal()<<"+"<<c5.getIm()<<"i"<<endl;
	cout<<"c9="<<c6.getReal()<<"+"<<c6.getIm()<<"i"<<endl;


	return 0;
}