
#include<stdio.h>
#include<stdlib.h>
void quicksort(int[],int,int);
int partition(int[],int,int);
int main(){
    int arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=rand();
        printf("%d\n",arr[i]);
        scanf("%d",arr[i]);
    }
    quicksort(arr,0,9);
    printf("sorted array is :");
    for(int i=0;i<10;i++)
    printf("%d\n",arr[i]);
}
void quicksort(int arr[],int l,int h)
{                                               
    if(l<h)
    {
        int j=partition(arr,l,h);
        quicksort(arr,l,j-1);
        quicksort(arr,j+1,h);
    }
}
int partition(int arr[],int l,int h)
{
    int pivot,p,q;
    p=l;
    q=h+1;
    pivot=arr[l];
    while(p<q)
    {
        do
        {
           p++; /* code */
        } while (arr[p]<pivot);
        do
        {
           q--; /* code */
        } while (arr[q]>pivot);
        if(p<q)
        {
            int t=arr[p];
            arr[p]=arr[q];
            arr[q]=t;
        }  
    }
    arr[l]=arr[q];
    arr[q]=pivot;
    /*int temp=pivot;
    pivot=arr[q];
    arr[q]=temp;*/
    return q;
}