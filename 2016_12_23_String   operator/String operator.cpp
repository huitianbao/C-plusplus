#include<iostream>
#include<string>
#include<iostream>


//  2016_12_23___Ê§°Ü 1

using namespace std;

class String{
public:
	String(char* s){
		str=new char[strlen(s)+1];
		strcpy(str,s);

	}

	String(){
		str=NULL;
	}

	String getString(){
		return str;
	}

String operator +(String s){
	str=new char[strlen(s.str)+1+strlen(this->str)];
	strcpy(str,s.str);

    strcat(this->str,s.str);
	return str;

}


String operator =(String s){
	str=new char[strlen(s.str+1)];
	strcpy(this->str,s.str);
	return str;
}



friend ostream& operator <<(ostream os,const String s);


private:
	 char* str;

};

ostream& operator <<(ostream &os,const String s){

	for(int i=0;i<strlen(s.getString());i++){
		cout<<s

	}
	return os;
}

int main(){
	String s1="aaaaaa";
	String s2="bbbbbbbbb";

	String s3;

	s3=s1+s2;

	cout<<"s1="<<s1<<endl<<"s2="<<s2<<endl<<"s3="<<s3<<endl;


	return 0;
}