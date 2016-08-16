#include<bits/stdc++.h>
using namespace std;

long long mod=1000000007;
long long modl(long long a)
{
    return (a%mod);
}

long long mul(long long b, long long e)
{
long long p = 0;
while (e > 0)
{
    if(e&1)
        p = modl(p+b);
    e = e>>1;
    b = modl(b+b);
}
return p;
}

long long power(long long b, long long e)
{
long long p = 1;
while (e > 0)
{
    if(e&1)
        p = modl(mul(p,b));
    e = e>>1;
    b = modl(mul(b,b));
}
return p;
}

int main()
{
    long long t,i,j;
    scanf("%lld", &t);
    while(t--)
    {
        long long n,k,ans=1;
        scanf("%lld%lld", &n, &k);
        ans=modl(k*modl(power(k-1,n-1)));
        printf("%lld\n", ans);
    }
    return 0;
}
