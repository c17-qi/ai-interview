//递归函数计算斐波那契数列第n项

#include<stdio.h>

int fibonacci(int n);

int fibonacci(int n)
{
	if(n == 0 || n == 1)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
 } 
 
 int main()
 { 
 	int n;
 	printf("请输入一个数字:\n");
 	scanf("%d", &n);
 	
 	int num = fibonacci(n);
 	printf("斐波那契数列第 %d 项 = %d\n", n, num);
 	return 0;
 }
