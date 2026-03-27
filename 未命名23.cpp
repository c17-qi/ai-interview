//接收一个整数数组和数组长度 动态创建一个新数组 
//删除原数组中所有重复元素并返回新数组 

#include<stdio.h>
#include<stdlib.h>

int *delete_arr(int *arr,int len,int *new_len);

int *delete_arr(int *arr,int len,int *new_len)
{
	if(arr == 0 || len <= 0)//检查输入数组是否为空 
	{
		printf("输入数组为空\n");
		*new_len = 0;
		return NULL;
	}
	
	int temp = 0;
	int k = 0;
	
	//复制原数组 
	int *temp_arr = (int *)malloc(len * sizeof(int));
	if(temp_arr == NULL)
	{
		*new_len = 0;
		return NULL;
	}
	for(int i = 0; i < len; i++)
		temp_arr[i] = arr[i];
		
	//排序
	for(int i = 0; i < len; i++)
	{
		for(int j = i+1; j < len ; j++)
		{
			if(temp_arr[i] > temp_arr[j])
			{
				temp = temp_arr[i];
				temp_arr[i] = temp_arr[j];
				temp_arr[j] = temp;
			}
		}
	}
	
	//创建新数组
	int *newarr = (int *)malloc(len * sizeof(int));
	if(newarr == NULL)
	{
		free(temp_arr);
		*new_len = 0;
		return NULL;
	}
	
	//去重
	 newarr[k++] = temp_arr[0];
	 
	 for(int i = 1; i < len; i++)
	 {
	 	if(temp_arr[i] != temp_arr[i-1])
	 		newarr[k++] = temp_arr[i];
	 }
	 
	 *new_len = k;
	 
	 free(temp_arr);
	 return newarr;
}

int main()
{
	int arr[] = {4,2,5,6,7,4,3,2,1,2};
	int len = sizeof(arr) / sizeof(arr[0]);
	int new_len;
	int *newarr = delete_arr(arr, len, &new_len);
	
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











