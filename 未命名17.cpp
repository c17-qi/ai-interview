//用指针找出数组中的第一个偶数，并返回指向它的指针
//使用指针遍历数组若数组为空或不存在偶数返回NULL
//在主函数中测试并输出结果
#include<stdio.h>

int *find_first_even(int *arr,int len); 

int *find_first_even(int *arr,int len)
{
	if(arr == NULL || len <= 0)
		return NULL;
	
	for(int *p = arr; p < arr + len; p++)
	{
		if(*p % 2 == 0)
		{
			return p;
		}	
	}
	
	return NULL;
	
}

int main()
{
	int arr[] = {1,3,5,7};
	int len = sizeof(arr) / sizeof(arr[0]);
	
	int *first = find_first_even(arr,len);
	
	if(first != NULL)
		printf("first even = %d\n",*first);
	else
		printf("no data");
		
	return 0;
}
