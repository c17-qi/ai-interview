//用户输入三个名字 写入文件 再从文件读取并打印 
#include<stdio.h>

int main()
{
	FILE *file = fopen("111.txt","w+");
	if(file == NULL) 
	{
		printf("error\n");
		return 1;
	}
	char name[100];
	
	printf("请输入三个名字");
	for(int i = 0; i < 3; i++)
	{
		scanf("%s",name);
		fprintf(file, "%s\n", name);
	}
	
	rewind(file);
	while(fgets(name, 100, file) != NULL)
	{
		printf("%s", name);
	}
	fclose(file);
	return 0;
}

