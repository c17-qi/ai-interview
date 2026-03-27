//接收一个整数数组和数组长度，找出数组中出现次数最多的数字
//返回这个数字 如果数组无效则返回-1；
#include<stdio.h>
#include<stdlib.h>

int find_most(int *arr,int len);

int find_most(int *arr,int len)
{
	if(arr == NULL || len <= 0)
	{
		printf("error\n");
		return -1;
	}
	//复制
	int *temparr = (int *)malloc(len * sizeof(int));
	if (temparr == NULL)
		return -1; 
	
		for(int i = 0; i < len; i++)
		{
			temparr[i] = arr[i];
		}
	  
	 //排序
	 for(int i = 0; i < len; i++)
	 {
	 	for(int j = i+1; j < len; j++)
	 	{
	 		if(temparr[i] < temparr[j])
	 		{
	 			int temp = temparr[i];
	 			temparr[i] = temparr[j];
	 			temparr[j] = temp;
			 }
		 }
	  } 
	//寻找
	int max_num = temparr[0];
	int count = 1;
	int max_count = 1;
	
	for(int i = 1; i < len; i++)
	{
		if(temparr[i] == temparr[i-1])
		{
			count++;
		}
		else
		{
			if(count > max_count)
			{
				max_count = count;
				max_num = temparr[i-1];
			}
			count = 1;
		}
	}
	
	if(count > max_count)
	{
		max_num = temparr[len-1];
	}
	free(temparr);
	return max_num;
		
}

int main()
{
	int arr[] = {1,2,2,3,3,4,5,3};
	int len = sizeof(arr) / sizeof(arr[0]);
	
	int most_number = find_most(arr,len);
	if(most_number != -1)
		printf("%d ", most_number);
	return 0;
}
