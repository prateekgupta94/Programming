#include<bits/stdc++.h>
using namespace std;

long long mod=1000000007;
long long modl(long long a)
{
    return (a%mod);
}

long long bc(long long n, long long k)
{
    long long C[k+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = min(i, k); j > 0; j--)
            C[j] = modl(C[j] + C[j-1]);
    }
    return C[k];
}

int main()
{
    long long t,i,j;
    scanf("%lld", &t);
    while(t--)
    {
        map <char,int> ch;
        long long a,k,ans,len;
        scanf("%lld%lld", &a, &k);
        char str[110];
        scanf("%s", str);
        len=strlen(str);
        for(i=0; i<len; i++)
            ch[str[i]]++;
        if(a==1)
        {
            if(len>=3)
                printf("0\n");
            else
            {
                if(ch.size()==1)
                    printf("1\n");
                else if(ch.size()==2)
                {
                    if(k==0)
                        printf("0\n");
                    else
                        printf("1\n");
                }
            }
        }
        else if(a==2)
        {
            if(ch.size()==1)
            {
                if(k==0 && len<=2)
                    printf("1\n");
                else if(k==1 && len<=3)
                    printf("%lld\n", modl(len*25));
                else if(k==2 && len<=4)
                    printf("%lld\n", modl(bc(len,k)*25*25));
                else if(k==3 && len<=5)
                    printf("%lld\n", modl(3*bc(len,k)*25*25*24));
                else if(k==4 && len<=6)
                    printf("%lld\n", modl(6*bc(len,k)*25*25*24*24));
            }
        }
    }
    return 0;
}
