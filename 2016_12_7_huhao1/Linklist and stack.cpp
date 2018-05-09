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
	Node *head;//ͷ���
public:
	LinkedList();//���캯��
	~LinkedList(){}//��������
	Node *clear();
	bool isEmpty();//�ж��Ƿ�Ϊ��
	int length();//������
	string get(int index);//����λ�ã���ȡ����
	int locate(string d);//�������ݣ���ȡλ��
	void insertFront(string d);//��ͷ������
	void insertEnd(string d);//��β������
	void insert(int index,string d);//����Ԫ��
	bool  remove(int index);//ɾ��ĳλ������Ԫ��
	string  removeFromEnd();//��ͷ��ɾ�� 
	void traverse();//����
};

	//���캯��
    LinkedList::LinkedList()
	{
		head=NULL;		
	}
	//�ж��Ƿ�Ϊ��
 	bool LinkedList::isEmpty()
	 {
	 	return head==NULL;
	 }
	////�������
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
	
	//������
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
	//����λ�ã���ȡ����
	string LinkedList::get(int index)
	{
		if(index<1||index>length()+1)
			cout<<"�����������"<<endl;
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
	//�������ݣ���ȡλ��
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
	//��ͷ������
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
	//��β������
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
	//������λ�ò���
	void LinkedList::insert(int index,string d)
	{	
		
	
		if(index<1||index==length()+1)
		{cout<<"�������";}
		
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
	//��β��ɾ�� 
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
		cout<<"ջΪ��";
		exit(0); 
	
	} 
	//ɾ��ĳλ������Ԫ��
	bool LinkedList:: remove(int index)
	{
		if(head==NULL)
		{cout<<"��������";	exit(0); }
		if(index<1||index>length()+1)
		{cout<<"�������";	exit(0); }
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
			
			string pop();
			void push(string d);
			
			
		
	} ;
	//ջ��ʵ��
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
		string a;
		int count=0;
		cout<<"��������ջ�����ݣ�";
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

	
	
	
	
	
	
	
	

