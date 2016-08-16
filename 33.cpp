#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int t,n,m,i,j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        char a[1005][1005];
        for(i=0; i<n; i++)
            scanf("%s", a[i]);
        int ctr=0,pn,qn,pm,qm=-1,ans;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(a[i][j]=='*')
                {
                    if(ctr==0)
                    {
                        pn=i;
                        pm=j;
                    }
                    if(j<pm)
                        pm=j;
                    ctr++;
                    qn=i;
                    if(j>qm)
                        qm=j;
                }
            }
        }
        n=qn-pn+1;
        m=qm-pm+1;
        if(ctr>1)
        {
            if(n==m)
            {
                if(n%2!=0)
                    ans=n - m/2;
                else if(n%2==0)
                    ans=n - m/2 + 1;
            }
            else if(n!=m)
            {
                if(n<m)
                    n=m;
                else if(n>m)
                    m=n;
                if(n%2!=0)
                    ans=n - m/2;
                else if(n%2==0)
                    ans=n - m/2 + 1;
            }
            printf("%d\n", ans);
        }
        else
            printf("%d\n", ctr);
    }
    return 0;
}
