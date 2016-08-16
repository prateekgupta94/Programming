#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int digit(int temp)
{
    int d=0;
    while(temp)
    {
        d++;
        temp=temp/10;
    }
    return d;
}
int main()
{
    int n,i,ans,d=0,temp;
    scanf("%d", &n);
    int j,ctr,pr=1,pd=1,flag=1;
    ctr=n;
    temp=ctr;
    if(n>98689)
    {
        flag=0;
        ans=1003001;
    }
    while(flag)
    {
        d=digit(ctr);
        int no[d];
        for(i=2; i<ctr-1; i++)
        {
            if(ctr%i==0)
            {
                pr=0;
                break;
            }
            else
                continue;
        }
        for(i=d-1; temp!=0; i--)
        {
            no[i]=temp%10;
            temp=temp/10;
        }
        j=d-1;
        for(i=0; i<d/2; i++)
        {
            if(no[i]!=no[j])
            {
                pd=0;
                break;
            }
            else
            {
                j--;
                continue;
            }
        }
        if(pr==1 && pd==1)
        {
            ans=ctr;
            flag=0;
        }
        else
        {
            pr=1;
            pd=1;
            ctr++;
            temp=ctr;
        }
    }
    printf("\n%d", ans);
    return 0;
}
