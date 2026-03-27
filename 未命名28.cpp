// 写入文件并读取打开文件 
#include<stdio.h>

int main()
{
	FILE *file = fopen("111.txt","w+");
	if(file == NULL)
	{
		printf("打开失败\n");
		return 1;
	}
	
	fprintf(file, "你好\n");
	fprintf(file, "12345\n");
	
	rewind(file); //把指针移回文件开头  
	
	char buffer[100];
	while(fgets(buffer,100,file) != NULL)
	{
		printf("%s ", buffer);
	}
	
	fclose(file);
	return 0;
}
