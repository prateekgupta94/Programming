#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    int t,j,ans,ch[27];
    scanf("%d", &t);
    char s[100020];
    while(t--)
    {
        for(j=0; j<26; j++)
            ch[j]=97+j;
        ans=0;
        scanf("%s", s);
        for(j=0; s[j]!='\0'; j++)
        {
            if((int)s[j]==ch[(int)s[j]-97])
            {
                ch[(int)s[j]-97]=0;
                ans++;
            }
        }
        if(ans%2==0)
            printf("\nTerrorist");
        else if(ans%2!=0)
            printf("\nCounter Terrorist");
    }
	return 0;
}
