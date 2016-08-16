#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    scanf("%lld", &t);
    while(t--)
    {
        long long r,g,b,k;
        scanf("%lld%lld%lld", &r, &g, &b);
        scanf("%lld", &k);
        long long ans=1;
        if(r<k-1)
            ans+=r;
        else
            ans+=k-1;
        if(g<k-1)
            ans+=g;
        else
            ans+=k-1;
        if(b<k-1)
            ans+=b;
        else
            ans+=k-1;
        printf("%lld\n", ans);
    }
    return 0;
}
