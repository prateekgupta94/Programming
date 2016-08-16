#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
        int t,n;
        scanf("%d", &t);
        while(t--)
        {
        scanf("%d", &n);
        int arr[n],sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &arr[i]);;
            sum+=arr[i];
        }
        int temp=sum/2;
        int dp[n+1][temp+2];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=temp;j++)
            {
                if(i==0 || j==0)
                dp[i][j]=0;
                else if(arr[i]<=j)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i]]+arr[i]);
                else
                {
                dp[i][j]=dp[i-1][j];
                }
            }
        }
        printf("%d\n",sum-2*dp[n][temp]);
        }
}
