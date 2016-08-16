#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
    while(t--)
    {
        int i,n,chz=0,cho=0;
        bool ones=true,zeros=true;
        char sa[1000010],sb[1000010];
        scanf("%s%s", sa, sb);
        n=strlen(sa);
        for (i=0; i<n; i++)
        {
            if((sa[i]-'0')==0)
                ones=false;
            else
                zeros=false;
            if(sa[i]!=sb[i])
            {
                if(sa[i]=='0')
                    chz++;
                else
                    cho++;
            }
        }
        if(n==1)
            printf("Unlucky Chef\n");
        else
        {
            if(ones==true || zeros==true)
                printf("Unlucky Chef\n");
            else if(cho==chz || cho>chz)
            {
                printf("Lucky Chef\n");
                printf("%d\n", cho);
            }
            else if(cho<chz)
            {
                printf("Lucky Chef\n");
                printf("%d\n", chz);
            }
        }
    }
	return 0;
}

