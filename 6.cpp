 #include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int t,n,k,i,j,calc,ctr,flag=0;
    scanf("%d", &t);
    if(t<1 || t>10)
        return 0;
    for(i=0; i<t; i++)
    {
        flag=0;
        calc=0;
        ctr=0;
        scanf("%d%d", &n, &k);
        if(n<1 || n>100)
            return 0;
        if(k<1 || k>100)
            return 0;
        int a[n];
        for(j=0; j<n; j++)
        {
            scanf("%d", &a[j]);
            if(a[j]<1 || a[j]>100)
                return 0;
            if(a[j]==k)
                flag++;
            ctr+=a[j];
        }
        calc=floor((ctr+n-flag)/k);
            /*if(j==0 || ctr==0)
            {
            if(a[j]>k)
            {
                flag=a[j];
                while(flag!=0)
                {
                    if(flag>=k)
                    {
                        flag=flag-k;
                        calc++;
                    }
                    else
                        break;
                }
            }
            else if(a[j]<k)
                ctr=k - a[j];
            else
                calc++;
            if(ctr>0)
            {
                ctr--;
                if(ctr==0)
                    calc++;
            }
            }

            else
            {
            if((a[j]+ctr)>k)
            {
                flag=a[j]+ctr;
                while(flag!=0)
                {
                    if(flag>=k)
                    {
                        flag=flag-k;
                        calc++;
                    }
                    else
                        break;
                }
            }
            else if((a[j]+ctr)<k)
                ctr=k - a[j];
            else
                calc++;
            if(ctr>0)
            {
                ctr--;
                if(ctr==0)
                    calc++;
            }
            }
        }*/
        printf("\n%d", calc);
    }
    return 0;
}
/*Some chefs go for a tour lasting N days. They take packages of bread for food. Each package has K pieces of breads. On the ith day, they eat Ai pieces of bread.
Let us take an example. If K = 4 and N = 3, then A = {3, 1, 2}.
Chefs have packages of bread each having 4 pieces of bread, and their travel lasts 3 days.
In the first day, they must eat 3 pieces of bread. So they open new package of bread and eat 3 pieces.
They forget to close the package, so the 4th piece becomes bad. In the next day, they want to eat one piece of bread.
And in the first package we don't have any good pieces of bread left, so they open a new package of bread and eat one piece from that.
On the 3rd day, they want to eat 2 pieces of bread.
In the second package, we have three pieces, and one of them is bad; so we have 2 good pieces.
They eat 2 pieces from this package. So they must buy 2 packages of bread.*/
