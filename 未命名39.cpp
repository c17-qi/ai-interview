//读取一个文件 把所有小写字母变成大写 再写入另一个文件
#include<stdio.h>

int main()
{
	FILE *src = fopen("111.txt", "r");
	FILE *dest = fopen("copy.txt", "w");
	if(src == NULL || dest == NULL)
	{
		printf("error\n");
		return -1;
	}
	
	char ch;
	while((ch = fgetc(src)) != EOF)
	{
		if(ch >= 'a' && ch <= 'z')
		{
			ch = ch - 32;
		}
		
		fputc(ch, dest);
	}
	
	fclose(src);
	fclose(dest);
	
	return 0;
 } 
