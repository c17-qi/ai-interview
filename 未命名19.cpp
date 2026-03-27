//写一个递归函数 计算前n项斐波那契数列的总和

#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n);
int sum_fib(int n);
 
int fibonacci(int n)
{
	if(n < 0) 
		return -1;
	if(n == 0 || n == 1)
		return n;
		
	return fibonacci(n-1) + fibonacci(n-2);	
 } 
 
int sum_fib(int n)
{
	if(n < 0) 
		return -1;
	if(n == 0)
		return fibonacci(0);
	return fibonacci(n) + sum_fib(n-1);
}

int main()
{
	int n;
	int result;
	int *arr;
	
	while(1)
	{
		printf("请输入n:\n");
		scanf("%d",&n);
		
		if(n == -1)
			break;
		
		arr = (int*)malloc((n+1) * sizeof(int));
		
		for(int i = 0; i < n; i++)
		{
			arr[i] = fibonacci(i);
		}
		
		for(int i = 0; i < n; i++)
		{
			printf("%d ",arr[i]);
		}
		
		printf("\n");
		
		result = sum_fib(n);
		
		if(result != -1)
			printf("前 %d 项斐波那契数列和 = %d\n",n,result);
		else
			printf("输入非法\n");
		free(arr);	
	}
	

	return 0;
}
