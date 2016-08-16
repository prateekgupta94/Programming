#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

void quicksort(int x[100010],int y[100010],int first,int last)
{
    int pivot,j,temp,i,temp1;
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
                temp1=y[i];
                y[i]=y[j];
                y[j]=temp1;
            }
        }
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        temp1=y[pivot];
        y[pivot]=y[j];
        y[j]=temp1;
        quicksort(x,y,first,j-1);
        quicksort(x,y,j+1,last);
    }
}

int main()
{
    int n,i,j,ans,tcost=0,chk=10000000;
    scanf("%d", &n);
    int h[100005],c[100005];
    for(i=0; i<n; i++)
        scanf("%d", &h[i]);
    for(i=0; i<n; i++)
        scanf("%d", &c[i]);
    quicksort(h,c,0,n-1);
    for(i=0; i<n; i++)
    {
        tcost=0;
        for(j=0; j<n; j++)
        {
            if(i!=j)
                tcost+=(abs(h[i]-h[j])*c[j]);
        }
        if(min(chk,tcost)!=chk)
        {
            ans=h[i];
            chk=min(chk,tcost);
        }
    }
    printf("%d\n", ans);
    return 0;
}
