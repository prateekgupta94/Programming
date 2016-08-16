#include<bits/stdc++.h>
using namespace std;
map <char,int> q;
int main()
{
    int t,n,i;
    scanf("%d", &t);
    while(t--)
    {
        char s[100010];
        scanf("%d", &n);
        scanf("%s", s);
        q['R']=0;
        q['G']=0;
        q['B']=0;
        for(i=0; i<n; i++)
            q[s[i]]++;
        int temp=max(q['R'],q['G']);
        temp=max(temp,q['B']);
        printf("%d\n", n-temp);
    }
    return 0;
}
