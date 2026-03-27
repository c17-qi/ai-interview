//把一个文件的内容复制到另一个文件 
//fgetc的使用

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
		fputc(ch, dest);
	 } 
	 
	 fclose(src);
	 fclose(dest);
	 
	 return 0;
}
 
