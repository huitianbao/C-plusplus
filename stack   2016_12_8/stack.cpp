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
	Node *head;//ͷ���
public:
	LinkedList();//���캯��

	~LinkedList(){}//��������

	void insertFromHead(int val);//��ͷ������

	void insertFromTail(int val);//��β������

	void insert(int index,int val);//һ��Ĳ���Ԫ��

	bool  remove(int index);//ɾ��ĳλ������Ԫ��

	int  removeFromTail();//��ͷ��ɾ��

	void traverse();//����

	bool isNULL();
};

//���캯��
LinkedList::LinkedList()
{
	head=NULL;		
}


//��ͷ������
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
//��β������
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
//������λ�ò���
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
//��β��ɾ�� 
/*
int LinkedList::removeFromTail()//ֻ��һ��Ԫ�� ��ɾ������������
{
	    Node*p=new Node;
		Node*q=new Node; 
		p=head;
		q=NULL;

	if(head!=NULL)
	{

		while(p->next!=NULL)//�ƶ�ָ��
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
		cout<<"ջ��";
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
		cout<<"ջΪ��";
		exit(0); 
	
	} 


//ɾ��ĳλ������Ԫ��
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
		while(p!=NULL)//�ҵ�λ��
		{
			count++;
			if(count==index-1)
				break;
			p=p->next;
		}
		Node*tmp=p->next;//���� ������
		p->next=tmp->next;
		tmp->next=NULL;
		return true;
	}
	return false;

}

//����

void LinkedList:: traverse()                                                                                          
{
	for(Node*p=head;p!=NULL;p=p->next){
		cout<<p->data<<"->";
	}                                                                           // Node *p=new Node;
	                                                                              // p=head;
	                                                                               //while(p!=NULL){//����֮ǰ  p->next !=NULL,���˺�  line 185  ���ʳ�ͻ
		                                                                         //  cout<<p->data<<"->";
	                                                                              // p=p->next;
																	  

		                                                                  

	
	//cout<<p->data;	
	cout<<"NULL"<<endl;

}


bool LinkedList::isNULL(){
	return head==NULL;
}




int main(){//��ջ�Ĳ�����֤

	LinkedList l;
	for(int i=1;i<9;i++){

		l.insertFromTail(i);

	}
	l.traverse();
	for(int j=1;j<8;j++){//j ���ܴ��� 8������֮������д��󣬿϶���removeFromtail

		l.removeFromTail();
		cout<<"Call for l.removeFromTail()"<<"  "<<j<<"�κ�"<<endl;
		if(!l.isNULL()){
			l.traverse();
		}


		cout<<endl;
	}

	//l.remove(8);




return 0;
}




//����
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
//ջ�� 
class Stack
{
private:
	LinkedList top;
public:

	int pop();
	void push(int d);



} ;
//ջ��ʵ��
int Stack::pop()
{		
	return top.removeFromTail();     
}
void  Stack::push(int d)
{

	top.insertFromTail(d);
}




int main()//��stack ������֤
{
	Stack s;
	int a;
	int count=0;
	cout<<"��������ջ������(��С��0������β)��";
	
	do{
		cin>>a;
		s.push(a);
		count++;
	}while(a>0);//����

	
	for(int i=0;i<count;i++)
	{	

		cout<<s.pop()<<"  ";
	
	}



	return 0;
}

*/


