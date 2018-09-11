#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"

typedef struct _tag_LinkList
{
    LinkListNode header;   //头指针，是个结构体
    int length;
} TLinkList;

LinkList* LinkList_Create() // O(1)
{
    TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));
    
    if( ret != NULL )
    {
        ret->length = 0;
        ret->header.next = NULL;
    }
    
    return ret;
}

void LinkList_Destroy(LinkList* list) // O(1)
{
    free(list);			//为什么只释放一次，因为类中没有申请空间，增加的节点是主函数里的。还是栈空间变量
}

void LinkList_Clear(LinkList* list) // O(1)
{
    TLinkList* sList = (TLinkList*)list;
    
    if( sList != NULL )
    {
        sList->length = 0;
        sList->header.next = NULL;		//内存泄漏？不会，因为节点是主函数定义的，且是栈空间变量
    }
}

int LinkList_Length(LinkList* list) // O(1)
{
    TLinkList* sList = (TLinkList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->length;
    }
    
    return ret;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos) // O(n)
{ 
    TLinkList* sList = (TLinkList*)list;
    int ret = (sList != NULL) && (pos >= 0) && (node != NULL);
    int i = 0;
    
    if( ret )
    {
        LinkListNode* current = (LinkListNode*)sList;
        
        for(i=0; (i<pos) && (current->next != NULL); i++)	//结构体强转为结构体中的第一个变量类型
        {
            current = current->next;	//current虽然是TLinkList强转的，但他是LinkListNode类型
        }
        
        node->next = current->next;
        current->next = node;
        
        sList->length++;
    }
    
    return ret;
}

LinkListNode* LinkList_Get(LinkList* list, int pos) // O(n)
{
    TLinkList* sList = (TLinkList*)list;
    LinkListNode* ret = NULL;
    int i = 0;
    
    if( (sList != NULL) && (0 <= pos) && (pos < sList->length) )
    {
        LinkListNode* current = (LinkListNode*)sList;
        
        for(i=0; i<pos && (current->next != NULL); i++)
        {
            current = current->next;
        }
        
        ret = current->next;
    }
    
    return ret;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos) // O(n)
{
    TLinkList* sList = (TLinkList*)list;
    LinkListNode* ret = NULL;
    int i = 0;
    
    if( (sList != NULL) && (0 <= pos) && (pos < sList->length) )
    {
        LinkListNode* current = (LinkListNode*)sList;
        
        for(i=0; i<pos && (current->next != NULL); i++)
        {
            current = current->next;
        }
        
        ret = current->next;
        current->next = ret->next;
        
        sList->length--;
    }
    
    return ret;
}
