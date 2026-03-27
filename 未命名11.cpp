//例题：定义一个结构体book 包含书名name 价格price
//接收结构体数组和数组长度 计算所有书的总价和平均价格
//返回价格最高的书名
//确保数组为空的情况 

#include<stdio.h>

struct book
{
	char *name;
	float price;
}Book[] =
	{
		{"C Primer Plus", 88.5},
	    {"Data Structure", 76.0},
	    {"Operating System", 99.0},
	    {"Computer Network", 85.0}
	};
	
char *analyze(struct book *pb, int len, float *avg);

char *analyze(struct book *pb, int len, float *avg)
{
	int i;
	float sum = 0;
	char *top_name;
	float top_price;
	
	//空数组处理
	if(pb == NULL || len <= 0)
	{
		*avg = 0;
		return NULL;
	 } 
	 
	top_name = pb[0].name;
	top_price = pb[0].price;
	
	for(i = 0; i < len; i++)
	{
		sum += pb[i].price;
		
		if(pb[i].price > top_price)
		{
			top_price = pb[i].price;
			top_name = pb[i].name;
		}
	}
	
	*avg = sum / len;
	return top_name;
}

int main()
{
	int len = sizeof(Book) / sizeof(Book[0]);
	float average;
	char *top;
	
	top = analyze(Book,len,&average);
	
	if(top != NULL)
	printf("average = %.2f\ntop_name = %s\n",average,top);
	else
	printf("no data\n");
	
	return 0;
}
