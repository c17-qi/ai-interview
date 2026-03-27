#include<stdio.h>

void compute(int *arr,int len);

void compute(int *arr,int len)
{
	if(arr == NULL || len <= 0)
	return;
	
	for(int *p = arr; p < arr + len; p++)
	{
		*p *= 2;
	}
}

int main()
{
	int arr[] = {7,2,3,4,5,6};
	int len = sizeof(arr) / sizeof(arr[0]);
	compute(arr,len);
	
	for(int i = 0; i < len; i++)
	{
		printf("%d ",arr[i]);
	}
	
	return 0;
}
