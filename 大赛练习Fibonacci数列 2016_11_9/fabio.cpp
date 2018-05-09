#include<iostream>
using namespace std;

int getFn(int n){
	int f1,f2,tmp;
	int fn;

		f1=1;
		f2=1;
		if(n==1){
			cout<<"F"<<n<<"  "<<"="<<f1;
			return f1;
		}
		
		else if(n==2){
			cout<<"F"<<n<<"  "<<"="<<f2;
			return f2;
			
		}

		
		else{
			int x=2;//----------------------------
			do{

				tmp=f1+f2;

				f1=f2;
				f2=tmp;

				x++;

			}while(x<n);
			cout<<"F"<<n<<"  ="<<tmp<<endl;
			return tmp;

		}

	}


int main(){

	int n;
	int fn;

	cout<<"please input n:"<<endl;
	cin>>n;
	fn=getFn(n);
	cout<<"Fn除以10007的余数是"<<fn%10007<<endl;




	return 0;
}