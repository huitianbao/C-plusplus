#include<iostream>
#include<string> 
using namespace std;
class City{
public:
	City(string n){name=n;}
	City(){}
	string name;
	City* Cnext=NULL;
	static Add(City& route,string n);
	static Display(City& route);
};
int main(){
	City route;
	route.name="Peking";
	City::Add(route,"Nanjing");
	City::Add(route,"Shanghai");
	City::Add(route,"Tokyo");
	City::Display(route);
}
City::Add(City& route,string n){
	City*r=&route;
	while(r->Cnext!=NULL)r=r->Cnext;
	r->Cnext=new City(n);
}
City::Display(City& route){
	int num=1;City*r=&route;
	while(r!=NULL) {
		cout<<num<<"."<<r->name<<endl;
		r=r->Cnext;
		num++;
	}
}
