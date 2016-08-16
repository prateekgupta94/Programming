#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i;
	scanf("%d", &t);
    while(t--)
    {
        int n,ans=0,temp;
        scanf("%d", &n);
        int a[10010],b[10010];
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
            if(i==0)
                temp=a[i];
            else
            {
                a[i]=a[i]-temp;
                temp+=a[i];
            }
        }
        for(i=0; i<n; i++)
            scanf("%d", &b[i]);
        for(i=0; i<n; i++)
        {
            if(a[i]>=b[i])
                ans++;
        }
        printf("%d\n", ans);
    }
	return 0;
}
