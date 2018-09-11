#include <stdio.h>
#include <malloc.h>
#include "SeqList.h"

typedef unsigned int TSeqListNode;

typedef struct _tag_SeqList
{
    int capacity;		//����
    int length;			//����
    TSeqListNode* node;
} TSeqList;

SeqList* SeqList_Create(int capacity) //O(1) ��������������볤�ȿռ�
{
    TSeqList* ret = NULL;		//����һ������ͷָ��
    
    if( capacity >= 0 )
    {
        ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * capacity);
    }
    
    if( ret != NULL )
    {
        ret->capacity = capacity;
        ret->length = 0;
        ret->node = (TSeqListNode*)(ret + 1);  //�¸��ڵ��λ����ͷָ���¸���λ�ռ��ַ�������ģ�
    }
    
    return ret;   //Ĭ��ת����
}

void SeqList_Destroy(SeqList* list) //O(1) ��������
{
    free(list);			//ֻ����һ��ͷָ�뼴��
}

void SeqList_Clear(SeqList* list) //O(1) ���
{
    TSeqList* sList = (TSeqList*)list;
    
    if( sList != NULL )
    {
        sList->length = 0;		//������Ϊ0�����ǿռ仹��
    }
}

int SeqList_Length(SeqList* list) //O(1) ������
{
    TSeqList* sList = (TSeqList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->length;
    }
    
    return ret;		//��ͷ����length����
}

int SeqList_Capacity(SeqList* list) //O(1) �������� 
{
    TSeqList* sList = (TSeqList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->capacity;
    }
    
    return ret;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos) // O(n)  �������뵽��pos�Ľ�� 
{
    TSeqList* sList = (TSeqList*)list;              //ǿ��ת������������������� 
    int ret = (sList != NULL);                       //�ж������Ƿ�Ϊ�� 
    int i = 0;
    
    ret = ret && (sList->length + 1 <= sList->capacity);    //�ж����� +1�Ƿ񳬳��޶����ֵ 
    ret = ret && (0 <= pos);                                //�жϲ����λ���Ƿ����0 
     
    if( ret )                                            
    {
        if( pos >= sList->length )
        {
            pos = sList->length;		//��������ĩβ���м䲻���п�
        }
        
        for(i=sList->length; i>pos; i--)
        {
            sList->node[i] = sList->node[i-1];		//���ݺ���
        }
        
        sList->node[i] = (TSeqListNode)node;//û*Ҳ���ԣ�������ǿת��
        
        sList->length++;
    }
    
    return ret;
}

SeqListNode* SeqList_Get(SeqList* list, int pos) // O(1) ���ҽڵ�λ�ã���������ֵ
{
    TSeqList* sList = (TSeqList*)list;
    SeqListNode* ret = NULL;
    
    if( (sList != NULL) && (0 <= pos) && (pos < sList->length) )
    {
        ret = (SeqListNode*)(sList->node[pos]);
    }
    
    return ret;			//���ص���ͷ�ļ�����Ŀ�����
}

SeqListNode* SeqList_Delete(SeqList* list, int pos) // O(n) ɾ���ڵ㣬����ֵ
{
    TSeqList* sList = (TSeqList*)list;
    SeqListNode* ret = SeqList_Get(list, pos);
    int i = 0;
    
    if( ret != NULL )
    {
        for(i=pos+1; i<sList->length; i++)
        {
            sList->node[i-1] = sList->node[i];
        }
        
        sList->length--;
    }
    
    return ret;
}
