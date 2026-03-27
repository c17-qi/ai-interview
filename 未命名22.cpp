//接受一个整数数组和数组长度
//动态创建一个新数组，其中只存放原数组中偶数元素 并返回新数组指针

#include<stdio.h>
#include<stdlib.h>

int *find_even(int *arr, int len,int *new_len);

int *find_even(int *arr, int len,int *new_len)
{
	int count = 0;
	
	if(arr == NULL || len <= 0)
		return NULL;
		
	for(int i = 0; i < len; i++)
	{
		if(arr[i] % 2 == 0)
			count++;
	}
	if(count == 0)
	{
		*new_len = 0;
		return NULL;
	}
	
	int *newarr = (int*)malloc(count * sizeof(int));
	
	int j = 0;
	for(int i = 0; i < len; i++)
	{
		if(arr[i] % 2 == 0)
		{
			newarr[j] = arr[i];
			j++;
		}
	}
	
	*new_len = count;
	return newarr;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int len = sizeof(arr) / sizeof(arr[0]);
	
	int new_len;
	int *newarr = find_even(arr, len, &new_len);
	
	if(newarr != NULL)
	{	
		for(int i = 0; i < new_len; i++)
		{
			printf("%d ", newarr[i]);
		}
		printf("\n");
		
		free(newarr);
	}
	
	return 0; 
}
