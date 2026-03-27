#include<stdio.h>
//初始化结构体指针实例 
int main()
{
	struct 
	{
		char *name;
		int num;
		int age;
		char group;
		float score;
	}stu1 = {"Tom",12,18,'A',136.5},*pstu = &stu1;
	
	printf("%s 的学号是 %d,年龄是 %d,小组是 %c,成绩是 %.1f\n",(*pstu).name,(*pstu).num,(*pstu).age,(*pstu).group,(*pstu).score);
	printf("%s 的学号是 %d,年龄是 %d,小组是 %c,成绩是 %.1f\n",pstu->name,pstu->num,pstu->age,pstu->group,pstu->score);
	
	return 0;
	
}

