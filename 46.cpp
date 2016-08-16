#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int t,k,i;
    scanf("%d", &t);
    while(t--)
    {
        char s[110];
        int tmp=0,len;
        scanf("%s%d", s, &k);
        len=strlen(s);
        if(k==1)
            printf("YES\n");
        else if(k==2)
        {
            if((s[len-1]-48)%2==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if(k==3)
        {
            for(i=0; i<len; i++)
                tmp+=(s[i]-48);
            if(tmp%3==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if(k==4)
        {
            tmp=(10*(s[len-2]-48) + (s[len-1]-48));
            if(tmp%4==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if(k==5)
        {
            tmp=s[len-1]-48;
            if(tmp==0 || tmp==5)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if(k==6)
        {
            for(i=0; i<len; i++)
                tmp+=(s[i]-48);
            if((s[len-1]-48)%2==0 && tmp%3==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if(k==7)
        {
            for(i=len-1; i>=0; i-=6)
            {
                if(len>=6)
                    tmp+=(s[i]-48) + 3*(s[i-1]-48) + 2*(s[i-2]-48) + 6*(s[i-3]-48) + 4*(s[i-4]-48) + 5*(s[i-5]-48);
                else if(len==5)
                    tmp+=(s[i]-48) + 3*(s[i-1]-48) + 2*(s[i-2]-48) + 6*(s[i-3]-48) + 4*(s[i-4]-48);
                else if(len==4)
                    tmp+=(s[i]-48) + 3*(s[i-1]-48) + 2*(s[i-2]-48) + 6*(s[i-3]-48);
                else if(len==3)
                    tmp+=(s[i]-48) + 3*(s[i-1]-48) + 2*(s[i-2]-48);
                else if(len==2)
                    tmp+=(s[i]-48) + 3*(s[i-1]-48);
                else if(len==1)
                    tmp+=(s[i]-48);
                len-=6;
            }
            if(tmp%7==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if(k==8)
        {
            tmp=(100*(s[len-3]-48) + 10*(s[len-2]-48) + (s[len-1]-48));
            if(tmp%8==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if(k==9)
        {
            for(i=0; i<len; i++)
                tmp+=(s[i]-48);
            if(tmp%9==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if(k==10)
        {
            if((s[len-1]-48)==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
