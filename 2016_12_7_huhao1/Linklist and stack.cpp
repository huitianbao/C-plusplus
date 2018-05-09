#include <iostream>
#include <string>
using namespace std;


struct Node
{
	string data;
	Node *next;
};



class LinkedList
{
private:
	Node *head;//头结点
public:
	LinkedList();//构造函数
	~LinkedList(){}//析构函数
	Node *clear();
	bool isEmpty();//判断是否为空
	int length();//链表长度
	string get(int index);//根据位置，获取数据
	int locate(string d);//根据数据，获取位置
	void insertFront(string d);//从头部插入
	void insertEnd(string d);//从尾部插入
	void insert(int index,string d);//插入元素
	bool  remove(int index);//删除某位置链表元素
	string  removeFromEnd();//从头部删除 
	void traverse();//遍历
};

	//构造函数
    LinkedList::LinkedList()
	{
		head=NULL;		
	}
	//判断是否为空
 	bool LinkedList::isEmpty()
	 {
	 	return head==NULL;
	 }
	////清除链表
  	Node*  LinkedList::clear()
	 {
		while(head!=NULL)
		{
			Node*p = head;
			head=head->next;
			delete p;
		}
		return head;
		
	 }	
	
	//链表长度
	int  LinkedList::length()
	{	
		Node*p=head;
		int size;
		while(p!=NULL)
		{			
			p=p->next;
			size++;
		}
		return size-1;
	
	}	
	//根据位置，获取数据
	string LinkedList::get(int index)
	{
		if(index<1||index>length()+1)
			cout<<"坐标输入错误"<<endl;
		Node*p=head;
		int count=0;
		while(p!=NULL)
		{
			count++;
			if(count==index)
			{
				return p->data;
			}
			p=p->next;
		}
		return 0;
	}
	//根据数据，获取位置
	int LinkedList::locate(string d)
	{
	
		Node *p=head;
		int count=0;
		while(p!=NULL)
		{
			count++;
			if(p->data==d)
				return count;
			p=p->next;
		}
		return -1; 
	
	}
	//从头部插入
	void LinkedList::insertFront(string d)
	{	
		Node *p=new Node;
		p->data=d;
		if(d!="end"){
		
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
	void LinkedList::insertEnd(string d)
	{	
		Node *p=new Node;
		p->data=d;
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
	void LinkedList::insert(int index,string d)
	{	
		
	
		if(index<1||index==length()+1)
		{cout<<"坐标错误";}
		
		if(index==1)
		{
			Node *p=new Node;
			p->next=head;
			head=p;
			p->data=d;
			
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
			q->data=d;


		}
	
	}
	//从尾部删除 
	string   LinkedList::removeFromEnd()
	{
		if(head!=NULL)
		{
			Node*p=new Node;
			Node*q=new Node; 
			p=head;
			q=NULL;
			while(p->next!=NULL)
			{
				q=p;
				p=p->next;
			} 
			if(q!=NULL)
				q->next=NULL;
			string d=p->data;
			delete p;
			return d;
			 
		} 
		else
		cout<<"栈为空";
		exit(0); 
	
	} 
	//删除某位置链表元素
	bool LinkedList:: remove(int index)
	{
		if(head==NULL)
		{cout<<"参数错误";	exit(0); }
		if(index<1||index>length()+1)
		{cout<<"坐标错误";	exit(0); }
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
			while(p!=NULL)
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
			
			string pop();
			void push(string d);
			
			
		
	} ;
	//栈的实现
	string Stack::pop()
	{
		string d;		
		return top.removeFromEnd();
	}
	void  Stack::push(string d)
	{
		string d1;
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
		string a;
		int count=0;
		cout<<"请输入入栈的数据：";
		while(a!="end")
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

	
	
	
	
	
	
	
	

