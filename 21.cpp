#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int abs(int n)
{
    if(n>=0)
        return n;
	return -n;
}
int main()
{
    int n,i,j,ans[100005];
    scanf("%d", &n);
    int x[2][100005];
    for(i=0; i<2; i++)
    {
        for(j=0; j<n; j++)
            scanf("%d", &x[i][j]);
    }
    ans[0]=abs(x[0][0]-x[1][0]);
	ans[1]=max(abs(x[0][0]-x[0][1])+abs(x[1][0]-x[1][1]), abs(x[0][0]-x[1][0])+abs(x[0][1]-x[1][1]));
	for(i=2; i<n; i++)
		ans[i]=max(ans[i-1]+abs(x[0][i]-x[1][i]), ans[i-2]+abs(x[0][i]-x[0][i-1])+abs(x[1][i]-x[1][i-1]));
	printf("%d\n", ans[n-1]);
    return 0;
}
