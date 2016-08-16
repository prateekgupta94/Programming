#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

/*quicksort(increasing order)*/
void quicksort(int x[50005],int first,int last)
{
    int pivot,j,temp,i;

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
    int t,n,i,j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int a[50005],x=0;
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);
        quicksort(a,0,n-1);
        for(i=0; i<=n/2; i++)
        {
            if(i==0)
                j=n-i-1;
            else
                j=n-i;
            if(a[i]==a[j] && i!=j)
            {
                x+=(j-i+1);
                break;
            }
            else if(a[i]!=a[j])
                x++;
        }
        printf("%d\n", x);
    }
    return 0;
}
