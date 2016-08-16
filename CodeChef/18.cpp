#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
void quicksort(int x[10],int first,int last)
{
    int pivot,j,temp,i;

    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(x[i]>=x[pivot] && i<last)
                 i++;
            while(x[j] < x[pivot])
                 j--;
            if(i<j)
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        quicksort(x,first,j-1);
        quicksort(x,j+1,last);
    }
}
int main()
{
    int n,t,i,ans,temp;
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        scanf("%d", &n);
        int a[n],x=100000;
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);
        for(i=0; i<n; i++)
            if(x > a[i])
                x=a[i];
        quicksort(a,0,n-1);
        for(i=0; i<n-1; i++)
        {
            if(x < a[i] && a[i]==a[i+1])
            {
                temp=a[i];
                a[i]=x;
                a[i+1]=x;
                ans++;
            }
            else if(x==a[i] && temp==a[i+1])
                a[i+1]=x;
            else if(x < a[i])
            {
                a[i]=x;
                ans++;
            }
        }
        printf("\n%d", ans+1);
    }
    return 0;
}
