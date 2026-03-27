//µİ¹é¼ÆËã×Ö·û´®³¤¶È

#include<stdio.h>

int str_len(char *str);

int str_len(char *str)
{
	if(*str == '\0')
		return 0;
	
	str_len(str + 1);
	return 1 + str_len(str + 1);	
	
}

int main()
{
	char str[100];
	
	printf("ÇëÊäÈë×Ö·û´®£º\n");
	scanf("%s",str);
	
	int len = str_len(str);
	printf("%d\n", len);
	
	return 0;
}
 
