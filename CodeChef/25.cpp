#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
void quicksort(int x[200005],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(x[i]<=x[pivot]&&i<last)
                i++;
            while(x[j]>x[pivot])
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
    int n,i,c=0;
    scanf("%d", &n);
    int a[200005];
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        if(i>0 && a[i]!=a[i-1] && c==0)
            c=1;
    }
    if(c==1)
    {
        quicksort(a,0,n-1);
        printf("\n%d %d\n", a[n-1], a[n-2]);
    }
    else
    {
        printf("\n%d %d\n", a[n-1], a[n-2]);
    }
    return 0;
}
