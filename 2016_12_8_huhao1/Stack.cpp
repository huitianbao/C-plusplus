#include<iostream>
using namespace std;

if not define{


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