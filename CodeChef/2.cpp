#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int n,q,k;
    int i,j,z;
    cin>>n;
    int si[n],ei[n];
    if(n<1 || n>100000)
            cout<<"Wrong input";
    for (i=0; i<n; i++)
    {
        cin>>si[i]>>ei[i];
        if(si[i]<1 || si[i]>1000000000 || ei[i]<1 || ei[i]>1000000000)
            cout<<"Wrong input";
        if(si[i]>ei[i])
            cout<<"Wrong input";
    }
    cin>>q;
    if(q<1 || q>5000)
            cout<<"Wrong input";
    int flag[q][n], ans[q];
    for(i=0; i<q; i++)
        for(j=0; j<n; j++)
        flag[i][j]=0;
    for(i=0; i<q; i++)
    {
        cin>>k;
        int t[k];
        if(k<1 || k>20)
            cout<<"Wrong input";
        for(j=0; j<k; j++)
            {
                cin>>t[j];
                if(t[j]<1 || t[j]>1000000000)
                    cout<<"Wrong input";
            }
        ans[i]=0;
        for(z=0; z<k; z++)
        {
            for(j=0; j<n; j++)
            {
                if(t[z]>=si[j] && t[z]<=ei[j] && flag[i][j]==0)
                {
                    ans[i]++;
                    flag[i][j]=1;
                }
            }
        }
    }
    for(i=0; i<q; i++)
    {
        cout<<"\n"<<ans[i];
    }
    return 0;
}
