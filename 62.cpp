#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long modl(long long a)
{
    return (a%mod);
}

long long best(long long base, long long n)
{
    if(n==0)
       return 1;
    long long halfn=best(base,n/2);
    if(n%2==0)
        return ( halfn * halfn )% mod;
    else
        return ( ( ( halfn * halfn ) % mod ) * base ) % mod;
}

long long inv(long long a, long long m)
{
    return best(a, m-2);
}

long long ncr(long long n,long long k)
{
    long long imp,ctr,ans,temp;
    if(k%2==0)
    {
        ans=1,ctr=2,imp=1;
    }
    else
    {
        ans=n,ctr=3,imp=n;
    }
    while(ctr<=k)
    {
        temp=ctr-1;
        imp=modl(inv((temp+1)*(temp),mod)*modl(modl(modl(imp)*(n-temp))*(n-temp+1)));
        ans=modl(ans+imp);
        ctr+=2;
    }
    return ans;
}

int main()
{
	long long t;
	scanf("%lld", &t);
	while(t--)
    {
        long long n,k,i,ans=0,zero=0,no;
        scanf("%lld%lld", &n, &k);
        for(i=0; i<n; i++)
        {
            scanf("%lld", &no);
            if(no==0)
                zero++;
        }
        no=n-zero;
        if(no==0)
            printf("1\n");
        else
        {
            if(zero==0)
                ans=ncr(no,k);
            else
                ans+=best(2,no);
            printf("%lld\n", ans);
        }
    }
	return 0;
}

