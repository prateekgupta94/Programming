#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define rep(a,c)   for ( int (a)=0; (a)<(c); (a)++)
#define repn(a,b,c)  for ( int (a)=(b); (a)<=(c); (a)++)
#define repd(a,b,c)  for (  int (a)=(b); (a)>=(c); (a)--)
#define MOD 1000000007
#define M(x,i) memset(x,i,sizeof(x))


int f[100005],a[100005];
ll s[100005];

ll binpow(ll a, ll b, ll m)
{
	ll res=1;
	while(b)
    {
    if(b&1)
    res=(res*a)%m;
    a=(a*a)%m;
    b>>=1;
	}
	return res;
}

int main()
{
int test_case;
cin>>test_case;
while(test_case--)
{
int n,maxa=-1;
cin>>n;
ll ans=1;
M(f,0);
rep(i,n)
{
 cin>>a[i];
 maxa=max(maxa,a[i]);
 f[a[i]]++;
}
 repd(i,maxa,1)
 {
 	int p1=f[i];
 	ll p2=0;
 	for(int j=2;j*i<=maxa;j++)
 		p1+=f[i*j],p2=(p2+s[i*j])%(MOD-1);
  ll subsets=(binpow(2,p1,MOD-1)-1-p2+MOD-1)%(MOD-1);
  ans=(ans*binpow(i,subsets,MOD))%MOD;
  s[i]=subsets;
 }
cout<<ans<<"\n";
}
return 0;
}
