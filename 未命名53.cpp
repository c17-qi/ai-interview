//用尾插法创建链表（输入n个数）
//遍历链表打印奇数节点的值并输出其数量

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

int print_n(struct Node *head)
{
	struct Node *p = head;
	int count = 0;
	while(p != NULL)
	{
		if((p -> data) % 2 != 0)
		{
			printf("%d ", p -> data);
			count ++;	
		}			
		p = p -> next;
	}
	printf("\n");
	return count;
	
 } 
 
 int main()
 {
 	struct Node *head = NULL;
 	struct Node *tail = NULL;
 	int n, value; 
 	
	printf("请输入要录入数字的个数：\n");
	scanf("%d", &n); 
	
	printf("请输入一个整数：\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &value);
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	 	if(newNode == NULL)
	 	{
	 		printf("内存分配失败\n");
	 		exit(1);
		 }
		 
		 newNode -> data = value;
		 newNode -> next = NULL;
		 
		 if(head == NULL)
		 {
		 	head = newNode;
		 	tail = newNode;
		 }
		 else
		 {
		 	tail -> next = newNode;
		 	tail = newNode;
		 }
	}
	int count = print_n(head);
	printf("奇数节点数量 = %d\n", count);
	printf("\n");
	
 }
