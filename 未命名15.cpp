//编写一个函数，接收俩个整数指针作为参数
//并交换这俩个指针所指向的整数值，确保在主函数中测试此功能 

#include<stdio.h>

void change(int *a,int *b);
void change(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x = 8;
	int y = 10;
	int *a = &x;
	int *b = &y;
	
	
	change(a,b);
	printf("a = %d\nb = %d\n",*a,*b);
	return 0;
}
