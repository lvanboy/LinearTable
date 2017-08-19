#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_
typedef void SeqList;
typedef void SeqListNode;

// 创建一个顺序表
SeqList *Create_SeqList(int capacity);
//销毁一个顺序表
void Destory_SeqList(SeqList *list);
//清除表中元素
void Clear_SeqList(SeqList *list);
//得到顺序表的长度
int SeqList_Length(SeqList *list);
//得到顺序表的容量
int SeqList_Capacity(SeqList *list);
//在指定位置插入指定节点
int  Insert_SeqList(SeqList *list, SeqList *node, int pos);
//得到指定位置的节点地址
SeqList *Get_Node(SeqList *list,int pos);
//删除指定节点，返回删除节点地址
SeqList *Delete_Node(SeqList *list, int pos);

 

#endif
