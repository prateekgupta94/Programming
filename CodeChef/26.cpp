#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int t,n,m,i,x,d;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        int a[n];
        for(i=0; i<n; i++)
            a[i]=i+1;
        for(i=0; i<m; i++)
        {
            scanf("%d", &x);
            a[x-1]=0;
        }
        d=0;
        m=0;
        for(i=0; i<n; i++)
        {
            if(d==0 && a[i]!=0)
            {
                printf("%d ", a[i]);
                d=1;
            }
            else if(d==1 && a[i]!=0)
            {
                a[m++]=a[i];
                d=0;
            }
        }
        a[m]=0;
        printf("\n");
        for(i=0; i<n; i++)
        {
            if(a[i]!=0)
                printf("%d ", a[i]);
            else
                break;
        }
        printf("\n");
    }
    return 0;
}
