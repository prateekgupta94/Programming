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

vpii p[21];
vpii path;
int a[110][110],robo1[110][110],robo2[110][110];

int check(int i, int j, int n, int m)
{
	if(i>0 && i<=n && j>0 && j<=m)
	  return 1;
	else
	  return 0;
}

void solve(int n, int m, int x, int y, int robo[110][110], int k)
{
    int i,j,temp=0,x1,y1,x2,y2;
	path.clear();
	robo[x][y]=0;
	path.pb(mp(x,y));
	while(temp<(int)path.size())
	{
		x1=path[temp].f;
		y1=path[temp].s;
		for (i=1; i<=k; i++)
		{
			for(j=0; j<(int)p[i].size(); j++)
			{
			    x2=x1+p[i][j].f;
                y2=y1+p[i][j].s;
                if(check(x2,y2,n,m)==1)
                {
                    if(a[x2][y2]==0 && robo[x2][y2]==-1)
                    {
                        robo[x2][y2]=robo[x1][y1]+1;
                        path.pb(mp(x2,y2));
                    }
                }
			}
		}
		temp++;
	}
}

int main()
{
    int t;
	si(t);
	while(t--)
	{
	    int i,j,abss;
	    for(i=1; i<21; i++)
        {
            p[i].clear();
            for(j=-i; j<=i; j++)
            {
                abss=abs(j);
                p[i].pb(mp(j,i-abss));
                p[i].pb(mp(j,abss-i));
            }
        }
        p[0].clear();
        int n,m,k1,k2,ans=1000000007;
		si(n);si(m);si(k1);si(k2);
		for(i=0; i<=n+1; i++)
        {
            for(j=0; j<=m+1; j++)
			{
				a[i][j]=1;
				robo1[i][j]=-1;
				robo2[i][j]=-1;
			}
        }
		for (i=1; i<=n; i++)
            for (j=1; j<=m; j++)
                si(a[i][j]);
		if (k1==1 && k2==1)
		{
			solve(n,m,1,1,robo1,k1);
			if(robo1[1][m]>=0)
            {
                pi((robo1[1][m]/2)+(robo1[1][m]%2));
                pe;
            }
			else
            {
                pi(-1);
                pe;
            }
		}
		else
		{
			solve(n,m,1,1,robo1,k1);
			solve(n,m,1,m,robo2,k2);
			for(i=1; i<=n; i++)
            {
                for(j=1; j<=m; j++)
                {
                    if(robo1[i][j]!=-1 && robo2[i][j]!=-1)
                    {
                        if(max(robo1[i][j],robo2[i][j])<ans)
                            ans=max(robo1[i][j],robo2[i][j]);
                    }
                }
            }
			if(ans==1000000007)
            {
                pi(-1);
                pe;
            }
			else
            {
                pi(ans);
                pe;
            }
		}
	}
	return 0;
}
