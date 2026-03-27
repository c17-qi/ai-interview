#include<stdio.h>
//初始化数组 把1-10放入数组中
 
int main()
{
	int arr[10];
	int i;
	
	printf("输入十个数字放入数组中\n");
	
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
