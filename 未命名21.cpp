//接受一个整数数组及其长度作为参数，动态分配一个新的数组
//该数组包含原数组元素的平方，并返回新数组的指针
//确保处理可能为空的输入数组的情况

#include<stdio.h>
#include<stdlib.h>

int *square(int *arr,int len);

int *square(int *arr,int len)
{
	if(arr == NULL || len == 0)
		return 0;
		
	int *newarr = (int*)malloc(len * sizeof(int));
	if(newarr != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			newarr[i] = arr[i] * arr[i];
		}
	}
	
	return newarr;
 } 
 
 int main()
 {
 	int arr[] = {1,2,3,4,5};
 	int len = sizeof(arr) / sizeof(arr[0]);
 	int *squared = square(arr,len);
 	
 	if(squared != NULL)
 	{
 		for(int i = 0; i < len; i++)
 		{
 			printf("%d ", squared[i]);
		 }
		 free(squared);
	 }
	 return 0;
	 
 }
