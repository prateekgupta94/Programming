#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
void qst(int x[10],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(x[i]<=x[pivot]&&i<last)
                i++;
            while(x[j]>x[pivot])
                j--;
            if(i<j)
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        qst(x,first,j-1);
        qst(x,j+1,last);

    }
}
int main()
{
    int i,j,n,m,c,u[1010],l[1010],ctr[1010],ans[1010],pr[4995];
    scanf("%d%d%d", &n, &m, &c);
    for(i=0; i<n; i++)
        scanf("%d", &u[i]);
    for(i=0; i<m; i++)
        scanf("%d", &l[i]);
    qst(u,0,n-1);
    qst(l,0,m-1);
    for(i=0; i<c; i++)
        ctr[i]=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(u[i]==l[j])
                ctr[u[i]-1]++;
        }
    }
    for(i=0; i<c; i++)
        ans[i]=0;
    ans[0]=ctr[0]*ctr[1] + ctr[0]*ctr[2] + ctr[0]*ctr[3] + ctr[0]*ctr[4] + ctr[1]*ctr[2] + ctr[1]*ctr[3] + ctr[1]*ctr[4] + ctr[2]*ctr[3] + ctr[2]*ctr[4] + ctr[3]*ctr[4];
    ans[1]=ctr[0]*ctr[1]*ctr[2] + ctr[0]*ctr[1]*ctr[3] + ctr[0]*ctr[1]*ctr[4] + ctr[0]*ctr[2]*ctr[3] + ctr[0]*ctr[2]*ctr[4] + ctr[0]*ctr[3]*ctr[4] + ctr[1]*ctr[2]*ctr[3] + ctr[1]*ctr[2]*ctr[4] + ctr[1]*ctr[3]*ctr[4] + ctr[2]*ctr[3]*ctr[4];
    ans[2]=ctr[0]*ctr[1]*ctr[2]*ctr[3] + ctr[0]*ctr[1]*ctr[2]*ctr[4] + ctr[0]*ctr[1]*ctr[3]*ctr[4] + ctr[0]*ctr[2]*ctr[3]*ctr[4] + ctr[1]*ctr[2]*ctr[3]*ctr[4];
    ans[3]=ctr[0]*ctr[1]*ctr[2]*ctr[3]*ctr[4];
    for(i=0; i<c; i++)
    {
        for(j=0; j<(c*(c-1))/2; j++)
        {
            ans[i]+=pr[j];
        }
        k+=2;
    }
    for(i=0; i<c; i++)
        printf("\n%d\n", ans[i]%1000000007);
    return 0;
}
