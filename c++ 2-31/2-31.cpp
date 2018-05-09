#include<iostream>
using namespace std;

int main(){
	struct Time{
		int year;
		int month;
		int day;

		int hour;
		int min;
		int second;
	};

	cout<<"请输入 年，月，日，小时，分钟，秒：";
	int y,mo,d,h,mi,s;
	cin>>y>>mo>>d>>h>>mi>>s;

	Time t;

	t.year=y;  t.month=mo;  t.day=d;
	t.hour=h;  t.min=mi;    t.second=s;

	cout<<t.year<<"年  "<<t.month<<"月   "<<t.day<<"日   "<<t.hour<<"时   "<<t.min<<"分    "<<t.second<<"秒   "<<endl;






	return 0;
}