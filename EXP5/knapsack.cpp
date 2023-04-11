#include<bits/stdc++.h>
using namespace std;
struct Knapsack
{
    int id;
    float prof,wt,ratio;
};
void sort(int n,struct Knapsack arr[10])
{
    struct Knapsack temp;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[j].ratio>arr[i].ratio)
            {
               temp=arr[j];
               arr[j]=arr[i];
               arr[i]=temp;
            }
        }
    }
}
int main()
{
    int cap,i,j,n;
    float p,w;
    float profit;

    cout<<"Enter Capacity "<<endl;
    cin>>cap;
    cout<<"Enter number of Elements"<<endl;
    cin>>n;
    struct Knapsack kn[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter Profit and weight element of "<<(i+1)<<" item"<<endl;
        cin>>p>>w;
        kn[i].prof=p;
        kn[i].wt=w;
        kn[i].ratio=p/w;
        kn[i].id=(i+1);

    }
    printf("\nID\t\tPROFIT\t\t\tWEIGHT\t\t\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t%f\t\t%f\t\t\n",kn[i].id,kn[i].prof,kn[i].wt);
    }
    sort(n,kn);
    printf("Sorted with p/w Ratio");
    printf("\nID\t\tPROFIT\t\t\tWEIGHT\t\t\tRATIO\t\t\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t%f\t\t%f\t\t%f\t\t\n",kn[i].id,kn[i].prof,kn[i].wt,kn[i].ratio);
    }
    
    for(i=0;i<n;i++)
    {
      if(cap>kn[i].wt)
      {
        cap=cap-kn[i].wt;
        profit=profit+kn[i].prof;

      }
      else if(cap<=kn[i].wt)
      {
        profit=profit+kn[i].ratio*cap;
        cap=0;

      }
        if(cap==0)
        {
            break;
        }
    }
    printf("Total Profit Obtained after performing fractiional knapsack is %f",profit);

}