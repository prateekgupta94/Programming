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
        double s,h,ctr,a,b,temp1,temp2,temp3;
        scanf("%lf%lf", &h, &s);
        temp1=h*h - 4*s;
        temp2=h*h + 4*s;
        temp3=(4*s)/(h*h);
        if(temp2<0 || temp1<0)
            printf("-1\n");
        else
        {
            ctr=0.5*asin(temp3);
            b=h*sin(ctr);
            a=h*cos(ctr);
            if(a>b)
                swap(a,b);
            printf("%lf %lf %lf\n", a, b, h);
        }
    }
	return 0;
}
