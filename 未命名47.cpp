//递归计算数组元素之和

#include<stdio.h>

int sum_n(int *arr, int n);

int sum_n(int *arr, int n)
{
	if(n == 0)
		return 0;
	return *arr + sum_n(arr + 1, n - 1);
 } 
 
 int main()
 {
 	int n;
 	int arr[] = {1,2,3,4,5,6};
 	int len = sizeof(arr) / sizeof(arr[0]);
 	
 	printf("请输入一个n值\n");
 	scanf("%d", &n);
 	if(n > len)
 		n = len;
 	
 	int sum = sum_n(arr, n);
 	printf("数组前 %d 个元素之和 = %d\n", n, sum);
 	
 	return 0;
 }
