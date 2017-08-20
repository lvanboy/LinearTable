#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkList.h"
typedef struct _tag_LinkList_{
	int length;
	/*LinkListNode *head;*/
	LinkListNode head;
}TLinkList;

LinkList *Create_LinkList(){
	TLinkList *ret = (TLinkList *)malloc(sizeof(TLinkList));
	if (ret == NULL){
		return NULL;
	}
	ret->length = 0;
	ret->head.next = NULL;
	return ret;
}

void Destory_LinkList(LinkList *list){
	if (list == NULL){
		return;
	}
	free(list);
	return;
}

void Clear_LinkList(LinkList *list){
	TLinkList *ret = (TLinkList *)list;
	if (ret == NULL){
		return;
	}
	ret->length = 0;
	ret->head.next = NULL;
	return;
}
int  LinkList_Length(LinkList *list){
	TLinkList *ret = (TLinkList *)list;
	if (ret == NULL){
		return 0;
	}
	return ret->length;
}

//insert before the pos
int  Insert_LinkList(LinkList *list, LinkListNode *node, int pos){
	TLinkList *ret = (TLinkList *)list;
	LinkListNode *p = &ret->head;

	if (ret == NULL || node == NULL){
		return -1;
	}
	if (pos < 0){
		return -2;
	}
	if (pos > LinkList_Length(list)){
		pos = LinkList_Length(list);
	}
	while (p->next != NULL && pos--){
		p = p->next;
	}
	node->next = p->next;
	p->next = node;
	ret->length++;
	return 1;
}

LinkListNode *Get_LinkListNode(LinkList *list, int pos){
	TLinkList *ret = (TLinkList *)list;
	LinkListNode *p = &ret->head;
	if (ret == NULL){
		return NULL;
	}
	if (pos < 0 || pos > LinkList_Length(list)){
		return NULL;
	}
	while (p->next != NULL && pos--){
		p = p->next;
	}
	return p->next;
}

LinkListNode *Delete_LinkListNode(LinkList *list, int pos){
	TLinkList *ret = (TLinkList *)list;
	LinkListNode *p = &ret->head;
	LinkListNode *delete_item = NULL;
	if (ret == NULL){
		return NULL;
	}
	if (pos < 0 || pos >= LinkList_Length(list)){
		return NULL;
	}
	while (p->next != NULL && pos--){
		p = p->next;
	}
    delete_item = p->next;
	p->next = delete_item->next;
	ret->length--;
	return delete_item;
}
