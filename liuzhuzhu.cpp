#include <stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // 回归质朴，百发百正的临时变量法
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main(){
    int *arr;
    int n;
    printf("---欢迎使用工资排序器---\n");
    printf("请输入员工数量：\n");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    for (int i =0 ;i<n;i++){
        printf("请输入第%d位员工的工资:",i+1);
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr, n);
    printf("---排序完成---\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
