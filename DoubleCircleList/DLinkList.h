#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_
typedef void DLinkList;
typedef struct _tag_DLinkListNode_{
	struct _tag_DLinkListNode_ *next;
	struct _tag_DLinkListNode_ *pre;
}DLinkListNode;

DLinkList *Create_DLinkList();
void Destory_DLinkList(DLinkList *list);
void Clear_DLinkList(DLinkList *list);
int Get_Length(DLinkList *list);
int  Insert_DLinkList(DLinkList *list, DLinkListNode *node,int pos);
DLinkListNode *Get_DLinkListNode(DLinkList *list, int pos);
DLinkListNode *DeleteByPos_DLinkListNode(DLinkList *list, int pos);
DLinkListNode *DeleteByNode_DLinkListNode(DLinkList *list, DLinkListNode *node);
DLinkListNode *Reset_DLinkList(DLinkList *list);
DLinkListNode *Current_DLinkList(DLinkList *list);
DLinkListNode *Pre_DLinkList(DLinkList *list);
DLinkListNode *Next_DLinkList(DLinkList *list);

#endif
