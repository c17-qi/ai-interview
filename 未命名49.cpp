//创建链表（头插法）

#include<stdio.h>
#include<stdlib.h>

//先定义节点 
struct Node
{
	int data;
	struct Node *next;
 };
 
 struct Node *insertHead(struct Node *head, int value)
 {
 	struct Node *newNode;
 	
 	newNode = (struct Node *)malloc(sizeof(struct Node));
 	if(newNode == NULL)
  	{
  		printf("内存分配失败\n");
  		exit(1);
	  }
 	newNode -> data = value;
 	newNode -> next = head;
 	head = newNode;
 	return head;
 }
 
 void printList(struct Node *head)
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
 	struct Node *head = NULL;
 	
 	head = insertHead(head,1);
	head = insertHead(head,2);
   	head = insertHead(head,3);
  	head = insertHead(head,4);
  	
  	printList(head);
  	return 0;
 }
