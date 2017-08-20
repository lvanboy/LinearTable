#include <stdio.h>
#include <stdlib.h>
//该文件来自上上级目录文件
#include "LinkList.h"
#include "LinkStack.h"

//包装数据
typedef struct _tag_LinkStack_{
	LinkListNode node; 
	void *value;
}TLinkStack;

LinkStack *Create_LinkStack(){
	return Create_LinkList();
}

void Destory_LinkStack(LinkStack *stack){
	//先清空,再销毁
	Clear_LinkStack(stack);
	Destory_LinkList(stack);
}

void Clear_LinkStack(LinkStack *stack){
	while (Get_Length(stack) > 0){
		Pop(stack);
	}
}

int Get_Length(LinkStack *stack){
	return LinkList_Length(stack);
}

int Push(LinkStack *stack, void *item){
	TLinkStack *container = (TLinkStack *)malloc(sizeof(TLinkStack));
	if (container == NULL){
		return 0;
	}
	container->value = item;
	//开口向左的栈
	if (Insert_LinkList(stack, (LinkListNode *)(&container->node), 0)){
		//free(container);
	}
	return 1;
}

void *Top(LinkStack *stack){
	TLinkStack *temp = (TLinkStack *)Get_LinkListNode(stack, 0);
	if (temp == NULL){
		return NULL;
	}
	return temp->value;
}

void *Pop(LinkStack *stack){
	//弹出时,释放堆上的空间
	TLinkStack *temp = (TLinkStack *)Delete_LinkListNode(stack, 0);
	if (temp == NULL){
		return NULL;
	}
	else{
		free(temp); 
	}
	return temp->value;
}
