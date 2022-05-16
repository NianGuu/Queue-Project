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
void UI_Ready();						//��ʼ����UI

void UI_History();						//�����¼UI

void UI_Set(LinkList*,int*);				//���ý���UI
void UI_Set_History(int*);			//���������¼����
void UI_Set_Talker(LinkList*);				//���÷�����

int main() {
	LinkList talker=InitList();			//��ʼ���������б�
	int record = 10;					//��ʼ���ɱ��������¼����
	char choose;
	while (TRUE) {
		system("CLS");
		printf("\33[?25l1.��ʼ����\n");
		printf("2.�����¼\n");
		printf("3.����\n");
		choose=_getch();
		switch (choose) {
		case '1':UI_Ready();
		case '2':UI_History();
		case '3':UI_Set(&talker,&record);
		default:continue;
		}
	}
}

//�������ع�꺯��
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
/*��ʼ����UI*/
void UI_Ready() {

}
/*�����¼UI*/
void UI_History() {

}
/*���ý���UI*/
void UI_Set(LinkList* talker,int* record) {
	char choose;
	while (TRUE) {
		system("CLS");
		printf("1.���ñ��������¼����\n");
		printf("2.�����û�\n");
		printf("3.����\n");
		choose = _getch();
		switch (choose) {
		case '1':UI_Set_History(record);
		case '2':UI_Set_Talker(talker);
		case '3':return;
		default: {
			printf("��������ȷ��ѡ�\n");
			Sleep(200);
		};break;
		}
	}
}
void UI_Set_History(int* record) {
	system("CLS");
	printf("��ǰ���������¼���ޣ�%d\n",*record);
	printf("����Ҫ�ĳɶ���?");
	scanf_s("%d",record);
}
void UI_Set_Talker(LinkList* talker) {

}