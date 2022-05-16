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

int ToInt32(char[]);					//字符串类型转换为整型
void UI_ERROR();						//输入错误

void UI_Ready();						//开始聊天UI

void UI_History();						//聊天记录UI

void UI_Set(LinkList*, int*);			//设置界面UI
void UI_Set_History(int*);				//设置聊天记录上限
void UI_Set_Talker(LinkList*);			//设置发言者
void UI_Set_Talker_Add(LinkList*);		//添加发言者
void UI_Set_Talker_Delete(LinkList*);	//删除发言者

int main() {
	LinkList talker = InitList();		//初始化发言者列表
	int record = 10;					//初始化可保存聊天记录上限
	char choose;
	while (TRUE) {
		system("CLS");
		printf("\33[0m\33[?25l1.开始聊天\n");
		printf("2.聊天记录\n");
		printf("3.设置\n");
		choose = _getch();
		switch (choose) {
		case '1':UI_Ready();
		case '2':UI_History();
		case '3':UI_Set(&talker, &record);
		default:continue;
		}
	}
}


/*输入错误*/
void UI_ERROR() {
	printf("\33[31m请输入正确的选项\33[0m");
	printf("\33[0A");
	printf("\33[0B");
	Sleep(200);
}
/*开始聊天UI*/
void UI_Ready() {

}
/*聊天记录UI*/
void UI_History() {

}
/*设置界面UI*/
void UI_Set(LinkList* talker, int* record) {
	char choose;
	while (TRUE) {
		system("CLS");
		printf("\33[?25l设置\n");
		printf("***********\n");
		printf("1.设置记录上限\n");
		printf("2.设置用户\n");
		printf("3.返回\n");
		choose = _getch();
		switch (choose) {
		case '1':UI_Set_History(record);break;
		case '2':UI_Set_Talker(talker);break;
		case '3':return;
		default:UI_ERROR();break;
		}
	}
}
/*设置历史记录上限*/
void UI_Set_History(int* record) {
	int i;
	while (TRUE) {
		system("CLS");
		char length[NAME_LENGTH];
		printf("当前保存聊天记录上限：%d\n", *record);
		printf("\33[?25h你想要改成多少?\n");
		if ((i = ToInt32(gets_s(length))) == -1) {
			UI_ERROR();
			continue;
		}
		*record = i;
		break;
	}
}
/*设置发言者*/
void UI_Set_Talker(LinkList* talker) {
	char choose;
	while (TRUE) {
		system("CLS");
		printf("当前发言者：\n");
		Traversal(*talker);
		printf("\n\33[0m请选择你的操作：\n");
		printf("1.添加\n");
		printf("2.删除\n");
		printf("3.返回\n");
		choose = _getch();
		switch (choose) {
		case '1':UI_Set_Talker_Add(talker);break;
		case '2':UI_Set_Talker_Delete(talker);break;
		case '3':return;
		default:UI_ERROR();break;
		}
	}
}
/*添加发言者*/
void UI_Set_Talker_Add(LinkList* list) {
	char name[NAME_LENGTH];
	char color;
	printf("\33[?25h请输入发言者名字：\n");
	gets_s(name);
	while (TRUE) {
		printf("\33[?25l\33[20D请选择发言者颜色：\n\n");
		printf("\33[31m1.红色\n");
		printf("\33[32m2.绿色\n");
		printf("\33[33m3.黄色\n");
		printf("\33[34m4.蓝色\n");
		printf("\33[35m5.紫色\n");
		printf("\33[36m6.青色\n");
		printf("\33[37m7.白色\n");
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
/*删除发言者*/
void UI_Set_Talker_Delete(LinkList* list) {

}

/*字符串转换为整型*/
int ToInt32(char ch[]) {
	if (ch[0] == '\0')
		return -1;
	for (int i = 0;ch[i] != '\0';i++)					//若字符串中含有非数字，则返回值-1
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