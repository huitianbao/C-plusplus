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
	//int get(int index);//����λ�ã���ȡ����
	//int locate(int val);//�������ݣ���ȡλ��
	void insertFront(int val);//��ͷ������
	void insertEnd(int val);//��β������
	void insert(int index,int val);//����Ԫ��
	bool  remove(int index);//ɾ��ĳλ������Ԫ��
	int  removeFromEnd();//��ͷ��ɾ�� 
	void traverse();//����
};

	//���캯��
    LinkedList::LinkedList()
	{
		head=NULL;		
	}
	

	//��ͷ������
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
	//��β������
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
	int LinkedList::removeFromEnd()
	{
		if(head!=NULL)
		{
			Node*p=new Node;
			Node*q=new Node; 
			p=head;
			q=NULL;
			while(p->next!=NULL)//�ƶ�ָ��
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
			Node*tmp=p->next;
			p->next=tmp->next;
			tmp->next=NULL;
			return true;
		}
		return false;
	
	}
	//����
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
		int d;		
		return top.removeFromEnd();     //top.removeFromEnd();
	}
	void  Stack::push(int d)
	{
		//string d1;   //----------------------------------------------
		top.insertFront(d);
	}
	//������� 
/*	int main(){
		
		string a,b,c;
		int index=0;
		LinkedList L1,L2;
		cout<<"����������1���ݣ�";
		while(a!="end")
		{	
			cin>>a;
			L1.insertFront(a);//��ͷ�����룬��ʾ��˳���������˳���෴ 
			
		}
		L1.traverse();
		cout<<"����ĳ����ǣ�";
		cout<<L1.length()<<endl;
		cout<<"����������2���ݣ�";
		while(b!="end")
		{	
			cin>>b;
			L2.insertEnd(b);//��ͷ�����룬��ʾ��˳���������˳���෴ 
			
		}	
		L2.traverse();
		cout<<"��������Ҫ����Ԫ�ص�λ��:";	
		cin>>index;
		if(index>L2.length()||index<1)
		cout<<"����λ�ô���"<<endl;
		else
		cout<<L2.get(index)<<endl;
		cout<<"��������Ҫ����Ԫ�ص�ֵ������Ԫ��λ�ã�";
		cin>>c;
		cout<<"data="<<L2.locate(c)<<endl;
		cout<<"��������Ҫɾ����Ԫ�ص�λ�ã�";
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
		cout<<"��������ջ�����ݣ�";
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

	

	
	
	
	
	
	
	
	

