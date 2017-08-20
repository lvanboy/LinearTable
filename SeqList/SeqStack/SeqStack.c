#include <stdio.h>

#include "SeqList.h"
#include "SeqStack.h"

SeqStack *Create_SeqStack(int capacity){
	return Create_SeqList(capacity);
}

void Destory_SeqSatck(SeqStack *stack){
	Destory_SeqList(stack);
}

void Clear_SeqStack(SeqStack *stack){
	Clear_SeqList(stack);
}
int Get_Length(SeqStack *stack){
	return SeqList_Length(stack);
}
int Get_Size(SeqStack *stack){
	return SeqList_Capacity(stack);
}

int *Push(SeqStack *stack,void *item){
	Insert_SeqList(stack, item, Get_Length(stack) );
	return 0;
}

void *Pop(SeqStack *stack){
	return Delete_Node(stack, Get_Length(stack) - 1);
}

void *Top(SeqStack *stack){
	return Get_Node(stack, Get_Length(stack) - 1);
}