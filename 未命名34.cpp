//编写一个函数，接收一个文件路径作为参数，读取该文件中的所有行
//并打印到标准输出，确保处理可能无法打开文件或文件为空的情况

#include<stdio.h>

void printf_file(char *path);
void printf_file(char *path)
{
	FILE *file = fopen(path,"r");
	if(file == NULL)
	{
		printf("error\n");
		return;
	}
	
	char buffer[100];
	while(fgets(buffer, 100, file) != NULL)
	{
		printf("%s", buffer);
	}
	fclose(file);
}
	
int main()
{
	printf_file("111.txt");
	return 0;
}
