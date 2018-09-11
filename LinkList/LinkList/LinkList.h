#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef void LinkList;
typedef struct _tag_LinkListNode LinkListNode;
struct _tag_LinkListNode
{
    LinkListNode* next;   //自己的指针	（神奇的写法。没有指明类型）
};

LinkList* LinkList_Create(); //创建

void LinkList_Destroy(LinkList* list);  //销毁

void LinkList_Clear(LinkList* list);	//清空

int LinkList_Length(LinkList* list);	//长度

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);	//插入

LinkListNode* LinkList_Get(LinkList* list, int pos);	//查找

LinkListNode* LinkList_Delete(LinkList* list, int pos);		//删除

#endif
