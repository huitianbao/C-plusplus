#include<iostream>
using namespace std;


//if else  
/*
int main(){
	cout<<"Menu:A(add) D(elete) S(ort) Q(uit),Select one:";

	char ch;
	cin>>ch;

	if(ch=='A'){
		cout<<"����������"<<endl;
	}

	else if(ch=='D'){
		cout<<"������ɾ��"<<endl;
	}

	else if(ch=='S'){
		cout<<"����������"<<endl;
	}

	else if(ch=='Q'){
		exit(0);
	}


	return 0;
}

*/


int main(){

	cout<<"Menu:A(add) D(elete) S(ort) Q(uit),Select one:";

	char ch;
	cin>>ch;

	switch(ch){
	case 'A':
		cout<<"����������"<<endl;
		break;
	case 'D':
		cout<<"������ɾ��"<<endl;
		break;

	case 'S':
		cout<<"����������"<<endl;
		break;
	case 'Q':
		exit(0);


	}
	return 0;
}
