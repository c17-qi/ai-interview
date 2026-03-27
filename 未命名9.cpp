#include<stdio.h>
//结构体指针作为函数参数实例
	
struct stu
{
	char *name;
	int num;
	int age;
	char group;
	float score;
}stus[] =
	{
		{"Li ping",5,18,'C',145.0},
		{"Zhang ping",4,19,'A',130.5},
		{"He fang",1,18,'A',148.5},
		{"Cheng ling",2,17,'F',139.0},
		{"Wang ming",3,17,'B',144.5}	
	};

void average(struct stu *ps, int len);

void average(struct stu *ps, int len)
{
	int i,num_140 = 0;
	float average,sum = 0;
	
	for(i = 0; i < 5; i++)
	{
		sum += (ps + i) -> score;
		if((ps +i) -> score <140)
		num_140++;
	}
	printf("sum = %.2f\naverage = %.2f\nnum_140 = %d\n",sum,sum/5,num_140);
	
}
	
int main()
{
	int len = sizeof(stus) / sizeof(struct stu);
	average(stus, len);
	
	return 0;
}



		

