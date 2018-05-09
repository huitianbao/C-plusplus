#include<iostream>
using namespace std;
int main(){


int a[8];
for(int i=7;i>=0;i--){
	a[i]=i;
}

cout<<"before sort"<<endl;
for(int i=0;i<8;i++){
	cout<<a[i]<<endl;
}

cout<<"after sort"<<endl;

for(int i=0;i<7;i++){
	if(a[i]>a[i+1]){
		int t=0;
		a[i]=t;
		t=a[i+1];
		a[i+1]=a[i];
	}
}

for(int i=0;i<8;i++){
	cout<<a[i]<<endl;
}



	cout<<"zzzzzzzzzzzzzzzzzzzzzz"<<endl;
return 0;
}

