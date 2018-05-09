#include<iostream>
using namespace std;


//  failed  2016_12_16

int main(){


//   数组 类型
	int a[20];
	//for(int j=0;j<10;j++){              //产生随机数

		for(int i=0;i<20;i++){
			a[i]=rand()%20+1;
		}

		for(int k=0;k<20;k++){
			cout<<a[k]<<"  ";
		}
		cout<<endl<<endl;
	//}

		void swap(int a,int b){
			int tmp;
			tmp=a;
			a=b;
			b=tmp;
		}

		void sort(int a[],int num){

			while(num>1){
				int tmp;
				for(int i=0;i<a;i++){
					if(a[i]>a[i+1]){
						swap(a[i],a[i+1]);
					}
					num--;

				}

			}

		}

	return 0;
}

