#include<bits/stdc++.h>
int main()
{
    int t,i,j;
    scanf("%d", &t);
    while(t--)
    {
        char a[1005],b[1005];
        scanf("%s%s", a, b);
        int l1=strlen(a);
        int l2=strlen(b);
        int ctr=0;
        for(i=0; i<l1; i++)
        {
            for(j=0; j<l2; j++)
            {
                if(a[i]==b[j])
                {
                    printf("Yes\n");
                    ctr=1;
                    break;
                }
            }
            if(ctr==1)
                break;
        }
        if(ctr==0)
            printf("No\n");
    }
    return 0;
}
