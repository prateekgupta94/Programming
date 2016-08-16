#include<bits/stdc++.h>
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(x) scanf(" %[^\n]", x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define pb push_back
using namespace std;
int main()
{
    int t;
    si(t);
    while(t--)
    {
        int n,i,j,ans=0,x=0,check=0;
        si(n);
        int a[1005];
        map<int,int> temp;
        for(i=0; i<n; i++)
        {
            si(a[i]);
            temp[a[i]]++;
            if(temp[a[i]]>1)
                check++;
        }
        if(check==0)
        {
            for(i=1; i<=n; i++)
                ans+=((((n-i)*(n-i+1))/2)*i);
        }
        else
        {
            for(i=0; i<n; i++)
            {
                x=i;
                for(j=i+1; j<n; j++)
                {
                    if(a[i]!=a[j])
                        ans+=(j-x);
                    else
                        x=j;
                }
            }
        }
        pi(ans);
    }
    return 0;
}

