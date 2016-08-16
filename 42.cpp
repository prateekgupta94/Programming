#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int k,g=0,s=0;
    scanf("%d", &k);
    if(k-493<0)
    {
        g=0;
        if(k-29<0)
            s=0;
        else
        {
            while(k>=29)
            {
                k=k-29;
                s++;
            }
        }
    }
    else if(k-493>=0)
    {
        while(k>493)
        {
            k=k-493;
            g++;
        }
        while(k>=29)
        {
            k=k-29;
            s++;
        }
    }
    printf("%d galleons %d sickles %d knuts", g, s, k);
    return 0;
}
