#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    int a,b,i,ans;
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
        ans=0;
        scanf("%d%d", &a, &b);
        if(a<b)
        {
            if(a%2==0 && a%3!=0 && a%5!=0 && a%7!=0)
                while(a!=b)
                {
                    a=a*2;
                    ans++;
                }
            else
                printf("No Answer");
        }
        else if(a==b)
            ans=0;
        else
        {
            if(a%2==0 && a%3!=0 && a%5!=0 && a%7!=0)
                while(a!=b)
                {
                    a=a/2;
                    ans++;
                }
            else
                printf("No Answer");
        }
        printf("%d", ans);
    }
	return 0;
}

