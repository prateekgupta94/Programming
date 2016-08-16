#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

long long mod=1000000007;
long long modl(long long a)
{
    return (a%mod);
}

unsigned long long power(long long x, long long y, long long m)
{
    if (y == 0)
    return 1;
    unsigned long long p = power(x, y/2, m) % m;
    p = (p * p) % m;
    if(y%2==0)
        return p;
    else
        return (x * p) % m;
}

unsigned long long modinv(unsigned long long a)
{
    return power(a, mod-2, mod);
}

int main()
{
    long long t,i,n,x,m;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld%lld", &n, &x, &m);
        long long a[100005],sum,prod=1,j=1;
        for(i=0; i<n; i++)
        {
            scanf("%lld", &a[i]);
            a[i]=a[i]%mod;
        }
        if(x==1)
          printf("%lld\n", modl(a[x-1]));
        else
        {
            m=m-1;
            sum=a[x-1];
            for(i=x-2; i>=0; i--)
            {
                prod=modl(modl(prod*modl(m+j))*modinv(j));
                sum=modl(sum+modl(a[i]*prod));
                j++;
            }
            printf("%lld\n", sum);
        }
    }
    return 0;
}

