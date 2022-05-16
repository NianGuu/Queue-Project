
typedef struct {
	char name[NAME_LENGTH];		//发言者名字
	char color;					//发言者颜色
}Talker;
typedef struct listnode {
	Talker talker;
	struct listnode* next;
}ListNode,*LinkList;

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
	while (list) {
		printf("1.\33[%dm%s\n",list->talker.color,list->talker.name);
		list = list->next;
	}
}