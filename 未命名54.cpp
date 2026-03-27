//链表逆序

#include<stdio.h>
#include<stdlib.h>

 struct Node
 {
 	int data;
 	struct Node *next;
 };
 
 //链表逆序函数 
 struct Node *reverse_n(struct Node *head)
 {
 	struct Node *prev = NULL;
 	struct Node *cur = head;
 	struct Node *next = NULL;
 	
 	while(cur != NULL)
 	{
 		next = cur -> next;// 存next 
 		cur -> next = prev;//反转 把 1 的next改成prev 
 		prev = cur;// prev前进
 		cur = next;//cur前进
	 }
	 
	 return prev;
 }
 
 //尾插法创建链表
 struct Node *create_n(int n)
 {
 	struct Node * head = NULL;
 	struct Node * tail = NULL;
 	
 	printf("输入数字：\n");
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
 		if(head ==NULL)
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
  
  //打印链表 
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
  	struct Node *head;
  	
  	head = create_n(5);
  	printf("原链表：\n");
  	print_n(head);
  	
  	head = reverse_n(head);
  	printf("逆序后链表：\n");
  	print_n(head);
  	
  	return 0;
  }
  
  
  
