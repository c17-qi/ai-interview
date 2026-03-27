#include<stdio.h>
//判断输入为奇数 
int main()
{
	int start,end,i;
	
	while(1)
	{
		printf("请输入 start 和 end\n"); 
		scanf("%d %d", &start, &end);
		
		if(start < 0 || end < 0 || start > end)
		printf("error\n");
		
		if(start == 0 && end == 0)
		break;
		
		//for(i = start; i < end; i++)
		//{
		//	if(start % 2 == 1)
		//	printf("%d ",start);
		//	
		//	start++;
		
		while(start <= end && start > 0 && end > 0 )
		{
			if(start % 2 == 1)
				printf("%d ",start);
				
			start++;	
		}
		printf("\n");
	}
	
	return 0;
} 

