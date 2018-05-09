#include<iostream>
using namespace std;

if not define{


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