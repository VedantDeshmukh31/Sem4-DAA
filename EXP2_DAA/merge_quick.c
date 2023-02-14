#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int arr[],int beg,int mid,int end)
{
    
    int temp[100000];
    int i=beg,j=mid+1,index=0,k;
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            temp[index]=arr[i];
            i++;
            index++;
        }
        else
        {
            temp[index]=arr[j];
            j++;
            index++;
        }
       
    }
    while(i<=mid)
    {
            temp[index]=arr[i];
            i++;
            index++;
    }
    while(j<=end)
    {
            temp[index]=arr[j];
            j++;
            index++;
    }
    for(i=beg,k=0;i<=end;i++,k++)
    {
        arr[i]=temp[k];
    }
   
}
void merge_sort(int arr[],int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
}
}
int partition(int arr[],int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub,temp;
    
    while(start<end)
    {
        while( arr[start]<=pivot)
        {
            start++;
        }
        while(pivot<arr[end])
        {
            end--;
        }
            if(start<end)
            {
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            }
        
        
    }
    
    temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;
    return end;

}
void quicksort(int arr[],int lb,int ub)
{
    int loc;
    if(lb<ub)
    {
     loc=partition(arr,lb,ub);
    quicksort(arr,lb,loc-1);
   quicksort(arr,loc+1,ub);
    }
}
int main()
{
    int n=0;
	for(int k=0; k<(1000); k++)
	{
		n=n+100;
		int num[n];
		int arr[n];
		int merge_arr[n];
		int j, min;
		clock_t start_t, end_t;
	    double total_t;
		printf("%d\t",n);
		for(int i=0; i<n; i++)
		{
			num[i]=rand() % 10;
			arr[i]=num[i];
            merge_arr[i]=num[i];
			
		}

       start_t = clock();
        quicksort(arr,0,n-1);
        end_t = clock();
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("%f\t", total_t  );
       
        start_t = clock();
        merge_sort(merge_arr, 0 ,n-1);
        end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("%f\t", total_t  );
        printf("\n");
    }


    return 0;
}
