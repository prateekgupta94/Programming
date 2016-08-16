#include<bits/stdc++.h>
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
using namespace std;
const int N = 100005;
const int INF = 1073741823;

int a[N];
int seg[3*N], seg2[3*N];

void build(int t, int i, int j)
{
    if (i==j)
    {
        seg[t] = a[i];
        seg2[t] = a[i];
        return;
    }
    int left = t<<1;
    int right = left|1;
    int mid = (i + j)/2;
    build(left, i, mid);
    build(right, mid+1, j);
    seg[t] = min(seg[left], seg[right]);
    seg2[t] = seg2[left] | seg2[right];
}

void update(int t, int i, int j, int l, int r, int val, int rev)
{
    if ((seg2[t] & rev)==0)
        return;
    if (i>r || j<l)
        return;
    if (i==j)
    {
        seg[t] = seg[t] & val;
        seg2[t] = seg2[t] & val;
        return;
    }
    int left = t<<1;
    int right = left|1;
    int mid = (i + j)/2;
    update(left, i, mid, l, r, val, rev);
    update(right, mid+1, j, l, r, val, rev);
    seg[t] = min(seg[left], seg[right]);
    seg2[t] = seg2[left] | seg2[right];
}

int query(int t, int i, int j, int l, int r)
{
    if (i>r || j<l)
        return INF;
    if (l<=i && j<=r)
        return seg[t];
    int left = t<<1;
    int right = left|1;
    int mid = (i + j)/2;
    int u = query(left, i, mid, l, r);
    int v = query(right, mid+1, j, l, r);
    return min(u, v);
}

int main()
{
    int n, q, l, r, t, x, ans;
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i)
        scanf("%d", &a[i]);
    build(1, 1, n);
    while(q--)
    {
        scanf("%d%d%d", &t, &l, &r);
        if (t==0)
        {
            ans = query(1, 1, n, l, r);
            printf("%d\n", ans);
        }
        else
        {
            scanf("%d", &x);
            update(1, 1, n, l, r, x, INF-x);
        }
    }
    return 0;
}
