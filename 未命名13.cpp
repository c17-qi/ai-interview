 #include<stdio.h>
 
 int *found(int *arr,int len);
 
 int *found(int *arr,int len)
 {
 	if(arr == NULL || len <= 0)
 	{
 		return NULL;
	 }
	 
	 int *top = arr;
	 
	 for(int i = 0; i < len; i++)
	 {
	 	if(*top < arr[i])
	 	{
	 		top = &arr[i];
		 }
	 }
	 return top;
 }
 
 int main()
 {
 	int arr[] = {2,3,4,5,6};
 	int len = sizeof(arr) / sizeof(arr[0]);
 	
 	int *p = found(arr,len);
 	
 	if(p != NULL)
 		printf("max = %d\n",*p);

 	return 0;
 }
