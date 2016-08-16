#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int t,n,i,j,ans,a[250010],b[250010],x[505][505];
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d", &x[i][j]);
                a[x[i][j]]=i;
                b[x[i][j]]=j;
            }
        }
        for(i=1; i<n*n; i++)
        {
            if(a[i]>a[i+1])
            {
                ans+=(a[i] - a[i+1]);
                if(b[i]>b[i+1])
                    ans+=(b[i] - b[i+1]);
                else
                    ans+=(b[i+1] - b[i]);
            }
            else if(a[i]<a[i+1])
            {
                ans+=(a[i+1] - a[i]);
                if(b[i]>b[i+1])
                    ans+=(b[i] - b[i+1]);
                else
                    ans+=(b[i+1] - b[i]);
            }
            else if(a[i]==a[i+1])
            {
                if(b[i]>b[i+1])
                    ans+=(b[i] - b[i+1]);
                else
                    ans+=(b[i+1] - b[i]);
            }
        }
        printf("\n%d\n", ans);
    }
    return 0;
}
