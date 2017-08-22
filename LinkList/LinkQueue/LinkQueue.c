#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"
#include "LinkQueue.h"


//已链表能接受的节点 ,封装数据
typedef struct _tag_LinkQueue{
	LinkListNode node;
	void *value;
}TLinkQueue;

LinkQueue  *Create_LinkQueue(){
	return Create_LinkList();
}

void Destory_LinkQueue(LinkQueue *queue){
	Clear_LinkQueue(queue);
	Destory_LinkList(queue);
}

void Clear_LinkQueue(LinkQueue *queue){
	Clear_LinkList(queue);
}

int _Get_Length(LinkQueue *queue){
	return LinkList_Length(queue);
}

int Append_LinkQueue(LinkQueue *queue, void *item){
	TLinkQueue *ret = (TLinkQueue *)malloc(sizeof(TLinkQueue));
	if (ret == NULL){
		return 0;
	}
	memset(ret, 0, sizeof(TLinkQueue));
	ret->value = item;
	Insert_LinkList(queue, (LinkListNode *)ret, _Get_Length(queue));
	return 0;
}

LinkQueue *Retrieve_LinkQueue(LinkQueue *queue){
	TLinkQueue *temp = (TLinkQueue *)Delete_LinkListNode(queue, 0);
	if (temp == NULL){
		return NULL;
	}
	else{
		free(temp);
	}
	return temp->value;
}

LinkQueue *_Get_Header(LinkQueue *queue){
	TLinkQueue *temp = (TLinkQueue *)Get_LinkListNode(queue, 0);
	if (temp == NULL){
		return NULL;
	}
	return temp->value;
}