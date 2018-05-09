#include<iostream>
#include<math.h>
using namespace std;

class Point{
public: double x,y;

public:
	Point(){
		x=5;
		y=3;
		cout<<"call for Point()"<<endl;};
		Point(double nx,double ny){
			x=nx;
			y=ny;
			cout<<"call for Point(double nx,double ny)"<<endl;
		}

		~Point(){cout<<"call for ~Point()"<<endl;}

		double getX(){return x;}
		double getY(){return y;}




};

class Rectangle{
private :Point p1;
		 Point p2;


public:
	//Rectangle(){
	     // p1;
		 // p2(2,2);
	//}


	Rectangle(Point newp1,Point newp2){
		/*
		p1.x=newp1.x;
		p1.y=newp1.y;

		p2.x=newp2.x;
		p2.y=newp2.y;
		*/
		//以上四行可以换成两行


		p1=newp1;//  是否会调用  拷贝构造函数
		p2=newp2;
	}


	~Rectangle(){cout<<"call for ~Rectangle()"<<endl;}

	double getArea(){
		double a=abs(this->p1.x-this->p2.x);
		double b=abs(this->p1.y-this->p2.y);


		return a*b;

	}




};

int main(){

	Point p1(1,1);
	Point p2(2,2);

	//Rectangle r1();
	Rectangle r2(p1,p2);

	 cout<<"r2 面积："<<r2.getArea()<<endl;
	// cout<<"r1 面积:"<<r1.


	return 0;
}