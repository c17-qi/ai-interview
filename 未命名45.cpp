//递归反转字符串

#include<stdio.h>

void reverse(char *str)
{
	if(*str == '\0')
		return;//return不是回到main()，而是回到上一层调用的函数 
		
	reverse(str + 1);
	printf("%c", *str);//返回时开始打印,程序从最深层往回返回 
 } 
 
 int main()
 {
 	char str[100];
 	
 	printf("请输入字符串：\n");
 	scanf("%s",str);
 	
 	printf("反转结果：");
 	reverse(str);
 	
 	printf("\n");
 	return 0;
 }
