#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
void quicksort(int x[200010],int first,int last)
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
    int t,n,m,k,i,j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &k, &m);
        int a[n],b[n],c[k+m],diff[n],z,ans=0;
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);
        for(i=0; i<n; i++)
            scanf("%d", &b[i]);
        for(i=0; i<k+m; i++)
            scanf("%d", &c[i]);
        for(i=0; i<n; i++)
            diff[i]=a[i]-b[i];
        quicksort(diff,0,n-1);
        quicksort(c,0,k+m-1);
        i=0;
        j=0;
        while(i<n && j<k+m)
        {
            if(diff[i]==c[j])
            {
                diff[i]=0;
                c[j]=-1;
                i++;
                j++;
            }
            else if(diff[i]>c[j])
                i++;
            else
                j++;
        }
        i=0;
        j=0;
        while(i<n && j<k+m)
        {
            if(diff[i]>c[j] && c[j]!=-1)
            {
                diff[i]-=c[j];
                c[j]=-1;
                i++;
                j++;
            }
            else if(diff[i]<c[j] && diff[i]!=0)
                j++;
            else if(c[j]==-1)
                j++;
            else
                i++;
        }
        for(i=0; i<n; i++)
            ans+=diff[i];
        printf("%d\n", ans);
    }
    return 0;
}
