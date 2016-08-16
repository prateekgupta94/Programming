#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

long long mod=1000000007;
long long pow2[100005];

long long modd(long long a)
{
    return (a%mod);
}

void calc()
{
    long long current = 1;
    int i;
    for(i=0; i<100005; i++)
    {
        pow2[i]=current;
        current=modd(current*2);
    }
}

long long powi(int x)
{
    return pow2[x];
}

int main()
{
    calc();
    int t,n,i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        long long a[100005];
        long long ans=0,pr=0;
        for(i=0; i<=n; i++)
            scanf("%lld", &a[i]);
        for(i=1; i<=n; i++)
        {
            if(i==1)
                pr+=2*a[i-1];
            else
                pr+=(modd(powi(i-1))*a[i-1]);
            pr=modd(pr);
            ans+=modd(modd(powi(n-i))*(modd(pr*a[i])));
            ans=modd(ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
