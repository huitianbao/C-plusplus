#include<iostream>
using namespace std;

struct Node{

	int element;
	Node* next;

};
class LinkList{
public:LinkList(Node *h);
	   LinkList();
public:~LinkList();


public:
	Node *getHead(){
		return h;
	}
	Node *insertFromHead(Node *h,int val);

	Node *insertFromTail(Node *h,int val);
	Node *insertBeforeKeyNode(Node *h,int val,int key);

	Node *insertAfterKeyNode(Node *h,int val,int key);

	Node *deleteFromHead(Node *h);

	Node *deleteFromTail(/*Node *h*/);//---------------------

	Node *deleteKeyNode(Node *h,int key);
	void output(Node *h);

	void remove(Node *h);

public: Node *h;

};

LinkList::LinkList(){

	this->h=NULL;
}
LinkList::LinkList(Node *h){
	this->h=NULL;
	//this->t=NULL;
	cout<<"�����๹�캯��������"<<endl;
}

LinkList::~LinkList(){
	cout<<"��������������������"<<endl;
}

Node* LinkList::insertFromHead(Node *h,int val){
	Node *p=new Node;
	p->element=val;

	if(h==NULL){
		h=p;
		p->next=NULL;
	}
	else{
		p->next=h;
		h=p;
	}
	return h;


}

Node* LinkList::insertFromTail(Node *h,int val){
	Node *p=new Node;
	p->element=val;

	if(h=NULL){//����Ϊ�գ�ͷ��ʱβ��
		h=p;
		p->next=NULL;
	}
	else{
		Node *q=h;

		//�ҵ�β��
		while(q->next!=NULL){
			q=q->next;
		}

		q->next=p;//����������������������������������������������
		p->next=NULL;

	}

	return h;


}

Node * LinkList::insertBeforeKeyNode(Node *h,int val,int key){

	Node* p=new Node;

	p->element=val;

	if(h!=NULL){//��λ��--------------------------
		Node* q=h;
		Node* q1=NULL;
		while(q!=NULL){
			if(q->element==key)
				break;

			else{
				q1=q;
				q=q->next;//q1  q
			}
		}

		//-----------------------------------------

		//һ�����

		if(q!=NULL&&q1!=NULL){
			p->next=q;
			q1->next=p;
		}

		//λ����ͷ��
		if(q!=NULL&&q1==NULL){
			p->next=q;
			h=p;
		}
		if(q==NULL&&q1!=NULL){//λ����β��
			p->next=NULL;
			p=q1->next;
		}

	}

	return h;

}

Node *LinkList::insertAfterKeyNode(Node *h,int val,int key){

	return NULL;

}

Node * LinkList::deleteFromHead(Node *h){
	if(h!=NULL){
		Node *p=h;
		h=h->next;
		delete p;
	}
	return h;


}

Node * LinkList::deleteFromTail(/*Node *h*/){//----------------------------------
	if(h!=NULL){

		Node* p=h;
		Node* q=NULL;
		//--------------------------------
		//��λ
		while(p->next!=NULL){// q p
			q=p;

			p=p->next;
		}

		//----------------------------------
		if(q!=NULL){
			q->next=NULL;
		}
		else{
			h=NULL;
			delete p;
		}

		return h;

	}
}

Node * LinkList::deleteKeyNode(Node *h,int key){
	if(h!=NULL){
		Node * p=h;
		Node *q=NULL;
		while(p!=NULL){
			if(p->element==key){
				break;
			}
			else
			{
				q=p;
				p=p->next;
			}
		}

		if(p!=NULL&&q!=NULL){
			q->next=p->next;
			delete p;
		}

		else if(p!=NULL&&q==NULL){
			h=p->next;
			delete p;
		}
	}

	return h;
}

void LinkList::output(Node *h){
	Node *p=h;
	for(p=h;p!=NULL;p=p->next){
		cout<<p->element<<"->";
	}

	cout<<p->element;
}

void LinkList::remove(Node *h){
	while(h!=NULL){
		Node *p=h;
		h=h->next;
		delete p;
	}
}

class Stack{
public:

	int pop();
	void push(int value);
	void traverse();

public:
	LinkList top;

};

int Stack::pop(){//��ջ
	int tmp=top.deleteFromTail();// error C2440: ����ʼ����: �޷��ӡ�Node *��ת��Ϊ��int��
	return tmp;//error C2248: ��LinkList::h��: �޷����� private ��Ա(�ڡ�LinkList����������)

}

void Stack::push(int value){
	top.insertFromTail(top.getHead(),value);
}

void Stack::traverse(){
	top.output(top.h);

}


int main(){
	Stack s;
	Node node;


	int a;
	do{
		cin>>a;
		s.push(a);
	}while(a>0);


	do{
		node=s.pop();
		cout<<node.element<<"  ";
	}while(node.element>0);


	return 0;

}



/*

int main(){
		Stack s;
		int a;
		int count=0;
		cout<<"��������ջ�����ݣ�";
		while(a<0)
		{
			cin>>a;
			s.push(a);		
			count++;
		}
		for(int i=0;i<count;i++)
		{	
			
				cout<<s.pop();
				if(i==count-2){
					break;
				}
				cout<<"<-";
		}
		
		
		
		return 0;
	}

	*/