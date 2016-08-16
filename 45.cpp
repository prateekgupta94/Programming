#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define PI 3.14159265
using namespace std;
/*quicksort(increasing order)*/
void quicksort(long long x[100005],int first,int last)
{
    int pivot,j,i;
    long long temp;

    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(x[i]<=x[pivot] && i<last)
                 i++;
            while(x[j] > x[pivot])
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
    int n,i;
    scanf("%d", &n);
    long long ans=0,a[100005];
    for(i=0; i<n; i++)
    {
        scanf("%I64d", &a[i]);
        ans+=a[i];
    }
    quicksort(a,0,n-1);
    for(i=0; i<n; i++)
    {
        if(ans%2==0)
        {
            printf("%I64d\n", ans);
            break;
        }
        else
            ans-=a[i];
        if(ans==0)
        {
            printf("%I64d\n", ans);
            break;
        }
    }
    return 0;
}
