#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "LinkQueue.h"

int main(){
	int a[10];
	LinkQueue *_queue = Create_LinkQueue();
	for (int i = 0; i < 10; i++){
		a[i] = i + 1;
		Append_LinkQueue(_queue, a + i);
	}
	while (_Get_Length(_queue)>0){
		int temp = *(int *)_Get_Header(_queue);
		printf("the value of temp is %d \n", temp);
		Retrieve_LinkQueue(_queue);
	}
	Destory_LinkQueue(_queue);
	getchar();
	return 0;
}