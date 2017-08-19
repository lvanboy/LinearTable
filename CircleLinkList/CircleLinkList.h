#ifndef  _CIRCLE_LIST_H_
#define _CIRCLE_LIST_H_

typedef struct _tag_CircleListNode_{
	struct _tag_CircleListNode_ *next;
}CircleListNode;
typedef void CircleList;

CircleList *Create_CircleList();
void Destory_CircleList(CircleList *list);
void Clear_CircleList(CircleList *list);
int Get_Length(CircleList *list);
int Insert_CircleList(CircleList *list, CircleListNode *node, int pos);
CircleListNode *Get_CircleList(CircleList *list, int pos);
CircleListNode *DeleteByPos_CircleList(CircleList *list, int pos);
CircleListNode *DeleteByNode_CircleList(CircleList *list, CircleListNode *node);
CircleListNode *Reset_CircleList(CircleList *list);
CircleListNode *Current_CircleList(CircleList *list);
CircleListNode *Next_CircleList(CircleList *list);



#endif // ! _CIRCLE_LIST_H
