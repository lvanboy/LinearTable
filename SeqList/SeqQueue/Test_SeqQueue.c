#include <stdio.h>
#include "SeqList.h"
#include "SeqQueue.h"


int _main(){
	int a[10];
	SeqQueue *queue = Create_SeqQueue(10);
	for (int i = 0; i < Get_Size(queue); i++){
		a[i] = i;
		Append_SeqQueue(queue, a+i);
	}
	printf("the header of queue is %d\n",*(int *)Get_Header(queue));
	while (Get_Length(queue) > 0){
		int temp = *((int *)Retrieve_SeqQueue(queue));
		printf("the value of queue is %d\n", temp);
	}
	Destory_SeqQueue(queue);
	getchar();
	return 0;
}