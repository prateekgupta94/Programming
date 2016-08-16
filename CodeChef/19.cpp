#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int t,i,n,k,a[2001]={0},x,y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        while(k--)
        {
            scanf("%d%d",&x,&y);
            for(i=x; i<=y; i++)
            {
                if((i-x)%2==0)
                    a[i]=0;
                else
                    a[i]=1;
            }
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
                printf("(");
            else if(a[i]==1)
                printf(")");
            else
                printf("(");
            a[i]=0;
        }
        printf("\n");
    }
    return 0;
}
