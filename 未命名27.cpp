#include<stdio.h>

int main()
{
	FILE *file = fopen("111.txt","r");
	if(file == NULL)
	{
		printf("Failed to open file.\n");
		return 1;
	}
	
	char buffer[100];
	
	while(fgets(buffer, 100, file) != NULL)
	{
		printf("%s ", buffer);
	}
	 
	 fclose(file);
	 return 0;
}
