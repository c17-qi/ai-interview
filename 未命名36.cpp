//编写一个函数接收文件路径作为参数，打开指定文件如果无法打开就返回-1
//读取文件内容，统计文件中总共出现了多少个单词并返回单词数

#include<stdio.h>

int count_words(char *path);

int count_words(char *path)
{
	FILE *file = fopen(path, "r");
	if(file == NULL)
	{
		printf("error\n");
		return -1;
	}
	int count =0;
	char buffer[100];
	int in_word =0;//0 = 不在单词里 1 = 在单词里 
	
	while(fgets(buffer, 100, file) != NULL)
	{
		for(int i = 0; buffer[i] != '\0'; i++)
		{
			if(buffer[i] != ' ' && in_word == 0)
			{
				count++;
				in_word = 1;
			 } 
			 
			 if(buffer[i] == ' ' || buffer[i] == '\n')
				 in_word = 0;
				
		}
			
		
	}
	fclose(file);
	return count;
 } 
 
 int main()
 {
 	int count = count_words("111.txt");
 	printf("%d", count);
 	return 0;
 }
