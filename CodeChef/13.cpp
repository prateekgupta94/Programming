#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    int t,n,h,i,ans;
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        scanf("%d%d", &n, &h);
        int lo[n],hi[n],ch[2]={0,0};
        for(i=0; i<n; i++)
            scanf("%d%d", &lo[i], &hi[i]);
        for(i=0; i<n; i++)
        {
            if(i!=0)
            {
                if(hi[0]<hi[i])
                    ch[1]++;
                else if(lo[0]>lo[i])
                    ch[0]++;
            }
        }
        for(i=0; i<n; i++)
        {
            if(n<h)
            {
                ans=-1;
                break;
            }
            if(hi[i]-lo[i]+1>=h)
            {
                if(i>0 && lo[i-1]<=lo[i])
                {
                    ans+=lo[i]-lo[i-1];
                    lo[i]=lo[i-1];
                }
            }
            else if(hi[i]-lo[i]+1<h)
            {
                /*if(i!=0 && lo[i-1]<lo[i])
                {
                    ans+=lo[i]-lo[i-1];
                    lo[i]=lo[i-1];
                }*/
                if(i==0)
               {
                    if(hi[i]<n-1 && (n-hi[i])>=(h-hi[i]+lo[i]-1) && ch[0]<=ch[1])
                    {
                        ans+=(h-hi[i]+lo[i]-1);
                        hi[i]+=(h-hi[i]+lo[i]-1);
                    }
                    else if(lo[i]>=(h-hi[i]+lo[i]-1) && ch[0]>=ch[1])
                    {
                        ans+=(h-hi[i]+lo[i]-1);
                        lo[i]=lo[i]-(h-hi[i]+lo[i]-1);
                    }
                    else if(n-hi[i]+lo[i]>=h)
                    {
                        if(ch[0]>=ch[1])
                        {
                            hi[i]+=1;
                            ans++;
                        }
                        else if(ch[0]<ch[1])
                        {
                            lo[i]-=1;
                            ans++;
                        }
                    }
               }
               else
               {
                   if(hi[i]<n-1 && (n-hi[i])>=(h-hi[i]+lo[i]-1))
                    {
                        ans+=(h-hi[i]+lo[i]-1);
                        hi[i]+=(h-hi[i]+lo[i]-1);
                    }
                    else if(lo[i]>=(h-hi[i]+lo[i]-1))
                    {
                        ans+=(h-hi[i]+lo[i]-1);
                        lo[i]=lo[i]-(h-hi[i]+lo[i]-1);
                    }
                }
            }
        }
        if(ans!=-1)
            printf("\n%d", ans);
        else
            printf("\nNo Answer");
    }
	return 0;
}
