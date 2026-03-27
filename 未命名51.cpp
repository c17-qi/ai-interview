//尾插法创建链表 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void print_n(struct Node *head)
{
	struct Node *p = head;
	while(p != NULL)
	{
		printf("%d ", p -> data);
		p =  p -> next;
	}
	printf("\n");
}

int main()
{
	struct Node *tail = NULL;
	struct Node *head = NULL;
	int value;
	
	printf("请输入五个整数\n");
	for(int i = 0; i < 5; i ++)
	{
		scanf("%d", &value);
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		if(newNode == NULL)
		{
			printf("内存存储失败\n");
			exit(1);
		}
		
		newNode -> data = value;
		newNode -> next = NULL;
		
		if(head == NULL)//第一次插入 
		{
			head = newNode;
			tail = newNode;
		}
		else//之后的插入
		{
			tail -> next = newNode;
			tail = newNode;
		 } 
	}
	
	print_n(head);
	return 0;
}
