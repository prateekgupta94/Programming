#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,n,x,temp,d,dis=0;
    cin>>n>>x;
    temp=x;
    char ch;
    for(i=0; i<n; i++)
    {
        cin>>ch>>d;
        if(ch=='+')
            temp+=d;
        else
        {
            if(temp>=d)
                temp-=d;
            else
                dis++;
        }
    }
    cout<<temp<<" "<<dis<<endl;
	return 0;
}
