#include<bits/stdc++.h>
long long max(long long a, long long b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    long long t,n,k,i;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld", &n, &k);
        long long a[100005],b[100005],sum=0;
        for(i=0; i<n; i++)
            scanf("%lld", &a[i]);
        for(i=0; i<n; i++)
            scanf("%lld", &b[i]);
        for(i=0; i<n; i++)
        {
            if(b[i]<0)
            {
                a[i]=0-a[i];
                b[i]=0-b[i];
            }
        }
        for(i=0; i<n; i++)
            sum+=(a[i]*b[i]);
        long long ans=sum,nsum;
        for(i=0; i<n; i++)
        {
            nsum=sum + (b[i]*k);
            ans=max(nsum,ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
