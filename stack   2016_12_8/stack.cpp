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

	void insertFromHead(int val);//从头部插入

	void insertFromTail(int val);//从尾部插入

	void insert(int index,int val);//一般的插入元素

	bool  remove(int index);//删除某位置链表元素

	int  removeFromTail();//从头部删除

	void traverse();//遍历

	bool isNULL();
};

//构造函数
LinkedList::LinkedList()
{
	head=NULL;		
}


//从头部插入
void LinkedList::insertFromHead(int val)
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
void LinkedList::insertFromTail(int val)
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
/*
int LinkedList::removeFromTail()//只有一个元素 再删除，就有问题
{
	    Node*p=new Node;
		Node*q=new Node; 
		p=head;
		q=NULL;

	if(head!=NULL)
	{

		while(p->next!=NULL)//移动指针
		{
			q=p;
			p=p->next;
		} 
		
		int value=p->data;
		delete p;
		if(q!=NULL){
			q->next=NULL;
		}

		return value;
		}

	
		else{
			int value=p->data;
		delete p;
		cout<<"栈空";
		return value;
	}

}
*/


int LinkedList::removeFromTail()
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
			int d=p->data;
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
		Node*tmp=p->next;//调试 有问题
		p->next=tmp->next;
		tmp->next=NULL;
		return true;
	}
	return false;

}

//遍历

void LinkedList:: traverse()                                                                                          
{
	for(Node*p=head;p!=NULL;p=p->next){
		cout<<p->data<<"->";
	}                                                                           // Node *p=new Node;
	                                                                              // p=head;
	                                                                               //while(p!=NULL){//调试之前  p->next !=NULL,改了后  line 185  访问冲突
		                                                                         //  cout<<p->data<<"->";
	                                                                              // p=p->next;
																	  

		                                                                  

	
	//cout<<p->data;	
	cout<<"NULL"<<endl;

}


bool LinkedList::isNULL(){
	return head==NULL;
}




int main(){//对栈的操作验证

	LinkedList l;
	for(int i=1;i<9;i++){

		l.insertFromTail(i);

	}
	l.traverse();
	for(int j=1;j<8;j++){//j 不能大于 8，大于之后就运行错误，肯定是removeFromtail

		l.removeFromTail();
		cout<<"Call for l.removeFromTail()"<<"  "<<j<<"次后"<<endl;
		if(!l.isNULL()){
			l.traverse();
		}


		cout<<endl;
	}

	//l.remove(8);




return 0;
}




//遍历
/*
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
*/

/*
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
	return top.removeFromTail();     
}
void  Stack::push(int d)
{

	top.insertFromTail(d);
}




int main()//对stack 操作验证
{
	Stack s;
	int a;
	int count=0;
	cout<<"请输入入栈的数据(以小于0的数结尾)：";
	
	do{
		cin>>a;
		s.push(a);
		count++;
	}while(a>0);//计数

	
	for(int i=0;i<count;i++)
	{	

		cout<<s.pop()<<"  ";
	
	}



	return 0;
}

*/


