#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
if(b==0)
return a;
else
return gcd(b,a%b);
}

int main()
{
    int t,n,i,q;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &q);
        int a[n],x[2*n],y[2*n];
        for(i=1; i<=n; i++)
            scanf("%d", &a[i]);
        x[1]=a[1];
        y[n]=a[n];
        for(int i=2;i<n;i++)
            x[i]=gcd(x[i-1],a[i]);
        for(int i=n-1;i>=1;i--)
            y[i]=gcd(y[i+1],a[i]);
        while(q--)
        {
	 	int l,r;
	 	scanf("%d%d",&l,&r);
	 	if(l==1)
        printf("%d\n",y[r+1]);
        else if(r==n)
        printf("%d\n",x[l-1]);
        else
        printf("%d\n",gcd(x[l-1],y[r+1]));
        }
    }
    return 0;
}

