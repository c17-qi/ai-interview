//用指针找出俩个整数中较大的那一个
//接收俩个int指针作为参数 返回指向较大整数的指针
//在主函数中测试该功能，并输出较大的值
#include <stdio.h>

int *found_max(int *a,int *b);

int *found_max(int *a,int *b)
{
	if(a == NULL || b == NULL)
	return NULL;
	
	if(*a < *b)
		return b;
	else
		return a;
}

int main()
{
	int x = 8;
	int y = 10;
	int *a = &x;
	int *b = &y;

	int *max = found_max(a,b);
	printf("max = %d\n",*max);  
	return 0;
}
