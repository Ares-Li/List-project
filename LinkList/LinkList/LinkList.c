#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"

typedef struct _tag_LinkList
{
    LinkListNode header;   //ͷָ�룬�Ǹ��ṹ��
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
    free(list);			//Ϊʲôֻ�ͷ�һ�Σ���Ϊ����û������ռ䣬���ӵĽڵ�����������ġ�����ջ�ռ����
}

void LinkList_Clear(LinkList* list) // O(1)
{
    TLinkList* sList = (TLinkList*)list;
    
    if( sList != NULL )
    {
        sList->length = 0;
        sList->header.next = NULL;		//�ڴ�й©�����ᣬ��Ϊ�ڵ�������������ģ�����ջ�ռ����
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
        
        for(i=0; (i<pos) && (current->next != NULL); i++)	//�ṹ��ǿתΪ�ṹ���еĵ�һ����������
        {
            current = current->next;	//current��Ȼ��TLinkListǿת�ģ�������LinkListNode����
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
