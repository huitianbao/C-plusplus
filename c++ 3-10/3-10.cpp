#include<iostream>
using namespace std;

int findMin(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}



int gongYueShu(int a,int b){
	int min;
	//找到a,b 中最小的数min
	min=findMin(a,b);

	//以C为范围，找到最大的公约数

	int y;
	for(int i=1;i<=min;i++){
		if(a%i==0&&b%i==0){
			y=i;
		}
	}

	return y;


}




int findMax(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

int gongBeiShu(int a,int b){//                为什么出错？？？？？？2017—1-6
	int ma;
	ma=findMax(a,b);
	int i;
	for(i=ma;i<=a*b;i++){               // for(int i=ma;i<=a*b;i++){     这句有问题 看i
		if((i%a==0)&&(i%b==0))
			break;
	}

	return i;

}







int main(){

	cout<<"gongYueShu(3,6);"<<endl;
	cout<<gongYueShu(3,6)<<endl;

	cout<<"gongBeiShu(3,6)"<<endl;
	cout<<gongBeiShu(3,6)<<endl;


	cout<<"gongYueShu(4,5);"<<endl;
	cout<<gongYueShu(4,5)<<endl;

	cout<<"gongBeiShu(4,5)"<<endl;
	cout<<gongBeiShu(4,5)<<endl;


	return 0;
}