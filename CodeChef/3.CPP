#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int n,k,t,sum=0,i;
    scanf("%d%d", &n, &k);
    if(n>10000000 || k>10000000)
        printf("Wrong Input");
    for(i=0; i<n; i++)
    {
        scanf("%d",&t);
        if(t>1000000000)
            printf("Wrong Input");
        if(t%k==0)
            sum++;
    }
    printf("%d",sum);
    return 0;
}
