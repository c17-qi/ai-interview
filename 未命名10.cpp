#include<stdio.h>

struct stu 
{
	char *name;
	float score;
}stu1[] =
	{
		{"Li ping",145.0},
		{"Zhang ping",130.5},
		{"He fang",148.5},
		{"Cheng ling",139.0},
		{"Wang ming",144.5}
	};

char *compute(struct stu *ps, int len,float *avg);

char *compute(struct stu *ps, int len,float *avg)
{
	int i;
	char *top_name;
	float max;
	float sum = 0;
	
	//空数组处理
	if(ps == NULL || len <= 0)
	{
		*avg = 0;
		return NULL;
	 } 
	
	max = ps[0].score;
	top_name = ps[0].name;
	
	for(i = 0; i < len; i++)
	{
		sum += ps[i].score;
		
		if(ps[i].score > max)
		{
			max = ps[i].score;
			top_name = ps[i].name;
		}

	}
	
	*avg = sum / len;
	
	return top_name;
	
}

int main()
{
	int len = sizeof(stu1) / sizeof(struct stu);
	float average;
	char *top;
	
	top = compute(stu1,len,&average);
	
	if(top != NULL)
		printf("average = %.2f\ntop = %s\n",average,top);
	else
		printf("no data\n");
	
	return 0;
}
