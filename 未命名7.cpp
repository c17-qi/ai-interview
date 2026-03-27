//计算全班学生总成绩、平均成绩以及140分以下的人数
//结构体中有姓名，学号，分组，年龄，分数 
//		{"Li ping",5,18,'C',145.0},
//		{"Zhang ping",4,19,'A',130.5},
//		{"He fang",1,18,'A',148.5},
//		{"Cheng ling",2,17,'F',139.0},
//		{"Wang ming",3,17,'B',144.5}
#include<stdio.h>

struct
{
		char *name;
		int num;
		int age;
		char group;
		float score;
}stu [] = 
	{
		{"Li ping",5,18,'C',145.0},
		{"Zhang ping",4,19,'A',130.5},
		{"He fang",1,18,'A',148.5},
		{"Cheng ling",2,17,'F',139.0},
		{"Wang ming",3,17,'B',144.5}
	};
	
int main()
{
	float sum;
	int num_140 = 0;
	int i;
	int average;
	
	for(i = 0; i < 5; i++)
	{
		sum += stu[i].score;
		if(stu[i].score < 140)
		num_140++;
	}
	
	printf("sum=%.2f\naverage=%.2f\nnum_140=%d\n",sum,sum/5,num_140);
	return 0;
}
