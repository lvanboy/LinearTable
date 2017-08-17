#ifndef _LINK_LIST_H_ 
#define _LINK_LIST_H_
typedef void LinkList;
typedef struct _tag_LinkListNode{
	struct _tag_LinkListNode *next;
}LinkListNode;

LinkList *Create_LinkList();
void Destory_LinkList(LinkList *list);
void Clear_LinkList(LinkList *list);
int  LinkList_Length(LinkList *list);
int  Insert_LinkList(LinkList *list, LinkListNode *node, int pos);
LinkListNode *Get_LinkListNode(LinkList *list, int pos);
LinkListNode *Delete_LinkListNode(LinkList *list, int pos);
#endif
