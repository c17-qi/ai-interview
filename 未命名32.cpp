//向文件里写入五个数字，用fscanf读取文件中的数字，计算总和并输出结果
#include<stdio.h>

int main()
{
	FILE *file = fopen("111.txt","w+");
	if(file == NULL)
	{
		printf("error\n");
		return 1;
	}
	
	fprintf(file,"%d %d %d %d %d",10,20,30,40,50);
	rewind(file);
	
	int a,b,c,d,e;
	fscanf(file,"%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	printf("%d\n",a+b+c+d+e);
	fclose(file);
	
	return 0;
	
}
