#include<stdio.h>
//返回最小元素的指针

 int *find_min(int *arr, int len);
 
 int *find_min(int *arr, int len)
 {
 	if(arr == NULL || len <= 0)
 	return NULL;
 	
 	int *min = arr;
 	
 	for(int i = 0; i < len; i++)
 	{
 		if(*min > arr[i])
 			min = &arr[i];
	 }
	 
	 return min;
 	
 }
 
 int main()
{
	int arr[] = {1,2,3,4,5,6};
	int len = sizeof(arr) / sizeof(arr[0]);
	int *p = find_min(arr,len);
	
	if (p != NULL)
	printf("min = %d\n",*p);
	
	return 0;
}
