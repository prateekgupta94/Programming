#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
void quicksort(int x[20010],int first,int last)
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
    int t,n,m,a[20010],i,ans,w,x;
    scanf("%d", &t);
    while(t--)
    {
        x=1;
        ans=0;
        scanf("%d%d", &n, &m);
        for(i=0; i<m; i++)
        {
            scanf("%d", &a[i]);
            if(a[i]!=1)
                x=0;
        }
        if(x==0)
            quicksort(a,0,m-1);
        w=m-1;
        for(i=0; i<m; i++)
        {
            if(a[i]>=w)
            {
                ans+=w;
                break;
            }
            else if(a[i]<w)
            {
                if(a[i]==1)
                {
                    ans++;
                    w-=2;
                    continue;
                }
                else
                {
                    ans+=a[i];
                    w-=(a[i]+1);
                    continue;
                }
            }
        }
        printf("\n%d\n", ans);
    }
    return 0;
}
