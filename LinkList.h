
typedef struct {
	char name[NAME_LENGTH];		//发言者名字
	char color;					//发言者颜色
}Talker;
typedef struct listnode {
	Talker talker;
	struct listnode* next;
}ListNode,*LinkList;

/*建立发言者*/
Talker CraftTalker(char name[NAME_LENGTH],char color) {
	Talker talker={};
	talker.color = color;
	strcpy_s(talker.name, name);
	return talker;
}
/*建空表*/
LinkList InitList() {
	LinkList p=NULL;
	return p;
}
/*插入*/
void Insert(LinkList* list, Talker talker) {
	LinkList p = (LinkList)malloc(sizeof(ListNode));
	p->talker = talker;
	p->next = *list;
	*list = p;
}
/*遍历*/
void Traversal(LinkList list) {
	int i = 1;
	while (list) {
		printf("\33[%dm%d.%s\n",i,list->talker.color,list->talker.name);
		list = list->next;
		i++;
	}
}