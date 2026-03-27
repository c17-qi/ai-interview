//输入一个长度为6的数组 使用插入排序将数组从小到大排序

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *arr = (int *)malloc(100 * sizeof(int));
	int len = 0;
	int num;
	printf("请输入数字,输入回车结束：\n");
	
	while(1)
	{
		scanf("%d", &num);
		if(num < 0)
			break;
		arr[len] = num;
		len++;
	}
	
	for(int i = 1; i < len; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		
		arr[j + 1] = temp;
	}
	
	for(int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
 } 
