#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct cyc
{
long long sp;
long long dist;
long long tm;
};
int main()
{
    cyc c[50001];
    long long user[50001],i,j,k,q,n,time,no,nsp,high=0;
    long long max,flag,maxsp,test,pr=0,win=0,topsp=0,prevt=-1,mintime=1000000001;
    scanf("%lld%lld", &n, &q);
    for(i=0; i<n; i++)
    {
        c[i].sp=0;
        c[i].tm=0;
        c[i].dist=0;
    }
    user[0]=0;
    while(q--)
    {
        scanf("%lld",&k);
        if(k==1)
        {
            scanf("%lld%lld%lld", &time, &no, &nsp);
            c[no-1].dist+=c[no-1].sp*(time-c[no-1].tm);
            c[no-1].tm=time;
            c[no-1].sp=nsp;
            if(nsp>topsp)
            {
                user[pr++]=no-1;
                topsp=nsp;
                if(no!=1 && ((float)(c[user[0]].dist+(c[user[0]].sp*(time-c[user[0]].tm))-c[no-1].dist)/(c[no-1].sp-c[user[0]].sp)+0.5+time) < mintime)
                    mintime=(float)(c[user[0]].dist+(c[user[0]].sp*(time-c[user[0]].tm))-c[no-1].dist)/(c[no-1].sp-c[user[0]].sp)+0.5+time;
            }
        }
        else
        {
            scanf("%lld",&time);
            if(prevt==time)
            {
                printf("%lld\n",max);
                continue;
            }
            prevt=time;
            if(prevt!=-1 && time<mintime)
            {
                printf("%lld\n",c[user[0]].dist+c[user[0]].sp*(time-c[user[0]].tm));
                continue;
            }
            max=c[user[0]].dist+=c[user[0]].sp*(time-c[user[0]].tm);
            c[user[0]].tm=time;
            maxsp=c[user[0]].sp;
            test=max;
            win=0;
            high=pr;
            for(i=1; i<pr; i++)
            {
                c[user[i]].dist+=c[user[i]].sp*(time-c[user[i]].tm);
                c[user[i]].tm=time;
                if(c[user[i]].dist>max)
                {
                    max=c[user[i]].dist;
                    win=i;
                }
                if(c[user[i]].sp>maxsp)
                {
                    maxsp=c[user[i]].sp;
                    test=c[user[i]].dist;
                }
            }
            printf("%lld\n",max);
            flag=user[win];
            user[win]=user[0];
            user[0]=flag;
            mintime=0;
            for(i=1,pr=1; i<high; i++)
            {
                if(c[user[i]].sp>c[user[0]].sp && c[user[i]].dist+c[user[i]].sp>=test+maxsp)
                {
                    user[pr]=user[i];
                    pr++;
                    if(pr==2)
                        mintime=(float)(c[user[0]].dist-c[user[i]].dist)/(c[user[i]].sp-c[user[0]].sp)+0.5;
                    if(pr>2)
                    {
                        if((float)(c[user[0]].dist-c[user[i]].dist)/(c[user[i]].sp-c[user[0]].sp)+0.5<mintime)
                            mintime=(float)(c[user[i]].dist-c[user[0]].dist)/(c[user[i]].sp-c[user[0]].sp)+0.5;
                    }
                }
            }
            mintime+=time;
        }
    }
    return 0;
}
