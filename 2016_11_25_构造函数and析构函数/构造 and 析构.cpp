#include<iostream>
using namespace std;

class Engine{
public: Engine(){
			cout<<"Engine �޲ι��캯��"<<endl;
		}
		~Engine(){
			cout<<"Engine ��������"<<endl;
		}

};

class Wheel{
public: Wheel(){
			cout<<"Wheel �޲ι��캯��"<<endl;
		}
		 Wheel(int nw){
			cout<<"Wheel �вι��캯��"<<endl;
			w=nw;
		}
		~Wheel(){
			cout<<"Wheel ��������"<<endl;
		}
private:
	int w;

};

class Door{
public :
	Door(){
		cout<<"Door �޲ι��캯��"<<endl;
	}

	~Door(){
		cout<<"Door ��������"<<endl;
	}
};


class Window{
public:
	Window(){
		cout<<"Window �޲ι��캯��"<<endl;
	}

	~Window(){
		cout<<"Window ��������"<<endl;
	}
};

class Car{

public :
	Engine engine;
	Wheel wheel;
	Door door;
	Car(){
		cout<<"Car �޲ι��캯��"<<endl;

	}
	Car(int ps):wheel(ps){
		cout<<"Car �вι��캯��"<<endl;
	}


	~Car(){
		cout<<"Car ��������"<<endl;

	}
};



int main(){
	Car car1;

	Car car2(4);

	return 0;
}

