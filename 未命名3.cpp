#include<stdio.h>
//求小组各科平均分与总平均分

int main()
{
	int arr[5][3];
	char arr2[3][10] = {"Math","Chinese","English"};
	int sum = 0;
	int sum1 = 0;
	int average1,average2;
	int i,j;
	
	for(i = 0; i < 3; i++)
	{
		printf("请输入 %s 考试成绩\n",arr2[i]);
		 
		for(j = 0; j < 5; j++)
		{	
		
			scanf("%d", &arr[j][i]);
			sum += arr[j][i];
		}
		
		average1 = sum / 5;//小组各科平均分 
		sum1 += sum;
		sum = 0;
		
		printf("小组 %s 平均分为 %d\n", arr2[i],average1);
		
	}
	
	average2 = sum1 /15;
	printf("小组总平均分为 %d\n", average2);
		
	return 0;
 } 
