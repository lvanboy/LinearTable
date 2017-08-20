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
//pos ���±� 
//����pos����0,�൱�ڲ����һ��λ��.
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
	if (next != NULL){    //���ǵ�һ�β���
		next->pre = node;
	}
	node->pre = current;
	if (ret->length == 0){
		ret->slider = node;
		node->next = current->next;
	}
	//������length++֮ǰ,�����õ�����null ֮ǰ��Ԫ��
	
	//�ڵ�һ��λ�ò���
	if (current == (DLinkListNode *)ret ){
		//�����Ѿ�����1,��length��ǰ��û��+1,
		last = Get_DLinkListNode(list, ret->length);
		node->pre = last;
		last->next = node;
	}
	
	ret->length++;
	return 1;
}
//pos ��ʾ ��0��pos  ,��whileѭ���൱���ƶ���0��pos-1��,����һ��,���Ե�ǰ�ڵ���current->next
//pos �൱���±�,��������ȡ�����Ԫ��,pos Ӧ������
DLinkListNode *Get_DLinkListNode(DLinkList *list, int pos){
	TDLinkList *ret = (TDLinkList *)list;
	if (ret == NULL){
		return NULL;
	}
	if (pos < 0 || pos > ret->length){
		return NULL;
	}
	//�õ��׵�ַ
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
	//�õ��׵�ַ
	DLinkListNode *current = (DLinkListNode *)ret;
	DLinkListNode *next = NULL;
	DLinkListNode *delete_point = NULL;
	DLinkListNode *last = NULL;
	
	//Ѱ��ɾ����
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
			//�����Ѿ�ɾ������-1,�����ڵ�length��û��ɾ����length,��ʵ����Ӧ��-1;
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

	//�õ��׵�ַ
	DLinkListNode *current = (DLinkListNode *)ret;
	DLinkListNode *delete_point = NULL;
	for (i = 0; i < ret->length;i++){
		// i = 0ʱ, current Ӧ���ǵ�һ��Ԫ��,current��ͷ,���ǵ�һ��Ԫ��
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
//ָ���һ��Ԫ��
DLinkListNode *Reset_DLinkList(DLinkList *list){
	TDLinkList *ret = (TDLinkList *)list;
	if (ret == NULL){
		return NULL;
	}
	ret->slider = ret->head.next;
	return ret->slider;
}

//��ǰԪ�ص�λ��
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