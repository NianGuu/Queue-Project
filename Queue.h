#include <stdio.h>
#include <malloc.h>



typedef struct {
	char line[LINE_LENGTH];			//句子
	Talker talker;					//发言者
}Line;

typedef Line datatype;

typedef struct node {
	datatype data;
	struct node* next;
}QNode;
typedef struct {
	QNode* front;
	QNode* rear;
}LinkQueue;

/*建立句子*/
Line CraftLine(char line[LINE_LENGTH], Talker talker) {
	Line re;
	strcpy_s(re.line, line);
	re.talker = talker;
	return re;
}
/*建空队*/
LinkQueue InitQueue() {
	LinkQueue queue={};
	queue.front = NULL;
	queue.rear = NULL;
	return queue;
}
/*判空队*/
int EmptyQueue(LinkQueue queue) {
	if (queue.front == NULL)
		return 1;
	return 0;
}
/*求队长*/
int LengthQueue(LinkQueue queue) {
	int i = 0;
	while (!EmptyQueue(queue)) {
		i++;
		queue.front = queue.front->next;
	}
	return i;
}
/*入队*/
int EnQueue(LinkQueue* queue, datatype x) {
	if (EmptyQueue(*queue)) {
		QNode* p = (QNode*)malloc(sizeof(QNode));
		p->data = x;
		p->next = queue->front;
		queue->front = p;
		queue->rear = p;
		return 0;
	}
	QNode* p = (QNode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	queue->rear->next = p;
	queue->rear = p;
	return 0;
}
/*出队*/
int DeQueue(LinkQueue* queue, datatype* x) {
	if (EmptyQueue(*queue))
		return ERR_QUEUEEMPTY;
	QNode* p = (QNode*)malloc(sizeof(QNode));
	p = queue->front;
	*x = p->data;
	queue->front = p->next;
	free(p);
	return 0;
}
/*求队长*/
int QueueLength(LinkQueue queue) {
	int i = 0;
	while (queue.front) {
		i++;
		queue.front = queue.front->next;
	}
	return i;
}
/*取队头*/
int GetHead(LinkQueue queue, datatype* x) {
	if (EmptyQueue(queue))
		return 1;
	*x = queue.front->data;
	return 0;
}
/*遍历*/
void Traversal(LinkQueue queue) {
	while (!EmptyQueue(queue)) {
		printf("\33[%dm%s:%s\n",queue.front->data.talker.color,queue.front->data.talker.name,queue.front->data.line);
		queue.front = queue.front->next;
	}
	putchar(10);
}