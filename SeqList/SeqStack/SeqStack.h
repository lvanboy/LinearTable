//顺序结构的栈, 是一种特殊的顺序表. 即 顺序栈 是 顺序表的一个子集

#ifndef _SeqStack_H_
#define _SeqStack_H_
typedef void SeqStack;

SeqStack *Create_SeqStack(int capacity);
void Destory_SeqSatck(SeqStack *stack);
void Clear_SeqStack(SeqStack *stack);
int Get_Length(SeqStack *stack);
int Get_Size(SeqStack *stack);
int *Push(SeqStack *stack,void *item);
void *Pop(SeqStack *stack);
void *Top(SeqStack *stack);

#endif
