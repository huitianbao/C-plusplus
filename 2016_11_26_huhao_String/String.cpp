#include<iostream>
#include<string>
using namespace std;


class String{
public :
	String(const char* s){//普通构造函数
		str =new char[strlen(s)+1];//  申请内存
		strcpy(str,s);
		cout<<"String 普通构造函数 "<<endl;
	
	}


	String(){//默认构造函数
		str=NULL;
		cout<<"String 默认构造函数"<<endl;
	}

	String(const String &s){//复制构造函数
		str=new char[strlen(s.str)+1];
		strcpy(str,s.str);
		cout<<"String 复制构造函数"<<endl;
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
