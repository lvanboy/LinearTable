#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

typedef struct _tag_seq_list{
	int length;
	int capacity;
	unsigned int *Node;
}T_SeqList;

SeqList *Create_SeqList(int capacity){
	if (capacity <=0){
		return 0;
	}
	T_SeqList *ret = (T_SeqList *)malloc(sizeof(T_SeqList) + sizeof(unsigned int) * capacity );
	if (ret == NULL){
		return 0;
	}
	memset(ret, 0, sizeof(T_SeqList)+sizeof(unsigned int) * capacity);
	ret->Node = (unsigned int *)(ret + 1);
	ret->length = 0;
	ret->capacity = capacity;
	return ret;
}

void Destory_SeqList(SeqList *list){
	T_SeqList *ret = (T_SeqList *)list;
	if (ret == NULL){
		return;
	}
	free(ret);
	return;
}

void Clear_SeqList(SeqList *list){
	T_SeqList *ret = (T_SeqList *)list;
	if (ret == NULL){
		return;
	}
	ret->length = 0;
	return;
	
}

int SeqList_Length(SeqList *list){
	T_SeqList *ret = (T_SeqList *)list;
	if (ret == NULL){
		return 0;
	}
	return ret->length;
}
int SeqList_Capacity(SeqList *list){
		T_SeqList *ret = (T_SeqList *)list;
		if (ret == NULL){
			return 0;
		}
		return ret->capacity;
}

	int  Insert_SeqList(SeqList *list, SeqListNode *node, int pos){
		T_SeqList *ret = (T_SeqList *)list;
		if (ret == NULL || node == NULL){
			return 0;
		}
		if (pos<0 || pos > ret->capacity){
			return -1;
		}
		if (pos > ret->length){
			pos = ret->length;
		}
		if (ret->length >= ret->capacity){
			return -2;
		}
		for (int i = ret->length ; i > pos; i--){
			ret->Node[i] = ret->Node[i-1];
		}
		ret->Node[pos] = (unsigned int )node;
		ret->length++;
		return 1;
}

	SeqListNode *Get_Node(SeqList *list, int pos){
		T_SeqList *ret = (T_SeqList *)list;
		if (ret == NULL){
			return NULL;
		}
		if (pos < 0 || pos >= ret->capacity){
			return NULL;
		}
		return (SeqListNode *)ret->Node[pos];
	}

	SeqList *Delete_Node(SeqList *list, int pos){
		T_SeqList *ret = (T_SeqList *)list;
		SeqListNode *_node = NULL;
		if (ret == NULL || pos < 0 || pos >= ret->capacity){
			return NULL;
		}
		_node = (SeqListNode *)ret->Node[pos];
		for (int i = pos + 1; i < ret->length ; i++){
			ret->Node[i-1] = ret->Node[ i ];
		}
		ret->length--;
		return _node;
	}
