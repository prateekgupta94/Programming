#include<bits/stdc++.h>
using namespace std;

long long diff(long long a, long long b)
{
    if(a>b)
        return (a-b);
    else
        return (b-a);
}

long long minn(long long a, long long b)
{
    if(a>b)
        return b;
    else
        return a;
}

long long gcd(long long a, long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long a,b,c,d,ans,temp,g;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        temp=diff(a,b);
        g=gcd(c,d);
        ans=temp%g;
        temp=(g-(temp%g));
        ans=minn(ans,temp);
        printf("%lld\n", ans);
    }
	return 0;
}
