#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;
    while(1)
    {
        while(i<=high &&arr[i]<=pivot)
        i++;
        while(arr[j]>pivot)
        j--;
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        else
        {
            temp=arr[low];
            arr[low]=arr[j];
            arr[j]=temp;
            return j;
        }
    }
}


void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}


int main()
{
    int n,i;
    printf("enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%10000;
    }
    clock_t start=clock();
    quick_sort(arr,0,n-1);
    clock_t end=clock();
    double timetaken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("time taken for sorting : %f seconds \n ",timetaken);
    return 0;
    
    
}
