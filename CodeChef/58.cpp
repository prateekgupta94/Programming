#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

float p=1.618033,mp=-0.618033,invr5=0.447213;

float modd(float a)
{
int result = static_cast<int>(a/mod);
return a - static_cast<float>(result)*mod;
}

long long modl(long long a)
{
    return (a%mod);
}

long long roundNo(double num)
{
    return num < 0 ? num - 0.5 : num + 0.5;
}

float power(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}

int main()
{
    long long n,m,i,j;
    scanf("%lld%lld", &n, &m);
    long long a[100010];
    for(i=0; i<n; i++)
        scanf("%lld", &a[i]);
    char q;
    for(i=0; i<m; i++)
    {
        long long l,r;
        fflush(stdin);
        scanf("%c%lld%lld", &q, &l, &r);
        if(q==67)
            a[l-1]=r;
        else
        {
            float phi[2],mphi[2],x;
            x=0;
            phi[0]=1;
            mphi[0]=1;
            for(j=0; j<r-l+1; j++)
            {
                float t1=modd(pow(p,a[l+j-1])) , t2=modd(pow(mp,a[l+j-1]));
                phi[1]=modd((phi[0])*(t1+1));
                mphi[1]=modd((mphi[0])*(t2+1));
                x=modd(x + invr5*(modd(t1*phi[0]) - modd(t2*mphi[0])));
                phi[0]=phi[1];
                mphi[0]=mphi[1];
            }
            printf("%lld\n", roundNo(x));
        }
    }
    return 0;
}
