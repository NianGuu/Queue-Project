#define TRUE 1
#define	FALSE 0
#define NAME_LENGTH 20
#define ERR_QUEUEEMPTY -1
#define SUCCESS 0
#define LINE_LENGTH 200


#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include"LinkList.h"
#include"Queue.h"

void HideCursor();
void UI_Ready();						//开始聊天UI

void UI_History();						//聊天记录UI

void UI_Set(LinkList*,int*);				//设置界面UI
void UI_Set_History(int*);			//设置聊天记录上限
void UI_Set_Talker(LinkList*);				//设置发言者

int main() {
	LinkList talker=InitList();			//初始化发言者列表
	int record = 10;					//初始化可保存聊天记录上限
	char choose;
	while (TRUE) {
		system("CLS");
		printf("\33[?25l1.开始聊天\n");
		printf("2.聊天记录\n");
		printf("3.设置\n");
		choose=_getch();
		switch (choose) {
		case '1':UI_Ready();
		case '2':UI_History();
		case '3':UI_Set(&talker,&record);
		default:continue;
		}
	}
}

//定义隐藏光标函数
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
/*开始聊天UI*/
void UI_Ready() {

}
/*聊天记录UI*/
void UI_History() {

}
/*设置界面UI*/
void UI_Set(LinkList* talker,int* record) {
	char choose;
	while (TRUE) {
		system("CLS");
		printf("1.设置保存聊天记录上限\n");
		printf("2.设置用户\n");
		printf("3.返回\n");
		choose = _getch();
		switch (choose) {
		case '1':UI_Set_History(record);
		case '2':UI_Set_Talker(talker);
		case '3':return;
		default: {
			printf("请输入正确的选项！\n");
			Sleep(200);
		};break;
		}
	}
}
void UI_Set_History(int* record) {
	system("CLS");
	printf("当前保存聊天记录上限：%d\n",*record);
	printf("你想要改成多少?");
	scanf_s("%d",record);
}
void UI_Set_Talker(LinkList* talker) {

}