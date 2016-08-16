#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    unsigned int n;
    int x,i,t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
            printf("\n2");
        else
        {
            x=n+1;
            while(x%2==0 && x>1)
                x=x/2;
            if(x!=1)
                printf("\n-1");
            else
                printf("\n%d",n/2);
        }
    }
    return 0;
}
