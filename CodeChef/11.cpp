#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<stdio.h>
using namespace std;

int main()
{
    int t,i=0,ans,s;
    char a[200010], b[200010];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s%s", a, b);
        ans=0;
        s=0;
        for(i=0; a[i]!='\0'; i++)
        {
            if(a[i]=='#' && b[i]=='#')
            {
                s=0;
                printf("\nNo");
                break;
            }
            else if(a[i]=='.' && b[i]=='#')
            {
                if(a[i+1]=='.')
                {
                    s=1;
                    continue;
                }
                else if(a[i+1]=='#' && b[i+1]=='.')
                {
                    if(s=1)
                    {
                        ans++;
                        s=2;
                    }
                }
                else if(a[i+1]=='#' && b[i+1]=='#')
                {
                    s=0;
                    printf("\nNo");
                    break;
                }
                else
                    s=-1;
            }
            else if(a[i]=='#' && b[i]=='.')
            {
                if(b[i+1]=='.')
                {
                    s=2;
                    continue;
                }
                else if(b[i+1]=='#' && a[i+1]=='.')
                {
                    if(s=2)
                    {
                        ans++;
                        s=1;
                    }
                }
                else if(b[i+1]=='#' && a[i+1]=='#')
                {
                    s=0;
                    printf("\nNo");
                    break;
                }
                else
                    s=-1;
            }
            else if(a[i]=='.' && b[i]=='.')
            {
                if(a[i+1]=='#' && b[i+1]=='#')
                {
                    s=0;
                    printf("\nNo");
                    break;
                }
                else if(a[i+1]=='.' && b[i+1]=='#')
                {
                    if(s==2)
                    {
                        ans++;
                        s=1;
                    }
                }
                else if(a[i+1]=='#' && b[i+1]=='.')
                {
                    if(s==1)
                    {
                        ans++;
                        s=2;
                    }
                }
                else if(a[i+1]=='.' && b[i+1]=='.')
                {
                    if(s==0)
                        s=-1;
                    continue;
                }
                else
                    s=-1;
            }
        }
        if(s!=0)
        printf("\nYes\n%d", ans);
    }
	return 0;
}
