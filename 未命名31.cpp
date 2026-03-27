//fscanfµÄÊ¹ÓÃ
#include<stdio.h>

int main()
{
	FILE *file = fopen("111.txt","r");
	if(file == NULL)
	{
		printf("error\n");
		return 1;
	}
	
	char name[100];
	
	while(fscanf(file, "%s", name) != EOF)
	{
		printf("%s\n", name);
	}
	
	fclose(file);
	return 0;
 } 
