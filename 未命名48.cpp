//递归反转字符串，真正交换字符

#include<stdio.h>
#include<string.h>

void reverse(char *str, int left, int right);

void reverse(char *str, int left, int right)
{
	if(left >= right)
		return;
	reverse(str, left + 1, right - 1);
	char temp = str[right];
	str[right] = str[left]; 
	str[left] = temp;
}

int main()
{
	int left, right;
	char str[100];
	
	printf("请输入字符串：\n");
	scanf("%s", str);
	
	int len = strlen(str);
	reverse(str, 0, len - 1);//数组下标是从0开始的所以最后一个字符下标是len-1 
	
	printf("反转后：%s\n", str);
	
	return 0;
}
 
