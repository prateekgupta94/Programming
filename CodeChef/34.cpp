#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;

bool prime[10010];
void sieve(int n)
{
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

int gcd(int a,int b)
{
if(b==0)
return a;
else
return gcd(b,a%b);
}

int calc(int a[10010], int n)
{
    int x[10010],i;
    x[0]=a[0];
    for(i=1;i<n;i++)
    {
        x[i]=gcd(x[i-1],a[i]);
        if(x[i]==1)
            return 1;
    }
    return x[n-1];
}

int main()
{
    int t,n,i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int a[10010],b[10010],ctr=0,ans=1000000,x=2,flag=0,ex=0,l=-1;
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
            if(l<a[i])
                l=a[i];
            if(i>0 && a[i-1]>a[i])
            {
                ex=ex+(a[i-1]-a[i]);
                a[i]=a[i-1];
            }
        }
        ctr=calc(a,n);
        if(ctr==1)
        {
            sieve(l+10);
            while(x<=l+10)
            {
                if(prime[x])
                {
                    for(i=0; i<n; i++)
                    {
                        b[i]=a[i]%x;
                        if(b[i]!=0)
                            b[i]=x - b[i];
                    }
                    for(i=0; i<n; i++)
                        flag+=b[i];
                    ans=min(ans,flag);
                    if(ans==1)
                        break;
                }
                x++;
                flag=0;
            }
            printf("%d\n", ans+ex);
        }
        else
            printf("%d\n", flag+ex);
    }
    return 0;
}
