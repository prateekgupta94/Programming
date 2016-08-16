#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
struct st
{
    int l;
    int r;
    int c;
};
int main()
{
    long long int t,n,m;
    int k,i,j,flag,sum;
    scanf("%lld", &t);
    while(t--)
    {
        sum=0;
        scanf("%lld%d%lld", &n, &k, &m);
        long long int a[n];
        int pos[n];
        for(i=0; i<n; i++)
        {
            scanf("%lld", &a[i]);
            pos[i]=i+1;
        }
        struct st x[m];
        for(i=0; i<m; i++)
            scanf("%d%d%d", &x[i].l, &x[i].r, &x[i].c);
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(a[i]>a[j])
                {
                    flag=a[i];
                    a[i]=a[j];
                    a[j]=flag;

                    flag=pos[i];
                    pos[i]=pos[j];
                    pos[j]=flag;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            j=0;
            if(k==0)
                break;
            while(j!=5)
            {
                if(x[j].l<=pos[i] && x[j].r>=pos[i])
                {
                    if(x[j].c<=k)
                    {
                        k-=x[j].c;
                        a[i]=0;
                        j=4;
                    }
                }
            j++;
            }
        }
        for(i=0; i<n; i++)
            sum+=a[i];
        printf("%d", sum);
    }
	return 0;
}

