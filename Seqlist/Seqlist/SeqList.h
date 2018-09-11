/*
*线性表的顺序存储结构
*/

#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList;		//用于主函数调用，实现泛型
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);//创建 

void SeqList_Destroy(SeqList* list);//销毁 

void SeqList_Clear(SeqList* list);//清空 

int SeqList_Length(SeqList* list);//测量表长 

int SeqList_Capacity(SeqList* list);//测量容量 

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);//插入 

SeqListNode* SeqList_Get(SeqList* list, int pos);//查找 

SeqListNode* SeqList_Delete(SeqList* list, int pos);//删除 

#endif

