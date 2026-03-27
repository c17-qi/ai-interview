#include<stdio.h>

int main()
{
	struct
	{
		char *name;//姓名
		int num;//学号
		int age;//年龄
		char group;//小组
		float score;//成绩 
	}stu;
	
	stu.name = "Tom";
	stu.num = 12;
	stu.age = 17;
	stu.group = 'A';
	stu.score = 90.33;
	
	printf("%s 的学号是 %d ,年龄是 %d ,所在小组为 %c ,成绩为 %.2f\n",stu.name,stu.num,stu.age,stu.group,stu.score);
	
	return 0;
	
}
