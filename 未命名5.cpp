#include<stdio.h>
#include<string.h>

int main()
{
	char arr[] = "Hello,World!";
	char dest[50];
	char dec[] = "C17";
	
	int length = strlen(arr);
	strcpy(dest,arr);
	strcat(arr,dec);

	printf("Length of the string: %d\n",length);
	printf("Copied string: %s\n",dest);
	printf("×Ö·û´®Á¬½Ó: %s\n",arr);
	
	return 0;
}
