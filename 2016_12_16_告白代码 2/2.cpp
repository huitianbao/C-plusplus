#include<windows.h>
#include<string.h>

#include<stdio.h>

#include<time.h>

#include<conio.h>
void gotoxy(int x,int y)

{COORD c;

c.X=x;

c.Y=y;SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),c);

}

void Deng(int s)

{

	int a,b;

	a=clock();

	while(clock()-a<s);}void SetColor(unsigned short ForeColor,unsigned short BackGroundColor) {HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hCon,(ForeColor%16)|(BackGroundColor%16*16));

	}

	void LOVE(char A[],int a,int c)

	{ int i=0;

	gotoxy(0,0);

	while(A[i]!='\0')

	{ if(A[i]!=' '&&A[i]!='\n')

	SetColor(a-1,0),printf("%c",a);

	else

		printf("%c",A[i]);

	i++;

	}

	Deng(c);
	}

	int main()

	{

		char A[365]={" ****** ******\n ********** **********\n ************* *************\n *****************************\n *****************************\n *****************************\n ***************************\n ***********************\n *******************\n ***************\n ***********\n *******\n ***\n *\n\0"}; int c; gotoxy(0,14);

loop:

		scanf("%d",&c);

		while(!kbhit())

		{ LOVE(A,rand()%94+33,c); }

		goto loop; }