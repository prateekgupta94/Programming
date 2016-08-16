#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	scanf("%lld", &t);
	while(t--)
    {
        long long k,ans;
        scanf("%lld", &k);
        k--;
        long long rem[30],imp[30],i,temp=1;
        for(i=0; i<20; i++)
        {
            imp[i]=temp;
            temp=temp*5;
        }
        if(k==0)
            printf("0\n");
        else
        {
            for(i=19; i>=0; i--)
            {
                if(imp[i]>k)
                    rem[i]=0;
                else
                {
                    rem[i]=k/imp[i];
                    k=k%imp[i];
                }
            }
            temp=1,ans=0;
            for(i=0;i<19;i++)
            {
                ans+=temp*rem[i];
                temp=temp*10;
            }
            ans=ans*2;
            printf("%lld\n", ans);
        }
    }
	return 0;
}
