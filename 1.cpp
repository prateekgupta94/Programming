#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int t;
    cin>>t;
    if(t<1 || t>10000)
            cout<<"Wrong input";
    int n[t],sum[t],i,j,k;
    for(k=0; k<t; k++)
    {
        cin>>n[k];
        sum[k]=0;
        if(n[k]<1 || n[k]>50)
            cout<<"Wrong input";
        int di[n[k]];
        for(i=0; i<n[k]; i++)
            {
                cin>>di[i];
                if(di[i]<1 || di[i]>100)
                cout<<"Wrong input";
            }
        for(i=0; i<(n[k]-1); i++)
            {
                for(j=i+1; j<n[k]; j++)
                {
                    if(di[i]==di[j])
                    {
                        sum[k]++;
                        break;
                    }
                }
            }
    }
    for(i=0; i<t; i++)
    cout<<endl<<(n[i]-sum[i]);
    return 0;
}
