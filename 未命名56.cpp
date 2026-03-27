//链表---查找节点与删除节点 模式选择（switch） 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
 } ;
 
 struct Node *create_n(int n)
 {
 	struct Node *head = NULL;
 	struct Node *tail = NULL;
 	
 	printf("请输入整数：\n");
 	for(int i = 0; i < n; i++)
 	{
 		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
 		if(newNode == NULL)
 		{
 			printf("内存分配失败\n");
 			exit(1);
		 }
 		scanf("%d", &newNode -> data);
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
	 return head;
 }
 
 
 struct Node *search_n(struct Node *head, int key)
 {
 	struct Node *p = head;
 	while(p != NULL)
 	{
 		if(p -> data == key)
 		{
			 return p; 
		 }
 		p = p -> next;
	 }
	 
	 return NULL;
 }
 
 struct Node *delete_n(struct Node *head, int key)
 {
 	struct Node *cur = head;
 	struct Node *prev = NULL;
 	
 	while(cur != NULL)
 	{
 		if(cur -> data == key)
 		{
 			if(prev == NULL)
 			{
 				head = cur -> next;
			 }
			 else
			 {
			 	prev -> next = cur -> next;
			 }
			 
			 free(cur);
			 return head;
		 }
		 prev = cur;
		 cur = cur -> next;
	 }
	 
	 printf("没有找到要删除的数字\n");
	 return head;
 }
 void print_n(struct Node *head)
 {
 	struct Node *p = head;
 	while(p != NULL)
 	{
 		printf("%d ", p -> data);
 		p = p -> next;
	 }
	 printf("\n");
 }
 
 int main()
 {
 	struct Node *result;
 	struct Node *head;
 	int n;
 	int value;
 	int del;
 	int mode;
 	
 	printf("请输入要录入数字的个数：\n");
	scanf("%d", &n); 
	head = create_n(n);
	printf("原链表:\n");
	print_n(head);
	
	printf("选择模式：1--查找节点，2--删除节点\n");
	scanf("%d", &mode);
	
	switch(mode)
	{
		case 1:
			printf("请输入你要寻找的整数：\n");
		 	scanf("%d", &value);
		 	result = search_n(head, value);
		 	if(result != NULL)
		 		printf("找到了节点 %d\n", result -> data);
		 	else
		 		printf("没有找到该节点\n");
		break;
		case 2:
			printf("请输入要删除的数字：\n");
		 	scanf("%d", &del);
		 	head = delete_n(head,del);
		 	printf("删除后的链表：\n");
		 	print_n(head);
		break;
		default:
			printf("error\n");
		break;
	}
	
 	return 0;
 }
