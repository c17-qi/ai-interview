//插入排序

#include<stdio.h>

int main()
{
	int arr[] = {9, 3, 5, 1, 8};
	int len = sizeof(arr) / sizeof(arr[0]);
	
	for(int i = 1; i < len; i++)//从1开始，默认第0个数已经排好序 
	{
		int temp = arr[i];//保存要插入的数字 
		int j = i - 1;
		
		while(j >= 0 && arr[j] > temp)//不断向前比较 
		{
			arr[j + 1] = arr[j];
			j--;
		}
		
		arr[j + 1] = temp;//因为j--跳出后相当于循环结束 则应该把值放j+1里 
	}
	
	for(int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
	
 } 
