#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n>=1 && n<=6)
            printf("-1\n");
        else
        {
            printf("%d\n", n);
            for(i=1; i<5; i++)
                printf("%d %d\n", i, i+1);
            printf("2 6\n");
            printf("4 6\n");
            for(i=7;i<=n;i++)
                printf("6 %d\n",i);
            printf("3\n");
        }
    }
    return 0;
}
