#include<bits/stdc++.h>
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
using namespace std;
int main()
{
    int t;
    si(t);
    while(t--)
    {
        int n,i,ans=-1,ctr=0;
        si(n);
        int temp,temp1=1;
        map <int,int> a;
        for(i=0; i<n; i++)
        {
            si(temp);
            a[temp]++;
        }
        temp=1;
        map<int,int>::reverse_iterator rit;
        for(rit=a.rbegin(); rit!=a.rend(); ++rit)
        {
            if(rit->second>=4)
            {
                temp1=temp1*rit->first*rit->first;
                ans=max(temp1,ans);
                temp1=1;
            }
            if(rit->second>=2)
            {
                temp=temp*rit->first;
                ctr++;
                if(ctr==2)
                {
                    ans=max(temp,ans);
                    temp=1;
                    ctr=0;
                }
            }
        }
        pi(ans);
    }
	return 0;
}
