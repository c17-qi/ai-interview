//输入五个整数，使用头插法创建链表
 
 #include<stdio.h>
 #include<stdlib.h>
 
 struct Node
 {
 	int data;
 	struct Node *next;
  } ;
  
  struct Node *inserthead(struct Node *head, int value)
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
  
  void print_n(struct Node *head)
  {
  	struct Node *p = head;
  	
  	while(p != NULL)
  	{
  		printf("%d ", p -> data);
  		p =	p -> next;
	  }
	  
	  printf("\n");
  }
  
  int main()
  {
  	struct Node *head = NULL;
  	int value;
  	
  	printf("请输入五个整数\n");
  	for(int i = 0; i < 5; i++)
  	{
  		scanf("%d", &value);
  	  	head = inserthead(head, value);
	  }
	  print_n(head);
	  return 0;
  }
