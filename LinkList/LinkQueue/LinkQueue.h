//链式队列  ,一种特殊的线性表
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
typedef void  LinkQueue;
LinkQueue  *Create_LinkQueue();
void Destory_LinkQueue(LinkQueue *queue);
void Clear_LinkQueue(LinkQueue *queue);
int _Get_Length(LinkQueue *queue);
int Append_LinkQueue(LinkQueue *queue, void *item);
LinkQueue *Retrieve_LinkQueue(LinkQueue *queue);
LinkQueue *_Get_Header(LinkQueue *queue);
#endif