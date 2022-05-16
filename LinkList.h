
typedef struct {
	char name[NAME_LENGTH];		//����������
	char color;					//��������ɫ
}Talker;
typedef struct listnode {
	Talker talker;
	struct listnode* next;
}ListNode,*LinkList;

/*���ձ�*/
LinkList InitList() {
	LinkList p=NULL;
	return p;
}
/*����*/
void Insert(LinkList* list, Talker talker) {
	LinkList p = (LinkList)malloc(sizeof(ListNode));
	p->talker = talker;
	p->next = *list;
	*list = p;
}
/*����*/
void Traversal(LinkList list) {
	while (list) {
		printf("1.\33[%dm%s\n",list->talker.color,list->talker.name);
		list = list->next;
	}
}