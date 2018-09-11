//#include <stdio.h>
#include <stdlib.h>


int printf(const char *format, ...);


typedef int T;  //声明数据元素类型

//声明链表节点类型
typedef struct _Node
{
	T data;  //数据域
	struct _Node* next;  //指针域
} Node;


//创建一个空链表
Node* create(void)
{
	Node* node = malloc(sizeof(Node));
	node->next = NULL;
	return node;
}

//销毁链表
void destroy(Node* head)
{
	Node* p = NULL;

	while(head != NULL)	
	{
		p = head->next;
		free(head);
		head = p;
	}
}

//增加节点
void push_back(Node* head, T data)  //尾部插入
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	while(head->next != NULL)
	{
		head = head->next;
	}

	head->next = node;
}

void push_front(Node* head, T data)  //头部插入
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = head->next;

	head->next = node;	
}

void insert(Node* head, int pos, T data)  //中间插入
{
	if(pos < 0) pos = 0;

	while(pos--)
	{
		if(head->next == NULL) break;
		head = head->next;
	}

	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = head->next;

	head->next = node;
}

//删除节点
int remove(Node* head, T data)
{
	while(head->next != NULL && head->next->data != data)
	{
		head = head->next;
	}

	if(head->next == NULL)
		return 0;

	Node* p = head->next;
	head->next = head->next->next;
	free(p);

	return 1;
}

//清空链表
void clear(Node* head)
{
	Node* p = NULL;

	p = head->next;
	head->next = NULL;
	head = p;

	while(head != NULL)	
	{
		p = head->next;
		free(head);
		head = p;
	}	
}


//修改节点数据
int update(Node* head, T old, T new)
{
	head = head->next;

	while(head != NULL)
	{
		if(head->data == old)
			break;
	
		head = head->next;
	}

	if(head == NULL) return 0;
	head->data = new;
	return 1;
}

//查找某个数据
T* find(Node* head, T data)
{
	head = head->next;
	while(head != NULL && head->data != data)
	{
		head = head->next;
	}

	if(head == NULL) return NULL;
	return &(head->data);
}

//排序

//逆序


//判空
int empty(Node* head)
{
	return !(head->next);
}

//获取链表长度
int size(Node* head)
{
	int cnt = 0;

	while(head->next != NULL)
	{
		++cnt;
		head = head->next;
	}

	return cnt;
}

//遍历所有节点
void traverse(Node* head, int(*visit)(T* data))
{
	head = head->next;

	while(head != NULL)
	{
		if(!visit(&(head->data)))
			break;
		
		head = head->next;
	}
}


int show(int* data)
{
	static int cnt = 0;
	cnt++;

	printf("%d ", *data);

	//if(cnt == 2) return 0;
	return 1;
}

int change(int* data)
{
	(*data)++;
}


int main()
{
	Node* list1 = NULL;
	Node* scores = NULL;

	list1 = create();
	scores = create();

	push_back(scores, 98);	
	push_back(scores, 89);	
	push_back(scores, 65);	

	traverse(scores, show);
	printf("\n");

	push_back(list1, 100);	
	push_back(list1, 300);
	push_front(list1, 600);	
	push_front(list1, 500);
	push_front(list1, 500);
	push_front(list1, 500);
	push_front(list1, 500);
	insert(list1, 2, 800);

	if(!remove(list1, 5))
	{
		printf("删除失败！\n");
	}

	remove(list1, 800);
	remove(list1, 100);

	//traverse(list1, change);
	
	clear(list1);
	
	while(update(list1, 500, 1000));

	printf("%d\n", size(list1));

	traverse(list1, show);
	printf("\n");

	destroy(list1);

	


	return 0;
}
