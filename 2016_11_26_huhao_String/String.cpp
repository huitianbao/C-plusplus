#include<iostream>
#include<string>
using namespace std;


class String{
public :
	String(const char* s){//��ͨ���캯��
		str =new char[strlen(s)+1];//  �����ڴ�
		strcpy(str,s);
		cout<<"String ��ͨ���캯�� "<<endl;
	
	}


	String(){//Ĭ�Ϲ��캯��
		str=NULL;
		cout<<"String Ĭ�Ϲ��캯��"<<endl;
	}

	String(const String &s){//���ƹ��캯��
		str=new char[strlen(s.str)+1];
		strcpy(str,s.str);
		cout<<"String ���ƹ��캯��"<<endl;
	}



private:
	char* str;
};


int main(){

	String s;
	String s1=String("china");
	String s2=String(s1);




	return 0;
}
