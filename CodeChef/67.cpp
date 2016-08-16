#include<bits/stdc++.h>
using namespace std;

int n,m,temp[1010][1010],imp[1000010];

void row(int arr[1010][1010], int b)
{
    deque<int> Qi;
    int i,j,x=-1,y=0;
    for(j=0; j<n; j++)
    {
        Qi.clear();
        x++,y=0;
        for (i=0; i<b; ++i)
        {
            while ((!Qi.empty()) && arr[j][i]>=arr[j][Qi.back()])
                Qi.pop_back();
            Qi.push_back(i);
        }
        for ( ; i<m; ++i)
        {
            temp[x][y++]=arr[j][Qi.front()];
            while ((!Qi.empty()) && Qi.front()<=i-b)
                Qi.pop_front();
            while ((!Qi.empty()) && arr[j][i]>=arr[j][Qi.back()])
                Qi.pop_back();
            Qi.push_back(i);
        }
        temp[x][y]=arr[j][Qi.front()];
    }
}

void col(int a, int b)
{
    deque<int> Qi;
    int i,j,x=0;
    for(j=0; j<m-b+1; j++)
    {
        Qi.clear();
        for (i=0; i<a; ++i)
        {
            while ((!Qi.empty()) && temp[i][j]>=temp[Qi.back()][j])
                Qi.pop_back();
            Qi.push_back(i);
        }
        for ( ; i<n; ++i)
        {
            imp[x++]=temp[Qi.front()][j];
            while ((!Qi.empty()) && Qi.front()<=i-a)
                Qi.pop_front();
            while ((!Qi.empty()) && temp[i][j]>=temp[Qi.back()][j])
                Qi.pop_back();
            Qi.push_back(i);
        }
        imp[x++]=temp[Qi.front()][j];
    }
}

int solve(int mat[1010][1010], int a, int b)
{
    int ans=1000000007,temp1=0,sub=(n+1-a)*(m+1-b);
    int x=0,x1=0,y1=0,ctr1=-a,ctr2=0,ctr3=0;
    while(sub--)
    {
        while(ctr1!=a)
        {
            while(ctr2!=b)
            {
                temp1+=(imp[x]-mat[x1][y1++]);
                ctr2++;
                ctr3++;
            }
            x1++;
            y1-=b;
            ctr2=0;
            if(ctr3!=(a*b))
                ctr1=-(a+1);
            else
            {
                x++;
                break;
            }
            ctr1++;
        }
        ans=min(ans,temp1);
        ctr1=-a,ctr2=0;
        ctr3=0,temp1=0;
        if(x1!=n)
            x1=x1+1-a;
        else
        {
            x1=0;
            y1++;
        }
    }
    return ans;
}

int main()
{
	int i,j,q;
	scanf("%d%d", &n, &m);
	int mat[1010][1010];
	for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d", &mat[i][j]);
    scanf("%d", &q);
    while(q--)
    {
        int a,b,ans;
        scanf("%d%d", &a, &b);
        row(mat,b);
        col(a,b);
        ans=solve(mat,a,b);
        printf("%d\n", ans);
    }
	return 0;
}
