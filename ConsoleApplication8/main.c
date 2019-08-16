#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define U 1
#define D 2
#define L 3
#define R 4

typedef struct SNAKE
{
	int x;
	int y;
	struct SNAKE *next;
}snake;

//全局变量
int score = 0, add = 10;         //得分   每个食物的得分
int status, sleeptime = 200;     //每次运行的时间间隔
snake *head, *food;              //蛇头指针。食物指针
snake *q;                        //遍历蛇的时候用到的指针
int endGamestatus = 0;

void Pos(int x,int y)
{
	COORD pos;
	HANDLE houtput;

	pos.X = x;
	pos.Y = y;

	houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(houtput,pos);
}

void createmap()
{
	int i = 0;
	for (i = 0; i < 58; i+=2)  //打印上下边框
	{
		pos(i,0);
		printf("■");
		pos(i,26);
		printf("■");
	}
	for (i = 0; i < 26; i ++)  //打印左右边框
	{
		pos(0,i);
		printf("■");
		pos(56,i);
		printf("■");
	}
}

void initsnake()    //初始化蛇身
{
	snake *tail;
	int i;
	tail = (snake *)malloc(sizeof(snake));

	tail->x = 24;
	tail->y = 5;
	tail->next = NULL;

	for (i = 1; i <= 4; i++)
	{
		head = (snake *)malloc(sizeof(snake));
		head->next = tail;
		head->x = 24 + 2 * i;
		head->y = 5;
		tail = head;
	}
	while (tail != NULL)  //从头到尾输出蛇 的全身
	{
		pos(tail->x,tail->y);
		printf("■");
		tail = tail->next;
	}
}


