#include<bits/stdc++.h>
using namespace std;

int n,m,q,a,b;
int mat[1010][1010];
int temp[1010][1010];
int M[1010][1010][10][10];

int eval(int n)
{
    int ans = 0;
    while(n >>= 1)
        ans++;
    return ans;
}

int sum(int as, int bs, int ae, int be)
{
    return temp[ae+1][be+1] - temp[as][be+1] - temp[ae+1][bs] + temp[as][bs];
}

int magic(int x1, int y1, int x2, int y2, int k, int l)
{
    int ans = 0;
    ans = max(max(M[x1][y1][k][l],M[x2-(1<<k)+1][y1][k][l]), max(M[x1][y2-(1<<l)+1][k][l],M[x2-(1<<k)+1][y2-(1<<(l))+1][k][l]));
    return ans;
}

void preprocess()
{
    int i,j,x,y;
    temp[0][0] = 0;
    for(i = 0; i<n; i++)
        temp[i][0] = 0;
    for(i = 0; i<m; i++)
        temp[0][i] = 0;
    for(i = 1; i<=n; i++)
        for(j = 1; j<=m; j++)
            temp[i][j] = temp[i-1][j] + temp[i][j-1] - temp[i-1][j-1] + mat[i-1][j-1];
    for (i = 0; (1 << i) <= n; i++)
        for (j = 0; (1 << j)  <= m; j++)
            for (x = 0; x + (1<< i) - 1 < n; x++)
                for(y = 0; y + (1<<j) - 1 < m; y++)
                    if(i==0 && j == 0)
                        M[x][y][i][j] = mat[x][y];
                    else if(i==0)
                        M[x][y][i][j] = max(M[x][y][i][j-1], M[x][y+(1<<(j-1))][i][j-1]);
                    else if(j==0)
                        M[x][y][i][j] = max(M[x][y][i-1][j], M[x+(1<<(i-1))][y][i-1][j]);
                    else
                        M[x][y][i][j] = max(max(M[x][y][i-1][j-1],M[x+(1<<(i-1))][y][i-1][j-1]),max(M[x][y+(1<<(j-1))][i-1][j-1],M[x+(1<<(i-1))][y+(1<<(j-1))][i-1][j-1]));
}

int main()
{
    int i,j;
    scanf("%d%d", &n, &m);
    for(i = 0; i<n; i++)
        for(j = 0; j<m; j++)
            scanf("%d", &mat[i][j]);
    preprocess();
    scanf("%d", &q);
    while(q--)
    {
		int ans = 1000000007,temp1,temp2;
        scanf("%d%d", &a, &b);
        int k = eval(a);
        int l = eval(b);
        for(i = 0; i<=n-a; i++)
        {
            for(j = 0; j<=m-b; j++)
            {
				temp1 = magic(i,j,i+a-1,j+b-1,k,l);
				temp2 = sum(i,j,i+a-1,j+b-1);
                ans = min(ans,temp1*a*b - temp2);
            }
        }
        printf("%d\n", ans);
    }
	return 0;
}
