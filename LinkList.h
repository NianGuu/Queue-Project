
typedef struct {
	char name[NAME_LENGTH];		//����������
	char color;					//��������ɫ
}Talker;
typedef struct listnode {
	Talker talker;
	struct listnode* next;
}ListNode, * LinkList;

/*����������*/
Talker CraftTalker(char name[NAME_LENGTH], char color) {
	Talker talker = {};
	talker.color = color;
	strcpy_s(talker.name, name);
	return talker;
}
/*��ȡ������*/
Talker GetTalker(LinkList list, int i) {
	Talker error = { "ERROR",0 };
	int j = 1;
	while (list && j < i) {
		j++;
		list = list->next;
	}
	if (!list)
		return error;
	return list->talker;
}
/*���ձ�*/
LinkList InitList() {
	LinkList p = NULL;
	return p;
}
/*�пձ�*/
int EmptyList(LinkList list) {
	if (!list)
		return 1;
	return 0;
}
/*����*/
void Insert(LinkList* list, Talker talker) {
	LinkList p = (LinkList)malloc(sizeof(ListNode));
	p->talker = talker;
	p->next = *list;
	*list = p;
}
/*ɾ��*/
void Delete(LinkList* list, int i) {
	if (i == 1) {
		LinkList s = *list;
		*list = s->next;
		free(s);
		return;
	}
	int j = 1;
	LinkList p = *list;
	LinkList s;
	while (p && j < i - 1) {
		j++;
		p = p->next;
	}
	s = p->next;
	if (!s)
		return;
	p->next = s->next;
	free(s);
}
/*���*/
int LengthList(LinkList list) {
	int i = 0;
	while (list) {
		i++;
		list = list->next;
	}
	return i;
}
/*����*/
void Traversal(LinkList list) {
	int i = 1;
	while (list) {
		printf("\33[%dm%d.%s\n", list->talker.color, i, list->talker.name);
		list = list->next;
		i++;
	}
}