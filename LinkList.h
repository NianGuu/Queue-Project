
typedef struct {
	char name[NAME_LENGTH];		//����������
	char color;					//��������ɫ
}Talker;
typedef struct listnode {
	Talker talker;
	struct listnode* next;
}ListNode,*LinkList;

/*����������*/
Talker CraftTalker(char name[NAME_LENGTH],char color) {
	Talker talker={};
	talker.color = color;
	strcpy_s(talker.name, name);
	return talker;
}
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
	int i = 1;
	while (list) {
		printf("\33[%dm%d.%s\n",i,list->talker.color,list->talker.name);
		list = list->next;
		i++;
	}
}