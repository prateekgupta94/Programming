#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int n,k,i,j,num,ans=0;
    char a[12];
    scanf("%d%d", &n, &k);
    int x[1010];
    for(i=0; i<n; i++)
        x[i]=0;
    for(i=0; i<k; i++)
    {
        scanf("%s", a);
        if(strcmp(a,"CLICK")==0)
        {
            scanf("%d", &num);
            if(x[num-1]==0)
            {
                x[num-1]=1;
                ans++;
            }
            else if(x[num-1]==1)
            {
                x[num-1]=0;
                ans--;
            }
        }
        else
        {
            ans=0;
            for(j=0; j<n; j++)
                if(x[j]!=0)
                    x[j]=0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
