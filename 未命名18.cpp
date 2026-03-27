//编写一个函数 接收一个整数参数
//并使用递归来计算该整数的斐波那契数列值 确保处理无效输入的情况如负数 

#include<stdio.h>

int fibonacci(int n);

int fibonacci(int n)
{
	if(n < 0) 
	{
		printf("no data!\n");
		return -1;
	}
	if(n == 0 || n == 1) return n;
	
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int n,x;
	
	printf("请输入一个数值\n");
	scanf("%d",&n);
	
	x = fibonacci(n);
	
	if(x != -1)
		printf("斐波那契数列第 %d 项值 = %d\n",n,x);
	return 0;
}
