#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
typedef void LinkStack;
LinkStack *Create_LinkStack();
void Destory_LinkStack(LinkStack *stack);
void Clear_LinkStack(LinkStack *stack);
int Get_Length(LinkStack *stack);
int Push(LinkStack *stack, void *item);
void *Top(LinkStack *stack);
void *Pop(LinkStack *stack);


#endif
