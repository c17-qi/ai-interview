//根据长方体的长宽高，求它的体积以及三个面的面积

#include<stdio.h>

int compute_v(int a, int b, int c);
int compute_s(int a, int b, int c);

int compute_v  (int a, int b, int c)
{
	int v = a * b * c;
	return v;
 } 
 
int compute_s(int a, int b, int c)
 {
 	printf("三个面的面积分别为：%d %d %d\n", a * b, a * c, b * c);
  } 
 
 int main()
 {
 	int a, b, c;
 	while(1)
 	{
	 	printf("请输入长宽高：");
	 	scanf("%d %d %d", &a, &b, &c);
	 	
	 	if(a == 0 && b == 0 && c == 0)
	 		break;
	 	
	 	if(a <= 0 || b <= 0 || c <= 0)
	 		printf("尺寸必须大于0\n");
	 	else
	 	{
	 		int v = compute_v(a, b, c);
		 	compute_s(a, b, c);
		 	printf("长方体体积为：%d\n", v);	
		 }
	 }
 	
 	return 0;
 }
