//选择排序

#include<stdio.h>

int main()
{
	int arr[] = {7, 4, 6, 2, 1};
	int len = sizeof(arr) / sizeof(arr[0]);
	int min;
	
	for(int i = 0; i < len - 1; i++) //比较len-1轮 
	{
		min = i;
		for(int j = i + 1; j < len; j++)//在当下一轮中寻找最小值 
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		
		if(min != i)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		
	}
	
	for(int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0; 
 } 
