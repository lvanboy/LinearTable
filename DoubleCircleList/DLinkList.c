#include <stdio.h>
#include <stdlib.h>
#include "DListLink.h"

typedef struct _tag_DLinkList_{
	DLinkListNode head;
	DLinkListNode *slider;
	int length;
}TDLinkList;

DLinkList *Create_DLinkList(){
	TDLinkList *ret = (TDLinkList *)malloc(sizeof(TDLinkList));
	if (ret == NULL){
		return NULL;
	}
	ret->head.next = NULL;
	ret->head.pre = NULL;
	ret->length = 0;
	ret->slider = NULL;
	return ret;
}

void Destory_DLinkList(DLinkList *list){
	if (list == NULL){
		return;
	}
	free(list);
	return;
}

void Clear_DLinkList(DLinkList *list){
	TDLinkList * ret = (TDLinkList *)list;
	if (ret == NULL){
		return;
	}
	ret->head.next = NULL;
	ret->head.pre = NULL;
	ret->length = 0;
	ret->slider = NULL;
}

int Get_Length(DLinkList *list){
	TDLinkList *ret = (TDLinkList *)list;
	if (ret == NULL){
		return 0;
	}
	return ret->length;
}
//pos 是下表 
//例如pos等于0,相当于插入第一个位置.
int  Insert_DLinkList(DLinkList *list, DLinkListNode *node, int pos){
	TDLinkList *ret = (TDLinkList *)list;
	if (ret == NULL || node == NULL){
		return 0;
	}
	if (pos < 0 || pos > ret->length){
		return 0;
	}
	DLinkListNode *current = (DLinkListNode *)ret;
	DLinkListNode *next = NULL;
	DLinkListNode *last = NULL;
	while (current->next != NULL && pos--){
		current = current->next;
	}
	next = current->next;
	current->next = node;
	node->next = next;
	if (next != NULL){    //不是第一次插入
		next->pre = node;
	}
	node->pre = current;
	if (ret->length == 0){
		ret->slider = node;
		node->next = current->next;
	}
	//这里在length++之前,所以拿到的是null 之前的元素
	
	//在第一个位置插入
	if (current == (DLinkListNode *)ret ){
		//本身已经增加1,而length当前还没有+1,
		last = Get_DLinkListNode(list, ret->length);
		node->pre = last;
		last->next = node;
	}
	
	ret->length++;
	return 1;
}
//pos 表示 从0到pos  ,而while循环相当于移动了0到pos-1次,还差一次,所以当前节点是current->next
//pos 相当于下标,所以你想取第五个元素,pos 应该填四
DLinkListNode *Get_DLinkListNode(DLinkList *list, int pos){
	TDLinkList *ret = (TDLinkList *)list;
	if (ret == NULL){
		return NULL;
	}
	if (pos < 0 || pos > ret->length){
		return NULL;
	}
	//拿到首地址
	DLinkListNode *current = (DLinkListNode *)ret;
	DLinkListNode *next = NULL;
	while (current->next != NULL && pos--){
		current = current->next;
	}
	next = current->next;
	return next;
}

//
DLinkListNode *DeleteByPos_DLinkListNode(DLinkList *list, int pos){
	TDLinkList *ret = (TDLinkList *)list;
	if (ret == NULL){
		return NULL;
	}
	if (pos < 0 || pos > ret->length){
		return NULL;
	}
	if (ret->length == 0){
		return NULL;
	}
	//拿到首地址
	DLinkListNode *current = (DLinkListNode *)ret;
	DLinkListNode *next = NULL;
	DLinkListNode *delete_point = NULL;
	DLinkListNode *last = NULL;
	
	//寻找删除点
	while (current->next != NULL && pos--){
		current = current->next;
	}
	delete_point = current->next;
	next = delete_point->next;
	current->next = next;
	ret->length--;
	if (ret->length == 0){
		ret->head.pre = NULL;
		ret->head.next = NULL;
		ret->slider = NULL;
		return delete_point;
	}
	if (next != NULL){
		
		next->pre = current;
		//provided delete the first node .
		if (current == (DLinkListNode *)ret){
			//本身已经删除长度-1,而现在的length是没有删除的length,真实长度应该-1;
			last =Get_DLinkListNode(list, ret->length - 1);
				next->pre = last;
				if (last != NULL){
					last->next = next;
				}
		}
	}
	if (delete_point == ret->slider){
			ret->slider = next;
	}

	return delete_point;
}


DLinkListNode *DeleteByNode_DLinkListNode(DLinkList *list, DLinkListNode *node){
	TDLinkList *ret = (TDLinkList *)list;
	int i;
	if (ret == NULL || node == NULL){
		return NULL;
	}

	//拿到首地址
	DLinkListNode *current = (DLinkListNode *)ret;
	DLinkListNode *delete_point = NULL;
	for (i = 0; i < ret->length;i++){
		// i = 0时, current 应该是第一个元素,current是头,不是第一个元素
		//if (current == node){
		if (current->next == node){
			delete_point = current->next;
			break;
		}
		current = current->next;
	}
	//found the node
	if (delete_point != NULL){
		DeleteByPos_DLinkListNode(list, i);
	}

	return delete_point;
}
//指向第一个元素
DLinkListNode *Reset_DLinkList(DLinkList *list){
	TDLinkList *ret = (TDLinkList *)list;
	if (ret == NULL){
		return NULL;
	}
	ret->slider = ret->head.next;
	return ret->slider;
}

//当前元素的位置
DLinkListNode *Current_DLinkList(DLinkList *list){
	TDLinkList *ret = (TDLinkList *)list;
	if (ret == NULL){
		return NULL;
	}
	return ret->slider;
}

DLinkListNode *Pre_DLinkList(DLinkList *list){
	TDLinkList *ret = (TDLinkList *)list;
	DLinkListNode *node = NULL;
	if (ret == NULL){
		return NULL;
	}
	node = ret->slider;
	ret->slider = node->pre;
	return ret->slider;
}

DLinkListNode *Next_DLinkList(DLinkList *list){
	TDLinkList *ret = (TDLinkList *)list;
	DLinkListNode *node = NULL;
	if (ret == NULL){
		return NULL;
	}
	node = ret->slider;
	ret->slider = node->next;
	return ret->slider;
}