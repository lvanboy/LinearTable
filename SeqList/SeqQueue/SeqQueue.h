// 顺序结构 的队列  也是一种特殊的线性表
#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_
typedef void SeqQueue;
SeqQueue *Create_SeqQueue(int capacity);
void Destory_SeqQueue(SeqQueue *queue);
void Clear_SeqQueue(SeqQueue *queue);
int Get_Length(SeqQueue *queue);
int Get_Size(SeqQueue *queue);
int Append_SeqQueue(SeqQueue *queue, void *item);
SeqQueue *Retrieve_SeqQueue(SeqQueue *queue);
SeqQueue *Get_Header(SeqQueue *queue);

#endif // !_SEQQUEUE_H_
