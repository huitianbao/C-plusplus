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

	cout<<"������ �꣬�£��գ�Сʱ�����ӣ��룺";
	int y,mo,d,h,mi,s;
	cin>>y>>mo>>d>>h>>mi>>s;

	Time t;

	t.year=y;  t.month=mo;  t.day=d;
	t.hour=h;  t.min=mi;    t.second=s;

	cout<<t.year<<"��  "<<t.month<<"��   "<<t.day<<"��   "<<t.hour<<"ʱ   "<<t.min<<"��    "<<t.second<<"��   "<<endl;






	return 0;
}