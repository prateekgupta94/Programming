#include <bits/stdc++.h>

/* I/O Commands */
#define si(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define ss(x) scanf(" %[^\n]", x)
#define slf(n) scanf("%lf", &n)
#define pi(n) printf("%d", n)
#define pl(n) printf("%lld", n)
#define plf(n) printf("%0.9lf", n)
#define ps printf(" ")
#define pe printf("\n")

/* Containers */
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define sti set<int>
#define stpii set<pii>
#define mii map<int,int>
#define mll map<ll,ll>

/* Containers element */
#define f first
#define s second
#define fr front
#define s second
#define pb push_back
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define iter(it,s) for(auto it=s.begin(); it!=s.end(); it++)
#define riter(rit,s) for(auto rit=s.crbegin(); rit!=s.crend(); rit++)

/* Constants */
#define INF 1000000000000000000
#define MOD 786433
#define PI 3.14159265358979323846
#define mod(a) ((a)%MOD)

using namespace std;

int main()
{
	ll t;
	sl(t);
	while(t--)
    {
        ll n,i,ans=0,temp=0;
        sl(n);
        ll a[10010],b[10010],c[10010];
        for(i=0; i<n; i++)
        {
            sl(c[i]);
            b[i]=c[i];
        }
        for(i=0; i<n; i++)
            sl(a[i]);
		b[n]=c[n]=0;
        ll a0=a[0],a0c0=a[0]+c[0],a0c1=a[0]+c[1],acc=a[0]+c[0]+c[1];
        for(i=1; i<=n; i++)
        {
            if(i==n)
            {
                temp=a0;
                break;
            }
            if(a[i]==a0)
                continue;
            if(a[i]+b[i-1]==a0)
            {
                b[i-1]=0;
			    continue;
            }
            if(a[i]+b[i-1]+b[i]==a0)
            {
                b[i-1]=0;
                b[i]=0;
			    continue;
            }
            if(a[i]+b[i-1]+b[i]+b[i+1]==a0)
            {
                b[i-1]=0;
                b[i]=0;
                b[i+1]=0;
			    continue;
            }
            if(a[i]+b[i]==a0)
            {
                b[i]=0;
                continue;
            }
            if(a[i]+b[i-1]+b[i+1]==a0)
            {
                b[i-1]=0;
                b[i+1]=0;
			    continue;
		    }
		    if(a[i]+b[i+1]==a0)
		    {
			    b[i+1]=0;
			    continue;
            }
		    if(a[i]+b[i+1]+b[i]==a0)
		    {
			    b[i]=0;
                b[i+1]=0;
			    continue;
            }
            break;
        }
        for(i=0; i<n; i++)
        {
            if(b[i]!=0)
            {
                temp=0;
                break;
            }
        }
        ans=max(temp,ans);
        for(i=0; i<=n; i++)
            b[i]=c[i];
        b[0]=0;
	    for(i=1; i<=n; i++)
        {
            if(i==n)
		    {
                temp=a0c0;
			    break;
		    }
		    if(a[i]==a0c0)
                continue;
		    if(a[i]+b[i-1]+b[i]==a0c0)
		    {
                b[i-1]=0;
                b[i]=0;
                continue;
            }
            if(a[i]+b[i-1]+b[i+1]==a0c0)
            {
                b[i-1]=0;
                b[i+1]=0;
                continue;
            }
            if(a[i]+b[i-1]==a0c0)
		    {
                b[i-1]=0;
                continue;
            }
            if(a[i]+b[i-1]+b[i]+b[i+1]==a0c0)
		    {
		        b[i-1]=0;
                b[i]=0;
                b[i+1]=0;
                continue;
            }
            if(a[i]+b[i]==a0c0)
            {
                b[i]=0;
                continue;
            }
            if(a[i]+b[i+1]==a0c0)
            {
                b[i+1]=0;
                continue;
            }
            if(a[i]+b[i+1]+b[i]==a0c0)
            {
                b[i]=0;
                b[i+1]=0;
                continue;
            }
            break;
        }
        for(i=0; i<n; i++)
        {
            if(b[i]!=0)
            {
                temp=0;
	 		    break;
	 	    }
	    }
        ans=max(temp,ans);
        for(i=0; i<=n; i++)
            b[i] = c[i];
        b[1]=0;
        for(i=1;i<=n;i++)
        {
            if(i==n)
		    {
                temp=a0c1;
                break;
            }
            if(a[i]==a0c1)
                continue;
            if(a[i]+b[i-1]==a0c1)
	     	{
		     	b[i-1]=0;
	    		continue;
		    }
		    if(a[i]+b[i-1]+b[i]==a0c1)
		    {
                b[i-1]=0;
			    b[i]=0;
			    continue;
		    }
		    if(a[i]+b[i-1]+b[i+1]==a0c1)
		    {
			     b[i-1]=0;
			     b[i+1]=0;
			     continue;
		    }
            if(a[i]+b[i-1]+b[i]+b[i+1]==a0c1)
		    {
		        b[i-1]=0;
                b[i]=0;
                b[i+1]=0;
                continue;
            }
            if(a[i]+b[i]==a0c1)
            {
                b[i]=0;
                continue;
            }
            if(a[i]+b[i+1]==a0c1)
            {
                b[i+1]=0;
                continue;
            }
            if(a[i]+b[i+1]+b[i]==a0c1)
            {
                b[i]=0;
                b[i+1]=0;
                continue;
            }
            break;
        }
        for(i=0; i<n; i++)
        {
            if(b[i]!=0)
            {
                temp=0;
                break;
            }
        }
        ans=max(temp,ans);
        for(i=0; i<=n; i++)
            b[i]=c[i];
	    b[0]=0;
      	b[1]=0;
        for(i=1; i<=n; i++)
        {
            if(i==n)
		    {
                temp=acc;
                break;
            }
            if(a[i]==acc)
                continue;
            if(a[i]+b[i-1]==acc)
		    {
                b[i-1]=0;
			    continue;
		    }
            if(a[i]+b[i-1]+b[i]==acc)
		    {
			    b[i-1]=0;
			    b[i]=0;
			    continue;
		    }
		    if(a[i]+b[i-1]+b[i+1]==acc)
		    {
			    b[i-1]=0;
			    b[i+1]=0;
			    continue;
		    }
            if(a[i]+b[i-1]+b[i]+b[i+1]==acc)
		    {
		        b[i-1]=0;
                b[i]=0;
			    b[i+1]=0;
			    continue;
		    }
		    if(a[i]+b[i]==acc)
		    {
                b[i]=0;
			    continue;
		    }
		    if(a[i]+b[i+1]==acc)
		    {
                b[i+1]=0;
			    continue;
		    }
            if(a[i]+b[i+1]+b[i]==acc)
		    {
			    b[i]=0;
			    b[i+1]=0;
			    continue;
		    }
            break;
        }
        for(i=0; i<n; i++)
        {
            if(b[i]!=0)
	 	    {
                temp=0;
                break;
	 	    }
	    }
	    ans=max(temp,ans);
        if(ans!=0)
            pl(ans);
        if(ans==0)
        {
            ans=-1;
            pl(ans);
        }
        pe;
	}
	return 0;
}
