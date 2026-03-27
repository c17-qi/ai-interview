//接受一个整数数组，动态创建一个新数组
//新数组中只包含在原数组中只出现一次的数字 并返回新数组指针 
#include<stdio.h>
#include<stdlib.h>

int *find_one(int *arr, int len, int *new_len);
int *find_one(int *arr, int len, int *new_len)
{
	if(arr == NULL || len <= 0)
	{
		printf("输入数组无效\n");
		*new_len = 0;
		return NULL;
	}
	//复制数组 
	int *temparr = (int *)malloc(len * sizeof(int));
	if(temparr != NULL)
	{
		for(int i = 0; i < len; i++)
			temparr[i] = arr[i];
	}
	//创建新数组 
	int *newarr = (int *)malloc(len * sizeof(int));
	if(newarr == NULL)
	{
		*new_len = 0;
		free(temparr);
		return NULL;
	}
	 //提取
	 int k = 0;
	 for(int i = 0; i < len; i++)
	 {
	 	int count = 0;
	 	for(int j = 0; j < len; j++)
	 	{
	 		if(temparr[i] == temparr[j])
	 		{
	 			count++;
			 }
		 }
		 if(count == 1) 
		 {
		 	newarr[k++] = temparr[i];
		 }
	 }
	 
	 free(temparr);
	 *new_len = k;
	 return newarr;

}

int main()
{
	int arr[] = {22,9,8,1,2,3,2,4,3,5,6,7};
	int len = sizeof(arr) / sizeof(arr[0]);
	int new_len;
	int *newarr = find_one(arr,len,&new_len);
	
	if(newarr != NULL)
	{
		for(int i = 0; i < new_len; i++)
			printf("%d ", newarr[i]);
			
		printf("\n");
		free(newarr);
	}
	return 0;
}

