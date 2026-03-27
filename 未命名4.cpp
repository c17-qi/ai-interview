#include<stdio.h>
//初始化数组时就给出成绩，计算小组每科平均分与总平均分

int main()
{
	int average1;//每科平均分
	int average2;//总平均分 
	int sum,sum1;
	int i,j; 
	int arr[5][3]{{80,75,92},{61,65,71},{59,63,70},{85,87,90},{76,77,85}};
	char arr2[3][10] = {"Math","Chinese","English"};
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 5; j++)
		{
			sum += arr[j][i];
		}
		average1 = sum / 5;
		sum1 += sum;
		sum = 0;
		
		printf("%s 科目平均分为 %d\n",arr2[i],average1);
		
	}
	average2 = sum1 / 15;
	printf("总平均分为 %d ",average2);
	
	return 0;
 } 
