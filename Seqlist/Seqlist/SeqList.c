#include <stdio.h>
#include <malloc.h>
#include "SeqList.h"

typedef unsigned int TSeqListNode;

typedef struct _tag_SeqList
{
    int capacity;		//容量
    int length;			//长度
    TSeqListNode* node;
} TSeqList;

SeqList* SeqList_Create(int capacity) //O(1) 参数是链表待申请长度空间
{
    TSeqList* ret = NULL;		//创建一个链表头指针
    
    if( capacity >= 0 )
    {
        ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * capacity);
    }
    
    if( ret != NULL )
    {
        ret->capacity = capacity;
        ret->length = 0;
        ret->node = (TSeqListNode*)(ret + 1);  //下个节点的位置是头指针下个单位空间地址（连续的）
    }
    
    return ret;   //默认转换了
}

void SeqList_Destroy(SeqList* list) //O(1) 销毁链表
{
    free(list);			//只销毁一次头指针即可
}

void SeqList_Clear(SeqList* list) //O(1) 清空
{
    TSeqList* sList = (TSeqList*)list;
    
    if( sList != NULL )
    {
        sList->length = 0;		//长度设为0，但是空间还在
    }
}

int SeqList_Length(SeqList* list) //O(1) 测量表长
{
    TSeqList* sList = (TSeqList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->length;
    }
    
    return ret;		//表头中有length变量
}

int SeqList_Capacity(SeqList* list) //O(1) 测量容量 
{
    TSeqList* sList = (TSeqList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->capacity;
    }
    
    return ret;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos) // O(n)  将结点插入到第pos的结点 
{
    TSeqList* sList = (TSeqList*)list;              //强制转化成主函数所需的类型 
    int ret = (sList != NULL);                       //判断链表是否为空 
    int i = 0;
    
    ret = ret && (sList->length + 1 <= sList->capacity);    //判断链表 +1是否超出限定最大值 
    ret = ret && (0 <= pos);                                //判断插入的位置是否大于0 
     
    if( ret )                                            
    {
        if( pos >= sList->length )
        {
            pos = sList->length;		//最多添加在末尾，中间不能有空
        }
        
        for(i=sList->length; i>pos; i--)
        {
            sList->node[i] = sList->node[i-1];		//数据后移
        }
        
        sList->node[i] = (TSeqListNode)node;//没*也可以，估计是强转了
        
        sList->length++;
    }
    
    return ret;
}

SeqListNode* SeqList_Get(SeqList* list, int pos) // O(1) 查找节点位置，返回数据值
{
    TSeqList* sList = (TSeqList*)list;
    SeqListNode* ret = NULL;
    
    if( (sList != NULL) && (0 <= pos) && (pos < sList->length) )
    {
        ret = (SeqListNode*)(sList->node[pos]);
    }
    
    return ret;			//返回的是头文件定义的空类型
}

SeqListNode* SeqList_Delete(SeqList* list, int pos) // O(n) 删除节点，返回值
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
