#include<iostream>
using namespace std;

class Bird{//����
public :
	Bird(){
		cout<<"Bird ���캯��"<<endl;
	}

	void fly_public(){
		cout<<" class Bird fly()"<<endl;
	}

protected://ֻ�����������
	void fly_prptected(){
		cout<<" class Bird fly()"<<endl;


	}
private:
	void fly_privated(){
		cout<<"fly-privated()"<<endl;
	}
};


class QiE :public Bird{
public :
	QiE(){
		cout<<"QiE ���캯��"<<endl;

	}

	//void walk(){
		//this->fly_prptected();
	//}

};
int main(){


	Bird b;

	QiE qie;

	qie.walk();
	
	qie.fly_prptected();


	//b.fly();

	return 0;
}


