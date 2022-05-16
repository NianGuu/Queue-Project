#define TRUE 1
#define	FALSE 0
#define NAME_LENGTH 20
#define ERR_QUEUEEMPTY -1
#define SUCCESS 0
#define LINE_LENGTH 200


#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<math.h>
#include"LinkList.h"
#include"Queue.h"

int ToInt32(char[]);					//�ַ�������ת��Ϊ����
void UI_ERROR();						//�������

void UI_Ready();						//��ʼ����UI

void UI_History();						//�����¼UI

void UI_Set(LinkList*, int*);			//���ý���UI
void UI_Set_History(int*);				//���������¼����
void UI_Set_Talker(LinkList*);			//���÷�����
void UI_Set_Talker_Add(LinkList*);		//��ӷ�����
void UI_Set_Talker_Delete(LinkList*);	//ɾ��������

int main() {
	LinkList talker = InitList();		//��ʼ���������б�
	int record = 10;					//��ʼ���ɱ��������¼����
	char choose;
	while (TRUE) {
		system("CLS");
		printf("\33[0m\33[?25l1.��ʼ����\n");
		printf("2.�����¼\n");
		printf("3.����\n");
		choose = _getch();
		switch (choose) {
		case '1':UI_Ready();
		case '2':UI_History();
		case '3':UI_Set(&talker, &record);
		default:continue;
		}
	}
}


/*�������*/
void UI_ERROR() {
	printf("\33[31m��������ȷ��ѡ��\33[0m");
	printf("\33[0A");
	printf("\33[0B");
	Sleep(200);
}
/*��ʼ����UI*/
void UI_Ready() {

}
/*�����¼UI*/
void UI_History() {

}
/*���ý���UI*/
void UI_Set(LinkList* talker, int* record) {
	char choose;
	while (TRUE) {
		system("CLS");
		printf("\33[?25l����\n");
		printf("***********\n");
		printf("1.���ü�¼����\n");
		printf("2.�����û�\n");
		printf("3.����\n");
		choose = _getch();
		switch (choose) {
		case '1':UI_Set_History(record);break;
		case '2':UI_Set_Talker(talker);break;
		case '3':return;
		default:UI_ERROR();break;
		}
	}
}
/*������ʷ��¼����*/
void UI_Set_History(int* record) {
	int i;
	while (TRUE) {
		system("CLS");
		char length[NAME_LENGTH];
		printf("��ǰ���������¼���ޣ�%d\n", *record);
		printf("\33[?25h����Ҫ�ĳɶ���?\n");
		if ((i = ToInt32(gets_s(length))) == -1) {
			UI_ERROR();
			continue;
		}
		*record = i;
		break;
	}
}
/*���÷�����*/
void UI_Set_Talker(LinkList* talker) {
	char choose;
	while (TRUE) {
		system("CLS");
		printf("��ǰ�����ߣ�\n");
		Traversal(*talker);
		printf("\n\33[0m��ѡ����Ĳ�����\n");
		printf("1.���\n");
		printf("2.ɾ��\n");
		printf("3.����\n");
		choose = _getch();
		switch (choose) {
		case '1':UI_Set_Talker_Add(talker);break;
		case '2':UI_Set_Talker_Delete(talker);break;
		case '3':return;
		default:UI_ERROR();break;
		}
	}
}
/*��ӷ�����*/
void UI_Set_Talker_Add(LinkList* list) {
	char name[NAME_LENGTH];
	char color;
	printf("\33[?25h�����뷢�������֣�\n");
	gets_s(name);
	while (TRUE) {
		printf("\33[?25l\33[20D��ѡ��������ɫ��\n\n");
		printf("\33[31m1.��ɫ\n");
		printf("\33[32m2.��ɫ\n");
		printf("\33[33m3.��ɫ\n");
		printf("\33[34m4.��ɫ\n");
		printf("\33[35m5.��ɫ\n");
		printf("\33[36m6.��ɫ\n");
		printf("\33[37m7.��ɫ\n");
		printf("\33[8A");
		color = _getch();
		if (color < '1' || color>'7') {
			printf("\33[1A\33[20D");
			UI_ERROR();
			continue;
		}
		Insert(list, CraftTalker(name, color - 18));
		break;
	}
}
/*ɾ��������*/
void UI_Set_Talker_Delete(LinkList* list) {

}

/*�ַ���ת��Ϊ����*/
int ToInt32(char ch[]) {
	if (ch[0] == '\0')
		return -1;
	for (int i = 0;ch[i] != '\0';i++)					//���ַ����к��з����֣��򷵻�ֵ-1
		if (ch[i] < '0' || ch[i]>'9')
			return -1;
	int num = 0;
	int j;
	for (int i = 0;ch[i] != '\0';i++) {
		num *= pow(10, i);
		num += (ch[i] - 48);
	}
	return num;
}