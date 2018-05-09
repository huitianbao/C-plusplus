#include <iostream>
#include <string>
using namespace std;


struct Node
{
	int data;
	Node *next;
};



class LinkedList
{
private:
	Node *head;//头结点
public:
	LinkedList();//构造函数
	~LinkedList(){}//析构函数
	//int get(int index);//根据位置，获取数据
	//int locate(int val);//根据数据，获取位置
	void insertFront(int val);//从头部插入
	void insertEnd(int val);//从尾部插入
	void insert(int index,int val);//插入元素
	bool  remove(int index);//删除某位置链表元素
	int  removeFromEnd();//从头部删除 
	void traverse();//遍历
};

	//构造函数
    LinkedList::LinkedList()
	{
		head=NULL;		
	}
	

	//从头部插入
	void LinkedList::insertFront(int val)
	{	
		Node *p=new Node;
		p->data=val;
		if(val<0){
		
		if(head==NULL)
		{
			head=p;
			head->next=NULL;
		} 
		else
		{
			p->next=head;
			head=p;
		}
	}	
	}
	//从尾部插入
	void LinkedList::insertEnd(int val)
	{	
		Node *p=new Node;
		p->data=val;
		if(head==NULL)
		{
			head=p;
			head->next=NULL;
		}
		else
		{
			Node *q=head;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=p;
			p->next=NULL;
			
		
		}
	
	}
	//在其他位置插入
	void LinkedList::insert(int index,int val)
	{
		
		if(index==1)
		{
			Node *p=new Node;
			p->next=head;
			head=p;
			p->data=val;
			
		}
		
		else 
		{	Node*p=new Node;
			int count=0;
			while(p!=NULL)
			{
				count++;
				if(count==index-1)
					break;
				p=p->next;
			}
			Node*q=new Node;
			q->next=p->next;
			p->next=q;
			q->data=val;


		}
	
	}
	//从尾部删除 
	int LinkedList::removeFromEnd()
	{
		if(head!=NULL)
		{
			Node*p=new Node;
			Node*q=new Node; 
			p=head;
			q=NULL;
			while(p->next!=NULL)//移动指针
			{
				q=p;
				p=p->next;
			} 
			if(q!=NULL)
				q->next=NULL;

			int value=p->data;
			delete p;
			return value;
			 
		} 
		else
		cout<<"栈为空";
		exit(0); 
	
	} 
	//删除某位置链表元素
	bool LinkedList:: remove(int index)
	{
		if(index==1)
		{
			Node *p=new Node;
			p=head;
			head=p->next;
		}
		else
		{
			Node *p=head;
			
			int count=0;
			while(p!=NULL)//找到位置
			{
				count++;
				if(count==index-1)
					break;
				p=p->next;
			}
			Node*tmp=p->next;
			p->next=tmp->next;
			tmp->next=NULL;
			return true;
		}
		return false;
	
	}
	//遍历
	void LinkedList:: traverse()
	{
		Node *p=new Node;
		p=head;
		while(p->next!=NULL)
		{
			
			cout<<p->data<<"->";
			p=p->next;
			
		}
		cout<<p->data;	
		cout<<"->NULL"<<endl;
		return;
	}
	//栈类 
	class Stack
	{
		private:
			LinkedList top;
		public:
			
			int pop();
			void push(int d);
			
			
		
	} ;
	//栈的实现
	int Stack::pop()
	{
		int d;		
		return top.removeFromEnd();     //top.removeFromEnd();
	}
	void  Stack::push(int d)
	{
		//string d1;   //----------------------------------------------
		top.insertFront(d);
	}
	//链表调用 
/*	int main(){
		
		string a,b,c;
		int index=0;
		LinkedList L1,L2;
		cout<<"请输入链表1数据：";
		while(a!="end")
		{	
			cin>>a;
			L1.insertFront(a);//从头部插入，显示的顺序与输入的顺序相反 
			
		}
		L1.traverse();
		cout<<"链表的长度是：";
		cout<<L1.length()<<endl;
		cout<<"请输入链表2数据：";
		while(b!="end")
		{	
			cin>>b;
			L2.insertEnd(b);//从头部插入，显示的顺序与输入的顺序相反 
			
		}	
		L2.traverse();
		cout<<"请输入你要查找元素的位置:";	
		cin>>index;
		if(index>L2.length()||index<1)
		cout<<"输入位置错误"<<endl;
		else
		cout<<L2.get(index)<<endl;
		cout<<"请输入你要查找元素的值，返回元素位置：";
		cin>>c;
		cout<<"data="<<L2.locate(c)<<endl;
		cout<<"请输入你要删除的元素的位置：";
		cin>>index;
		a=L2.remove(index);
	
			L2.traverse();
	
		return 0;
		
		
		
		
	}*/
	

	
	int main()
	{
		Stack s1;
		int a;
		int count=0;
		cout<<"请输入入栈的数据：";
		while(a>0)
		{
			cin>>a;
			s1.push(a);		
			count++;
		}
		for(int i=0;i<count;i++)
		{	
			
				cout<<s1.pop();
				if(i==count-2){
					break;
				}
				cout<<"<-";
		}
		
		
		
		return 0;
	}

	

	
	
	
	
	
	
	
	

