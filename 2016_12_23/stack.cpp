#include <iostream>

using namespace std;


struct Node
{
	int data;
	Node *next;
};



class LinkedList
{
private:
	Node *head;//头
public:
	LinkedList();//构造

	~LinkedList(){}//析构

	void insertFromHead(int val);//从头部插入

	void insertFromTail(int val);//从尾部插入

	void insert(int index,int val);//指定位置插入元素

	bool  deletee(int index);//删除某位置链表元素

	int  deleteFromTail();//从头部删除

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
//指定位置插入
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
int LinkedList::deleteFromTail()//只有一个元素 再删除，就有问题
{
	    Node*p=new Node;
		Node*q=new Node; 
		p=head;
		q=NULL;

	
		if(p->next!=NULL){
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


		cout<<" Call for deleteFromTail()  栈空"<<endl;
		head=NULL;// 执行到这里，说明栈已经空//                        2016_12_23_==============增加了这行代码就好了，因为执行到这里就说明栈已经空
		return value;
	}
}
	


//删除某位置链表元素
bool LinkedList:: deletee(int index)
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

/*//traverse
// Node *p=new Node;
 // p=head;
 //while(p!=NULL){//调试之前  p->next !=NULL,改了后  line 185  访问冲突
 //  cout<<p->data<<"->";
 // p=p->next;
*/

void LinkedList:: traverse()                                                                                          
{
	Node* p=head;
	if(p!=NULL){//=================   本来是 p
		for(Node*p=head;p!=NULL;p=p->next){//      p  换成了p->next//-----
		cout<<p->data<<"->";//------------------------------------------------为什么删完了还执行？？？
	}
	//cout<<p->data;	
	cout<<"NULL"<<endl;

}
	else{
		cout<<"栈空，不再Call for traverse()"<<endl;            //------------------------------------
	}

}


bool LinkedList::isNULL(){//===============================================================
	return head==NULL;
}


/*

int main(){//对栈的操作验证

	LinkedList l;
	int a;

	l.traverse();//----------------------------------------------------------


	for(int i=1;i<10;i++){

		l.insertFromTail(i);

	}

	cout<<"栈中初始元素为：";
	l.traverse();
	cout<<endl;
	
	for(int j=1;j<=9;j++){//j 不能大于 8，大于之后就运行错误，肯定是deleteFromtail
			cout<<"Call for l.deleteFromTail()"<<"  "<<j<<"次后"<<endl;
		a=l.deleteFromTail();
		cout<<"删除的是  "<<a<<endl;
	
		if(!l.isNULL()){//------------------------------------------原来是  （!l.isNULL()）

		l.traverse();//   这句话好像没有执行？？？？？？/ 2016——12——23  不，执行了
		cout<<"栈非空"<<endl;
		
		}
		
		else{
			cout<<"stack is null"<<endl;
		}
		
	

		cout<<endl;
	}


return 0;
}


*/



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
	return top.deleteFromTail();     
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
	cout<<"请输入入栈的数据(整数，且以小于0的数为标志位,标志位，不计)：";
	
	


	do{
		cin>>a;
		
	//	if(a!=atoi((char*)a)){   //参数检查，但是有点问题 11，20
	//		cout<<"输入有误，请重新输入:";
	//		//break;
	//	}
		

		s.push(a);
		count++;
	}while(a>0);//计数

	int covs=s.pop();// 先pop 标志位，这样就不会显示第一个了
	for(int i=0;i<count-1;i++)
	{	

		cout<<s.pop()<<"  ";
	
	}



	return 0;
}


