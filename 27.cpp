#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int t,i,j,n,ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        ans=n;
        int a[n];
        long long prod,sum;
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n; i++)
        {
        prod=1;
        sum=a[i];
        prod=prod*a[i];
        for (j = i+1; j < n; j++)
        {
            sum+=a[j];
            prod=prod*a[j];
            if (sum == prod)
                ans++;
        }
        }
        printf("\n%d\n", ans);
    }
    return 0;
}
