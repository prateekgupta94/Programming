#include<bits/stdc++.h>
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(x) scanf(" %[^\n]", x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;
int main()
{
    long long t;
    sl(t);
    while(t--)
    {
        long long n,i,y,j,f,l,check=0;
        long long ans=0,temp=1000000007;
        sl(n);
        char s[100010];
        ss(s);
        long long x[100010];
        for(i=0; i<n; i++)
            sl(x[i]);
        j=0;
        i=y=-1;
        while(j!=n)
        {
            if(s[j]=='1')
            {
                if(i==-1)
                    f=j;
                if(check==0)
                {
                    i=j;
                    check=1;
                }
                else
                {
                    y=j;
                    check=0;
                }
                if(i!=-1 && y!=-1)
                {
                    if(y>i)
                    {
                        for(int k=i; k<y; k++)
                            temp=min(temp,x[k]-x[i]+x[y]-x[k+1]);
                        if(temp!=1000000007)
                            ans+=temp;
                        temp=1000000007;
                    }
                    else
                    {
                        for(int k=y; k<i; k++)
                            temp=min(temp,x[k]-x[y]+x[i]-x[k+1]);
                        if(temp!=1000000007)
                            ans+=temp;
                        temp=1000000007;
                    }
                }
                l=j;
                j++;
            }
            else
                j++;
        }
        ans+=x[f]-x[0];
        ans+=x[n-1]-x[l];
        pl(ans);
    }
    return 0;
}
