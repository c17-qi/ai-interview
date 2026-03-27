//让用户输入五个整数写入文件
//再从文件循环读取 计算总和与平均值并输出

#include<stdio.h>

int main()
{
	FILE *file = fopen("111.txt","w+");
	if(file == NULL)
	{
		printf("error\n");
		return 1;
	}
	
	int num;
	printf("请输入五个整数\n");
	
	for(int i = 0; i < 5; i++)
	{
		scanf("%d", &num);
		fprintf(file, "%d ", num);	
	}
	
	rewind(file);
	
	int sum = 0;
	int avg = 0;
	for(int i = 0; i < 5; i++)
	{
		fscanf(file, "%d", &num);
		sum += num;
	}
	
	avg = sum / 5;
	printf("%d %d\n", sum, avg);
	
	fclose(file);
	return 0;
 } 
 
