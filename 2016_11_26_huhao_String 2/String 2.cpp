#include<iostream>
#include<string>
using namespace std;

class String{
public :
	String(){
		str=NULL;
		cout<<"Ĭ�Ϲ��캯��"<<endl;

	}

	String(const char *s){
		str=new char[strlen(s)+1];
		strcpy(str,s);
		cout<<"��һ�������Ĺ��캯��"<<endl;
	}

	String(const String &s){
		str=new char[strlen(s.str)+1];
		strcpy(str,s.str);
		cout<<"���ƹ��캯��"<<endl;
	}



private:
	char* str;

};

int main(){

	String s;
	String s1("CHINA");
	cout<<"String s1(\"CHINA\");";
	//cout<<s1;


	String s2=String(s1);
	//cout<<s2;




	return 0;
}