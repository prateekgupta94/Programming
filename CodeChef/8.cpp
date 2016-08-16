#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int n,si,ti,i;
    scanf("%d", &n);
    if(n<1 || n>10000)
        return 0;
    int ctr[n],lead[n],win,mlead;
    for(i=0; i<n; i++)
    {
        scanf("%d%d", &si, &ti);
        if(si>ti)
        {
            lead[i]=si-ti;
            ctr[i]=1;
            if(i==0)
            {
                win=ctr[i];
                mlead=lead[i];
            }
        }
        else if(si<ti)
        {
            lead[i]=ti-si;
            ctr[i]=2;
            if(i==0)
            {
                win=ctr[i];
                mlead=lead[i];
            }
        }
        else if(i>0)
        {
            if(mlead<lead[i])
            {
                mlead=lead[i];
                win=ctr[i];
            }
        }
        else
            continue;
    }
    printf("%d %d", win, mlead);
    return 0;
}
