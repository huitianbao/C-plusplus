#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


struct link *AppendNode(struct link *head);
void DisplayNode(struct link *head);
void DeleteMemory(struct link *head);

struct link{

	//string city;
	int price;
	struct link *next;
};


/*
int main()//不行
{
	cout<<"the city and the price of it"<<endl;
    
    cout<<"1 南京--100"<<endl<<"2 上海--200"<<endl<<"3 北京--300"<<endl<<"4 天津--400"<<endl<<"5 武汉--500"<<endl<<"6 杭州--600"<<endl;

	cout<<"请选择您要旅游的城市以确定路线,请先输入一个地点数字标号即可"<<endl;


	*/

int main()
{

	cout<<"城市目录和价格"<<endl;
    
    cout<<"1 南京--100"<<endl<<"2 上海--200"<<endl<<"3 北京--300"<<endl<<"4 天津--400"<<endl<<"5 武汉--500"<<endl<<"6 杭州--600"<<endl;

	cout<<"请选择您要旅游的城市以确定路线,请先输入一个地点数字标号即可"<<endl;




	int i=0;
	//string c;
	int price;char c;

	struct link *head=NULL;
	cout<<"要增加城市吗？（y or n）"<<endl;
	cin>>c;
	while(c=='y')
	{
		head=AppendNode(head);
		DisplayNode(head);
		cout<<"要增加城市吗？（y or n）"<<endl;
		cin>>c;
		i++;
	}

	cout<<i<<"个城市已经被选择"<<endl;
	DeleteMemory(head);
}

struct link *AppendNode(struct link *head)

{
	struct link *p=NULL,*pr=head;
	int price;
	p=(struct link *)malloc(sizeof(struct link));

	if(p==NULL)
	{
		cout<<"分配内存失败"<<endl;
		exit(0);
	}

	if (head==NULL)
	{
		head=p;
	}
	else
	{
		while(pr->next!=NULL)
		{
			pr=pr->next;
		}
		pr->next=p;
	}

	cout<<"input price"<<endl;
	cin>>price;
	p->price=price;
	p->next=NULL;
	return head;
}
void DisplayNode(struct link *head)
{
	struct link *p=head;
	int j=1;
	while (p!=NULL)
	{
		cout<<"   "<<j<<"   "<<p->next<<endl;
		p=p->next;
		j++;
	}
}


void DeleteMemory(struct link *head)
{
	struct link *p=head,*pr=NULL;
	while(p!=NULL)
	{
		pr=p;
		p=p->next;
		free(pr);
	}
}


    

