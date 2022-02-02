#include "stdafx.h"
#include "stdlib.h"


typedef struct Link{
	char elem;	//数据域
	struct Link * next;	//指针域
}link;

link * initLink(link * p, int elem, int add);
link * insertLink(link * p, int add);
link * delElem(link * p, int add);
int selectElem(link * p, int elem);
void display(link *p);

//链表的创建和遍历
link * initLink(){
	link * p = (link*)malloc(sizeof(link));	//定义头结点
	link * temp = p;	//声明指针指向头结点
	//生成链表
	for (int i = 1; i < 5; i++){
		link *a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}
	return p;
}

//向链表中插入结点
link * insertElem(link * p, int elem, int add){
	link * temp = p;	//创建临时节点
	//找上一个节点
	for (int i = 1; i < add; i++){
		if (temp == NULL){
			printf("NULL");
			return p;
		}
		temp = temp->next;
	}
	//创建插入结点n
	link * n = (link*)malloc(sizeof(link));
	n->elem = elem;
	//插入节点n到链表
	n->next = temp->next;
	temp->next = n;
	return p;
}

//从链表中删除节点
link * delElem(link * p, int add){
	link * temp = p;
	//temp指向被删除节点的上一个节点
	for (int i = 1; i < add; i++){
		temp = temp -> next;
	}
	link * del = temp->next;	//单独设置一个指针指向被删除结点，以防丢失
	temp->next = temp->next->next;	//删除某个结点的方法就是更改前一个结点的指针域
	free(del);	//释放
	return p;
}

//链表中查找某结点
int selectElem(link * p, int elem){
	link * t = p;
	int i = 1;
	while (t->next){
		t = t->next;
		if (t->elem == elem){
			return i;
		}
		i++;
	}
	return -1;
}

void display(link *p){
	link* temp = p;	//temp指针重新指向头
	while (temp->next){
		temp = temp->next;
		printf("%d", temp->elem);
	}
	printf("\n");
}

int main(){
	//初始化4个链表
	printf("正在初始化链表：");
	link *p = initLink();
	display(p);

	printf("第4个位置插入元素5\n");
	p = insertElem(p, 5, 4);
	display(p);

	printf("删除元素3\n");
	p = delElem(p, 3);
	display(p);

	printf("元素2的位置为：\n");
	int address = selectElem(p, 2);
	if (address == -1) {
		printf("没有该元素");
	}
	else{
		printf("元素2的位置为：%d\n", address);
	}
	printf("目前所有：");
	display(p);

	return 0;
}
