#include <stdio.h>
#include "SeqList.h"
#include "SeqQueue.h"

SeqQueue *Create_SeqQueue(int capacity){
	return Create_SeqList(capacity);
}

void Destory_SeqQueue(SeqQueue *queue){
	Clear_SeqQueue(queue);
	Destory_SeqList(queue);
	return;
}

void Clear_SeqQueue(SeqQueue *queue){
	while (Get_Length(queue) > 0){
		Retrieve_SeqQueue(queue);
	}
	return;
}

int Get_Length(SeqQueue *queue){
	return SeqList_Length(queue);
}
int Get_Size(SeqQueue *queue){
	return SeqList_Capacity(queue);
}

int Append_SeqQueue(SeqQueue *queue, void *item){
	return Insert_SeqList(queue, item, Get_Length(queue));
}

SeqQueue *Retrieve_SeqQueue(SeqQueue *queue){
	return Delete_Node(queue, 0);
}

SeqQueue *Get_Header(SeqQueue *queue){
	return Get_Node(queue, 0);
}