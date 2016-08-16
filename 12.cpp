#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    int t,i,ans;
    long double a[100],n;
    a[0]=1;
    a[1]=1;
    scanf("%d", &t);
    for(i=2; i<100; i++)
        a[i]=a[i-2]+a[i-1];
    while(t--)
    {
        ans=0;
        scanf("%Lf", &n);
        for(i=1; i<100; i++)
        {
            if(a[i]<=n)
                ans++;
            else
                break;
        }
        printf("\n%d", ans);
    }
	return 0;
}
