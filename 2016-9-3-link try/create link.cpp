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
int main()//����
{
	cout<<"the city and the price of it"<<endl;
    
    cout<<"1 �Ͼ�--100"<<endl<<"2 �Ϻ�--200"<<endl<<"3 ����--300"<<endl<<"4 ���--400"<<endl<<"5 �人--500"<<endl<<"6 ����--600"<<endl;

	cout<<"��ѡ����Ҫ���εĳ�����ȷ��·��,��������һ���ص����ֱ�ż���"<<endl;


	*/

int main()
{

	cout<<"����Ŀ¼�ͼ۸�"<<endl;
    
    cout<<"1 �Ͼ�--100"<<endl<<"2 �Ϻ�--200"<<endl<<"3 ����--300"<<endl<<"4 ���--400"<<endl<<"5 �人--500"<<endl<<"6 ����--600"<<endl;

	cout<<"��ѡ����Ҫ���εĳ�����ȷ��·��,��������һ���ص����ֱ�ż���"<<endl;




	int i=0;
	//string c;
	int price;char c;

	struct link *head=NULL;
	cout<<"Ҫ���ӳ����𣿣�y or n��"<<endl;
	cin>>c;
	while(c=='y')
	{
		head=AppendNode(head);
		DisplayNode(head);
		cout<<"Ҫ���ӳ����𣿣�y or n��"<<endl;
		cin>>c;
		i++;
	}

	cout<<i<<"�������Ѿ���ѡ��"<<endl;
	DeleteMemory(head);
}

struct link *AppendNode(struct link *head)

{
	struct link *p=NULL,*pr=head;
	int price;
	p=(struct link *)malloc(sizeof(struct link));

	if(p==NULL)
	{
		cout<<"�����ڴ�ʧ��"<<endl;
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


    

