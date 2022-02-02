#include "stdafx.h"
#include "stdlib.h"


typedef struct Link{
	char elem;	//������
	struct Link * next;	//ָ����
}link;

link * initLink(link * p, int elem, int add);
link * insertLink(link * p, int add);
link * delElem(link * p, int add);
int selectElem(link * p, int elem);
void display(link *p);

//����Ĵ����ͱ���
link * initLink(){
	link * p = (link*)malloc(sizeof(link));	//����ͷ���
	link * temp = p;	//����ָ��ָ��ͷ���
	//��������
	for (int i = 1; i < 5; i++){
		link *a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}
	return p;
}

//�������в�����
link * insertElem(link * p, int elem, int add){
	link * temp = p;	//������ʱ�ڵ�
	//����һ���ڵ�
	for (int i = 1; i < add; i++){
		if (temp == NULL){
			printf("NULL");
			return p;
		}
		temp = temp->next;
	}
	//����������n
	link * n = (link*)malloc(sizeof(link));
	n->elem = elem;
	//����ڵ�n������
	n->next = temp->next;
	temp->next = n;
	return p;
}

//��������ɾ���ڵ�
link * delElem(link * p, int add){
	link * temp = p;
	//tempָ��ɾ���ڵ����һ���ڵ�
	for (int i = 1; i < add; i++){
		temp = temp -> next;
	}
	link * del = temp->next;	//��������һ��ָ��ָ��ɾ����㣬�Է���ʧ
	temp->next = temp->next->next;	//ɾ��ĳ�����ķ������Ǹ���ǰһ������ָ����
	free(del);	//�ͷ�
	return p;
}

//�����в���ĳ���
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
	link* temp = p;	//tempָ������ָ��ͷ
	while (temp->next){
		temp = temp->next;
		printf("%d", temp->elem);
	}
	printf("\n");
}

int main(){
	//��ʼ��4������
	printf("���ڳ�ʼ������");
	link *p = initLink();
	display(p);

	printf("��4��λ�ò���Ԫ��5\n");
	p = insertElem(p, 5, 4);
	display(p);

	printf("ɾ��Ԫ��3\n");
	p = delElem(p, 3);
	display(p);

	printf("Ԫ��2��λ��Ϊ��\n");
	int address = selectElem(p, 2);
	if (address == -1) {
		printf("û�и�Ԫ��");
	}
	else{
		printf("Ԫ��2��λ��Ϊ��%d\n", address);
	}
	printf("Ŀǰ���У�");
	display(p);

	return 0;
}
