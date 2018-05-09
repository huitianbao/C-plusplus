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
	Node *head;//ͷ
public:
	LinkedList();//����

	~LinkedList(){}//����

	void insertFromHead(int val);//��ͷ������

	void insertFromTail(int val);//��β������

	void insert(int index,int val);//ָ��λ�ò���Ԫ��

	bool  deletee(int index);//ɾ��ĳλ������Ԫ��

	int  deleteFromTail();//��ͷ��ɾ��

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
//ָ��λ�ò���
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
int LinkedList::deleteFromTail()//ֻ��һ��Ԫ�� ��ɾ������������
{
	    Node*p=new Node;
		Node*q=new Node; 
		p=head;
		q=NULL;

	
		if(p->next!=NULL){
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


		cout<<" Call for deleteFromTail()  ջ��"<<endl;
		head=NULL;// ִ�е����˵��ջ�Ѿ���//                        2016_12_23_==============���������д���ͺ��ˣ���Ϊִ�е������˵��ջ�Ѿ���
		return value;
	}
}
	


//ɾ��ĳλ������Ԫ��
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

/*//traverse
// Node *p=new Node;
 // p=head;
 //while(p!=NULL){//����֮ǰ  p->next !=NULL,���˺�  line 185  ���ʳ�ͻ
 //  cout<<p->data<<"->";
 // p=p->next;
*/

void LinkedList:: traverse()                                                                                          
{
	Node* p=head;
	if(p!=NULL){//=================   ������ p
		for(Node*p=head;p!=NULL;p=p->next){//      p  ������p->next//-----
		cout<<p->data<<"->";//------------------------------------------------Ϊʲôɾ���˻�ִ�У�����
	}
	//cout<<p->data;	
	cout<<"NULL"<<endl;

}
	else{
		cout<<"ջ�գ�����Call for traverse()"<<endl;            //------------------------------------
	}

}


bool LinkedList::isNULL(){//===============================================================
	return head==NULL;
}


/*

int main(){//��ջ�Ĳ�����֤

	LinkedList l;
	int a;

	l.traverse();//----------------------------------------------------------


	for(int i=1;i<10;i++){

		l.insertFromTail(i);

	}

	cout<<"ջ�г�ʼԪ��Ϊ��";
	l.traverse();
	cout<<endl;
	
	for(int j=1;j<=9;j++){//j ���ܴ��� 8������֮������д��󣬿϶���deleteFromtail
			cout<<"Call for l.deleteFromTail()"<<"  "<<j<<"�κ�"<<endl;
		a=l.deleteFromTail();
		cout<<"ɾ������  "<<a<<endl;
	
		if(!l.isNULL()){//------------------------------------------ԭ����  ��!l.isNULL()��

		l.traverse();//   ��仰����û��ִ�У�����������/ 2016����12����23  ����ִ����
		cout<<"ջ�ǿ�"<<endl;
		
		}
		
		else{
			cout<<"stack is null"<<endl;
		}
		
	

		cout<<endl;
	}


return 0;
}


*/



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
	return top.deleteFromTail();     
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
	cout<<"��������ջ������(����������С��0����Ϊ��־λ,��־λ������)��";
	
	


	do{
		cin>>a;
		
	//	if(a!=atoi((char*)a)){   //������飬�����е����� 11��20
	//		cout<<"������������������:";
	//		//break;
	//	}
		

		s.push(a);
		count++;
	}while(a>0);//����

	int covs=s.pop();// ��pop ��־λ�������Ͳ�����ʾ��һ����
	for(int i=0;i<count-1;i++)
	{	

		cout<<s.pop()<<"  ";
	
	}



	return 0;
}


