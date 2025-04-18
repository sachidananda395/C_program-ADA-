#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void merge(int arr[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    int c[1000000];
    while(i<=mid &&j<=high)
    {
        if(arr[i]<arr[j])
        {
            c[k]=arr[i];
            i++;
        }
        else{
            c[k]=arr[j];
            j++;
        }
        k++;
        
    }
    while(i<=mid)
    {
        c[k++]=arr[i++];
    }
    for(i=low;i<=high;i++)
    {
        arr[i]=c[i];
    }
}
void merge_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
   int n,i;
   printf("enter the number of elemnets");
   scanf("%d",&n);
   int arr[n];
   srand(time(NULL));
   for(i=0;i<n;i++)
   {
       arr[i]=rand()%10000;
       
   }
   clock_t start=clock();
   merge_sort(arr,0,n-1);
   clock_t end=clock();
   double timetaken=((double)(end-start))/CLOCKS_PER_SEC;
   printf("Time taken for sorting :%f seconds \n ",timetaken);
   return 0;
   
}
