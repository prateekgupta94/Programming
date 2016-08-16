#include <bits/stdc++.h>
using namespace std;

int hor[1004],vert[1004];
int dp[512][250010];
int t,n,a,b,res,i,j,tmp;
char ch;

int solve(int ar[],int n)
{
    if(n<=0)
        return 0;
    int res=250005,tot=0;
    for(i=0;i<n;i++)
        tot=tot+ar[i];
    int sum=tot;
    tot=(tot+1)>>1;

    for(i=0;i<=n;++i)
        for(j=0;j<=tot;++j)
        dp[i][j]=0;

	dp[0][0]=1;
    for(i=1;i<=n;i++)
    {
        dp[i][0]=1;
        for(j=1;j<=tot;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=ar[i-1])
                dp[i][j]=(dp[i][j]||(dp[i-1][j-ar[i-1]]));
        }
    }
    for(i=0;i<=tot;i++)
    {
        if(dp[n][i]==1)
        res=min(res,abs(sum-(i<<1)));
    }
    return res;
}


int main()
{
    scanf("%d",&t);
    while(t--)
    {

        a=0;
        b=0;
        scanf("%d%d",&n, &tmp);
        vert[a]=tmp;
        a++;
        res=0;
        for(i=1;i<=n;i++)
        {
           scanf(" %c %d",&ch,&tmp);
            if(i&1)
            hor[b++]=tmp;
            else
            vert[a++]=tmp;
        }
        if(n<=2)
        printf("NO\n");
        else
        {
            res=solve(hor,b)+solve(vert,a);
            printf("%d\n",res);
        }
    }
	return 0;
}

