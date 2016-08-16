#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j;
    scanf("%d", &t);
    while(t--)
    {
        long long n,m;
        scanf("%lld%lld", &n, &m);
        if(n==1)
        {
            if(m!=2)
                printf("No\n");
            else
                printf("Yes\n");
        }
        else if(m==1)
        {
            if(n!=2)
                printf("No\n");
            else
                printf("Yes\n");
        }
        else if(n%2!=0 && m%2!=0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}

