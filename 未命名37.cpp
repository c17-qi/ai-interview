//编写一个函数接收文件路径和一个字符 
//打开文件统计该字符在文件中出现的次数
//返回出现次数，如果文件打不开返回-1 
#include<stdio.h>

int count_char(char *path, char ch);

int count_char(char *path, char ch)
{
	FILE *file = fopen(path,"r");
	if(file == NULL)
	{
		printf("error\n");
		return -1;
	}
	
	int count = 0;
	char buffer[100];
	while(fgets(buffer, 100, file) != NULL)
	{
		for(int i = 0; buffer[i] != '\0'; i++)
		{
			if(buffer[i] == ch)
				count++;
		}
	}
	fclose(file);
	return count;
}

int main()
{
	char ch;
	printf("请输入一个字符\n");
	scanf("%c", &ch);
	
	int count = count_char("111.txt",ch);
	if(count >= 0)
	{
		printf("%d", count);
	}
	
	return 0;
}
