#include<bits/stdc++.h>
int main()
{
    int d,i,j,mid,n,flag=0,c1=1,c2=1,k=0;
    char s[1000010];
    scanf("%d", &d);
    for(i=0; i<d; i++)
    {
        scanf("%s", s);
        n=strlen(s);
        if(n==1)
        {
            printf("NO\n");
            continue;
        }
        else if(n==3)
        {
            if(s[0]==s[1] || s[1]==s[2] || s[0]==s[2])
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if(n%2==0)
        {
            mid=n/2;
            for(j=0; j<n/2; j++)
            {
                if(s[j]!=s[mid+j])
                {
                    c1=0;
                    break;
                }
            }
            if(c1==1)
                printf("YES\n");
            else
                printf("NO\n");
            c1=1;
        }
        else
        {
            mid=n/2;
            j=mid;
            while(j<=n)
            {
                if(s[j]==s[k])
                {
                    j++;
                    k++;
                }
                else
                {
                    flag++;
                    j++;
                }
                if(flag>1)
                {
                    c1=0;
                    break;
                }
                else if(mid==k && j<=n)
                    break;
                else if(j==n)
                {
                    c1=0;
                    break;
                }
            }
            j=mid+1;
            flag=0;
            k=0;
            while(k<=mid)
            {
                if(s[j]==s[k])
                {
                    j++;
                    k++;
                }
                else
                {
                    flag++;
                    k++;
                }
                if(flag>1)
                {
                    c2=0;
                    break;
                }
                else if(j==n && k<=mid+1)
                    break;
                else if(k==mid+1)
                {
                    c2=0;
                    break;
                }
            }
            if(c1==1 || c2==1)
                printf("YES\n");
            else
                printf("NO\n");
            c1=1;
            c2=1;
            k=0;
            flag=0;
        }
    }
    return 0;
}
