#include<iostream>
#include<stdlib.h>
using namespace std;

  struct node  //   1                                                        单链表的创建过程有以下几步：  1 ) 定义链表的数据结构。 
//                                                                                                        2 ) 创建一个空表。 
//                                                                                                        3 ) 利用m a l l o c ( )函数向系统申请分配一个节点。 
//                                                               4 ) 将新节点的指针成员赋值为空。若是空表，将新节点连接到表头；若是非空表，将新 节点接到表尾。 
//                                                               5 ) 判断一下是否有后续节点要接入链表，若有转到3 )，否则结束。
  {
	  int date;
	  struct node *next;
  };


  //    2
  struct node *Create();
  void Display();

  struct node *head=NULL;    //定义头指针，并创建空表


  head=Create(head);
  Display(head);




