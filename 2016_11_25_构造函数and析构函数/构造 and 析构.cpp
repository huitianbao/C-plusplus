#include<iostream>
using namespace std;

class Engine{
public: Engine(){
			cout<<"Engine 无参构造函数"<<endl;
		}
		~Engine(){
			cout<<"Engine 析构函数"<<endl;
		}

};

class Wheel{
public: Wheel(){
			cout<<"Wheel 无参构造函数"<<endl;
		}
		 Wheel(int nw){
			cout<<"Wheel 有参构造函数"<<endl;
			w=nw;
		}
		~Wheel(){
			cout<<"Wheel 析构函数"<<endl;
		}
private:
	int w;

};

class Door{
public :
	Door(){
		cout<<"Door 无参构造函数"<<endl;
	}

	~Door(){
		cout<<"Door 析构函数"<<endl;
	}
};


class Window{
public:
	Window(){
		cout<<"Window 无参构造函数"<<endl;
	}

	~Window(){
		cout<<"Window 析构函数"<<endl;
	}
};

class Car{

public :
	Engine engine;
	Wheel wheel;
	Door door;
	Car(){
		cout<<"Car 无参构造函数"<<endl;

	}
	Car(int ps):wheel(ps){
		cout<<"Car 有参构造函数"<<endl;
	}


	~Car(){
		cout<<"Car 析构函数"<<endl;

	}
};



int main(){
	Car car1;

	Car car2(4);

	return 0;
}

