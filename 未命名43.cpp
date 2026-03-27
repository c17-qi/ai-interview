//递归算法计算阶乘

#include<stdio.h>

int factorial(int n);

int factorial(int n)
{
	if(n == 1)//结束条件
		return 1;
	else
		return n* factorial(n - 1);
 } 
 
 int main()
 {
 	int n;
 	printf("请输入一个正整数\n");
 	scanf("%d", &n);
 	
 	printf("%d! = %d\n", n, factorial(n));
 	
 	return 0;
  } 
