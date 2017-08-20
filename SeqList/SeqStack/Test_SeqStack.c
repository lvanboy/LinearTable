#include <stdio.h>
#include "SeqList.h"
#include "SeqStack.h"

int main(){
	int capacity = 10;
	int i = 0;
	int len = 0;
	SeqStack *stack = Create_SeqStack(capacity);

	for ( i = 0; i < capacity; i++){
		Push(stack, &i);
	}
	
	len  = Get_Length(stack);  
	printf("length = %d\n", len);
	//配合删除使用的话,长度每次都会变短.一般使用while循环,而不是for
	//for (i = 0; i <Get_Length(stack); i++){
	for (i = 0; i <len ; i++){
		int *temp = Top(stack);
		printf("the index is %d\n", *temp);
		Pop(stack);
	}
	printf("clearing....\n");
	Clear_SeqStack(stack);
	printf("destoring....\n");
	Destory_SeqSatck(stack);
	getchar();
	return 0;
}