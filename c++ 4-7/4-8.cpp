#include<iostream>
using namespace std;


class Dog{
public:
	void setInfor(int newAge,double newWeight);
	void show();

	Dog();
	Dog(int a,double w);
	~Dog();



private:
	int age;
	double weight;



};


void Dog::setInfor(int newAge,double newWeight){
	this->age=newAge;
	this->weight=newWeight;
}

void Dog::show(){
	cout<<"ÄêÁä"<<this->age<<"weight"<<this->weight<<endl;
}


Dog::Dog(){
	cout<<"call for Dog()"<<endl;

	age=3;
	weight=10.5;
}

Dog::Dog(int a,double w){
	cout<<"call for Dog(int a,double w)"<<endl;

	age=a;
	weight=w;
}

Dog::~Dog(){
	cout<<"call for xi gou function"<<endl;
}

int main(){
	Dog dog1;
	Dog dog2(1,3.3);

	dog1.show();

	dog2.show();


	dog1.setInfor(10,10.10);
	dog1.show();

	dog2.setInfor(10,10.10);
	dog2.show();


	return 0;
}