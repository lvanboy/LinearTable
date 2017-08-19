#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleList.h"
typedef struct _tag_CircleList_{   //结构体顺序很重要
	CircleListNode head;
	CircleListNode *slider;
	int length;
}TCircleList;

CircleList *Create_CircleList(){
	TCircleList *ret = (TCircleList *)malloc(sizeof(TCircleList));
	if (ret == NULL){
		return NULL;
	}
	ret->length = 0;
	ret->head.next = NULL;
	ret->slider = NULL;
	return ret;
}

void Destory_CircleList(CircleList *list){
	if (list == NULL){
		return;
	}
	free(list);
}

void Clear_CircleList(CircleList *list){
	TCircleList *ret = (TCircleList *)list;
	if (ret == NULL){
		return;
	}
	ret->length = 0;
	ret->head.next = NULL;
	ret->slider = NULL;
	return;
}

int Get_Length(CircleList *list){
	TCircleList *ret = (TCircleList *)list;
	if (ret == NULL){
		return 0;
	}
	return ret->length;
}

int Insert_CircleList(CircleList *list, CircleListNode *node, int pos){
	TCircleList *ret = (TCircleList *)list;
	
	if (ret == NULL || node == NULL){
		return 0;
	}
	if (pos < 0 || pos >ret->length){
		return -1;
	}
	//地址与结构体顺序有关,这里取到的head 的地址
	CircleListNode *current = (CircleListNode *)ret;

	for (int i = 0; i < pos&&current->next != NULL; i++){
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	
	if (ret->length == 0){
		ret->slider = node;
	}
	ret->length++;
	if (current == (CircleListNode *)ret){
		CircleListNode *last = Get_CircleList(list, ret->length - 1);
		last->next = current->next;
	}
	
	return 1;
}

CircleListNode *Get_CircleList(CircleList *list, int pos){
	TCircleList *ret = (TCircleList *)list;
	if (ret == NULL){
		return NULL;
	}
	if (pos < 0 || pos > ret->length){
		return NULL;
	}
	CircleListNode *current = (CircleListNode *)ret;
	while (current->next != NULL&&pos--){
		current = current->next;
	}
	return current->next;
}

CircleListNode *DeleteByPos_CircleList(CircleList *list, int pos){
	TCircleList *ret = (TCircleList *)list;
	CircleListNode *delete_item = NULL;
	if (ret == NULL){
		return NULL;
	}
	if (pos < 0 || pos > ret->length){
		return NULL;
	}
	CircleListNode *current = (CircleListNode *)ret;
	while (current->next != NULL&&pos--){
		current = current->next;
	}
	delete_item = current->next;
	current->next = delete_item->next;
	ret->length--;
	if (pos == 0){
		CircleListNode *last = Get_CircleList(list, ret->length - 1);
		if (last == NULL){
			return NULL;
		}
		ret->head.next = delete_item->next;
		last->next = delete_item->next;
	}
	if (delete_item == ret->slider){
		ret->slider = delete_item->next;
	}
	if (ret->length == 0){
		ret->slider = NULL;
		ret->head.next = NULL;
	}
	return delete_item;

}

CircleListNode *DeleteByNode_CircleList(CircleList *list, CircleListNode *node ){
	TCircleList *ret = (TCircleList *)list;

	CircleListNode *delete_point = NULL;
	int i;
	if (ret == NULL || node ==NULL){
		return NULL;
	}
	CircleListNode *current = (CircleListNode *)ret;
	for ( i = 0; i < ret->length; i++){
		if (current->next == node){
			delete_point = current->next;
			break;
		}
		current = current->next;
	}
	if (delete_point != NULL){
		delete_point = DeleteByPos_CircleList(list, i);
	}

	return delete_point;
}

CircleListNode *Reset_CircleList(CircleList *list){
	TCircleList *ret = (TCircleList *)list;
	if (ret != NULL){
		ret->slider = ret->head.next;
	}
	return ret->slider;
}

CircleListNode *Current_CircleList(CircleList *list){
	TCircleList *ret = (TCircleList *)list;
	if (ret == NULL){
		return NULL;
	}
	return ret->slider;
}

CircleListNode *Next_CircleList(CircleList *list){
	TCircleList *ret = (TCircleList *)list;
	CircleListNode *cur = NULL;
	if (ret == NULL || ret->slider == NULL){
		return NULL;
	}
	cur = ret->slider;
	ret->slider = cur->next;
	return ret->slider;	
}
