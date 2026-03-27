//编写一个函数，接收文件路径 读取文件内容，统计文件有多少行 返回行数
#include<stdio.h>

int count_lines(char *path);

int count_lines(char *path)
{
	FILE *file = fopen(path, "r");
	if(file == NULL)
	{
		printf("error\n");
		return -1;
	}
	
	char buffer[100];
	int count = 0;
	while(fgets(buffer, 100, file) != NULL)
	{
		count++;
	}
	fclose(file);
	return count;
 } 
 
 int main()
 {
 	int count = count_lines("111.txt");
 	printf("%d\n", count);
 	return 0;
 }
