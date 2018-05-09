#include<iostream>
using namespace std;

int main(){

	
	int j=2;
	cout<<"while====================================="<<endl;

	while(j<101){
		int i;
		for(i=2;i<=j;i++){
			if(j%i==0)
				break;
		}
		
		if(i==j){
			cout<<j<<"是质数"<<endl;
		}

		j++;
	}

	


	cout<<"do while=========================="<<endl;

	int k=2;

	do{
		int m;
		for(m=2;m<=k;m++){
			if(k%m==0)
				break;
		}

		if(k==m){
			cout<<k<<"是质数"<<endl;
		}
		k++;
	}while(k<101);



	cout<<"for================================="<<endl;
	
	int a,b;

	for(a=2;a<101;a++){
		for(b=2;b<=a;b++){
			if(a%b==0)
				break;
		}
		if(a==b){
			cout<<a<<"是质数"<<endl;
		}
	}



	return 0;
}