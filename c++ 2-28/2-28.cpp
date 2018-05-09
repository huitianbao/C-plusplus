#include<iostream>
using namespace std;


//if else  
/*
int main(){
	cout<<"Menu:A(add) D(elete) S(ort) Q(uit),Select one:";

	char ch;
	cin>>ch;

	if(ch=='A'){
		cout<<"数据已增加"<<endl;
	}

	else if(ch=='D'){
		cout<<"数据已删除"<<endl;
	}

	else if(ch=='S'){
		cout<<"数据已排序"<<endl;
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
		cout<<"数据已增加"<<endl;
		break;
	case 'D':
		cout<<"数据已删除"<<endl;
		break;

	case 'S':
		cout<<"数据已排序"<<endl;
		break;
	case 'Q':
		exit(0);


	}
	return 0;
}
