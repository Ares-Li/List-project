#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Value
{
    LinkListNode header;
    int v;
};
struct Value2
{
	LinkListNode header;
	char v;
};

int main(int argc, char *argv[]) 
{
    int i = 0;
    LinkList* list = LinkList_Create();
    
    struct Value v1;
    struct Value v2;
    struct Value v3;
    struct Value v4;
    struct Value v5;

	struct Value2 v6;

    v1.v = 65;
    v2.v = 66;
    v3.v = 67;
    v4.v = 68;
    v5.v = 69;

	v6.v = 'a';
	//printf("%d\n",v6.v);
    
    LinkList_Insert(list, (LinkListNode*)&v1, LinkList_Length(list)); //为什么可以把struct转为LinkListNode
    LinkList_Insert(list, (LinkListNode*)&v2, LinkList_Length(list)); //应该是第一个属性的类型
    LinkList_Insert(list, (LinkListNode*)&v3, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode*)&v4, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode*)&v5, LinkList_Length(list)); //插入结尾

	LinkList_Insert(list, (LinkListNode*)&v6, LinkList_Length(list)); //插入结尾
    
    for(i=0; i<LinkList_Length(list); i++)
    {
        struct Value2* pv = (struct Value2*)LinkList_Get(list, i);	//char的
        
        printf("%d\t", pv->v);
		printf("%c\n", pv->v);
    }
    
    while( LinkList_Length(list) > 0 )
    {
        struct Value* pv = (struct Value*)LinkList_Delete(list, 0);
        
        printf("%d\n", pv->v);
    }
    
    LinkList_Destroy(list);
    
	system("pause");
    return 0;
}
