#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define mod 1000000007
using namespace std;
int main()
{
    int n,m,i,j;
    double d;
    scanf("%d%d%lf", &n, &m, &d);
    int a[1005][2010],xi=-1,xii=-1,t=0,bs=1;
    double cr1=d,cr2=0;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d%d", &a[i][2*j], &a[i][2*j+1]);
    for(j=0; j<2*m; j+=2)
    {
        for(i=0; i<n-1; i++)
        {
            if(bs==1)
            {
                if(a[i][j]<a[i+1][j])
                    xi=i;
            }
            else
            {
                if(a[i][j+1]>a[i+1][j+1])
                    xi=i;
            }
        }
        if(j==2*m-4 && cr1>cr2)
        {
        if(bs==1)
        {
            if(cr1==a[xi][j])
            {
                cr1-=a[xi][j];
                cr2++;
                if(j==0)
                    t++;
                else
                    t+=abs(xii-xi) + 1;
                bs=0;
            }
            else
            {
                cr1-=(cr1/a[xi][j]);
                cr2+=(cr1/a[xi][j]);
                if(j==0)
                    t++;
                else
                    t+=abs(xii-xi) + 1;
                bs=0;
            }
        }
        else
        {
            cr1+=(cr2*a[xi][j+1]);
            cr2-=cr2;
            t+=abs(xii-xi) + 1;
            bs=1;
        }
        }
        else if(j<2*m-4 || j==2*m-2)
        {
        if(bs==1)
        {
            if(cr1==a[xi][j])
            {
                cr1-=a[xi][j];
                cr2++;
                if(j==0)
                    t++;
                else
                    t+=abs(xii-xi) + 1;
                bs=0;
            }
            else
            {
                cr2+=(cr1/a[xi][j]);
                cr1-=cr1;
                if(j==0)
                    t++;
                else
                    t+=abs(xii-xi) + 1;
                bs=0;
            }
        }
        else
        {
            cr1+=(cr2*a[xi][j+1]);
            cr2-=cr2;
            t+=abs(xii-xi) + 1;
            bs=1;
        }
        }
        if(cr1>1000000000000000000 || cr2>1000000000000000000)
        {
            printf("Quintillionnaire\n");
            return 0;
        }
        xii=xi;
    }
    if(cr1<=1000000000000000000 && cr2<=1000000000000000000)
        printf("%lf", cr1);
    return 0;
}
