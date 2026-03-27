//让用户输入一个名字 把名字写入文件 再从文件读出来并显示
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
	printf("请输入一个名字");
	scanf("%s", &name);
	
	fprintf(file, "%s",name);
	rewind(file);
	
	while(fgets(name,100,file))
	{
		printf("%s\n",name);
	}
	fclose(file);
	return 0;
	
 } 
