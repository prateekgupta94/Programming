#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
void quicksort(int x[505],int first,int last)
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
    int t,f,h,w,i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &f, &h, &w);
        int p[f];
        for(i=0; i<f; i++)
            scanf("%d", &p[i]);
        p[i]=w;
        quicksort(p,0,f);
        for(i=f; i>0; i--)
            p[i]=p[i] - p[i-1];
        quicksort(p,0,f);
        printf("%d\n", p[0]*h);
    }
    return 0;
}
