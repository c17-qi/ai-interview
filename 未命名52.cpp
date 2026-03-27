//尾插法创建链表并统计
//用户输入需要录入的n个数字个数，再输入n个整数 使用尾插法创建链表
//打印链表内容并计算输出链表中所有数字的和

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
	int sum = 0;
	while(p != NULL)
	{
		printf("%d ", p -> data);
		sum += p -> data;
		p = p -> next;

	}
	printf("\n");
	return sum;
}

int main()
{
	struct Node *head = NULL;
	struct Node *tail = NULL;
	int n;
	int value;
	
	printf("请输入你要录入的数字个数：\n");
	scanf("%d", &n);
	
	printf("请输入整数\n");
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
	int sum = print_n(head);
	printf("数字和 = %d\n", sum);
	return 0;
 } 
