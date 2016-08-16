#include<bits/stdc++.h>

int a[510][2505];

int ques1(int xl, int xr, int yl, int yr, int x, int y)
{
    int ans;
    printf("%d %d %d %d %d %d %d\n", 1, xl, xr, yl, yr, x, y);
    fflush(stdout);
    scanf("%d", &ans);
    return ans;
}

int ques2(int xl, int xr, int yl, int yr)
{
    int sum;
    printf("%d %d %d %d %d\n", 2, xl, xr, yl, yr);
    fflush(stdout);
    scanf("%d", &sum);
    return sum;
}

void eval(int xl, int xr, int yl, int yr, int x, int y, int ans, int sum)
{
    int nos=(xr-xl+1)*(yr-yl+1);
    int i,j,ndiff,sdiff,avg;
    if(x==y)
    {
        if(ans==nos)
        {
            for(i=xl-1; i<xr; i++)
                for(j=yl-1; j<yr; j++)
                    a[i][j]=x;
        }
        else
        {
            ndiff=nos-ans;
            sdiff=sum-x*ans;
            avg=sdiff/ndiff;
            for(i=xl-1; i<xr; i++)
            {
                for(j=yl-1; j<yr; j++)
                {
                    if(sdiff!=0 && ndiff!=0)
                    {
                        if(sdiff>=avg && ndiff>0)
                        {
                            a[i][j]=avg;
                            sdiff-=avg;
                        }
                        else if(ndiff==1)
                        {
                            a[i][j]=sdiff;
                            sdiff=0;
                        }
                        else
                        {
                            avg=sdiff/ndiff;
                            a[i][j]=avg;
                            sdiff-=avg;
                        }
                        ndiff--;
                    }
                    else
                        a[i][j]=x;
                }
            }
        }
    }
}

int main()
{
    int n,m,c,ans,sum,i,j,x=1,y=1;
    scanf("%d%d%d", &n, &m, &c);
    for(i=1; i<=n; i++)
    {
        ans=ques1(i,i,1,m,x,y);
        while(ans==0)
        {
            x++;
            y++;
            ans=ques1(i,i,1,m,x,y);
        }
        if(ans==m)
            sum=m*x;
        else
            sum=ques2(i,i,1,m);
        eval(i,i,1,m,x,y,ans,sum);
        if(x!=1 && y!=1)
        {
            x=1;
            y=1;
        }
    }
    printf("3\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d ", a[i][j]);
            fflush(stdout);
        }
        printf("\n");
    }
    return 0;
}
