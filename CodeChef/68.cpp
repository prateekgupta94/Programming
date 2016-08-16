#include<bits/stdc++.h>
using namespace std;

long long mod=1000000007;
long long modl(long long a)
{
    return (a%mod);
}

int main()
{
    long long i,n,q;
    scanf("%lld", &n);
    long long f[100010];
    double logarr[100010];
    for(i=0; i<n; i++)
    {
        scanf("%lld", &f[i]);
        logarr[i]=log10(f[i]);
    }
    scanf("%lld", &q);
    while(q--)
    {
        long long t,x,r,p,ans2=1,ans1;
        double temp=0;
        scanf("%lld", &t);
        if(t==1)
        {
            scanf("%lld%lld", &p, &x);
            f[p-1]=x;
            logarr[p-1]=log10(x);
        }
        else
        {
            scanf("%lld", &r);
            if(n<=10)
            {
                long long city=0,no=0,ctr;
                long long enj=1;
                while(city<n)
                {
                    enj=modl(enj*f[city]);
                    city+=r;
                }
                ctr=enj;
                while(ctr>0)
                {
                    if(ctr>=10)
                        ctr=ctr/10;
                    else
                    {
                        no=ctr;
                        break;
                    }
                }
                printf("%lld %lld\n", no, enj);
            }
            else
            {
                for(i=0; i<n; i+=r)
                {
                    temp+=logarr[i];
                    ans2=modl(ans2*f[i]);
                }
                temp=temp-(int)temp;
                if(temp>=0 && temp<0.30102999566)
                    ans1=1;
                else if(temp>=0.30102999566 && temp<0.47712125472)
                    ans1=2;
                else if(temp>=0.47712125472 && temp<0.60205999132)
                    ans1=3;
                else if(temp>=0.60205999132 && temp<0.69897000433)
                    ans1=4;
                else if(temp>=0.69897000433 && temp<0.77815125038)
                    ans1=5;
                else if(temp>=0.77815125038 && temp<0.84509804001)
                    ans1=6;
                else if(temp>=0.84509804001 && temp<0.90308998699)
                    ans1=7;
                else if(temp>=0.90308998699 && temp<0.95424250943)
                    ans1=8;
                else if(temp>=0.95424250943 && temp<1)
                    ans1=9;
                printf("%lld %lld\n", ans1, ans2);
            }
        }
    }
	return 0;
}
