#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
/*Each color will be from the list {"black", "blue", "red", "green", "yellow", "orange"}
A single line of each test case contains six words denoting the colors of painted sides in the order: front, back, left, right, top and bottom, respectively.
8 YES CASES= {135 , 145 , 136 , 146 , 235 , 245 , 236 , 246}*/
using namespace std;
int main()
{
    int t,i,j,k,l,si[6],tmp;
    char co[6][10];
    scanf("%d", &t);
    if(t<1 || t>50000)
        return 0;
    int ans[t];
    for(j=0; j<t; j++)
    {
        for(i=0; i<6; i++)
        {
            scanf("%s", &co[i]);
            if(strcmp(co[i],"black")==0)
                si[i]=1;
            else if(strcmp(co[i],"blue")==0)
                si[i]=2;
            else if(strcmp(co[i],"red")==0)
                si[i]=3;
            else if(strcmp(co[i],"green")==0)
                si[i]=4;
            else if(strcmp(co[i],"yellow")==0)
                si[i]=5;
            else if(strcmp(co[i],"orange")==0)
                si[i]=6;
        }
        if( (si[0]==si[2] && si[2]==si[4]) || (si[0]==si[3] && si[3]==si[4]) || (si[0]==si[2] && si[2]==si[5]) || (si[0]==si[3] && si[3]==si[5]) || (si[1]==si[2] && si[2]==si[4]) || (si[1]==si[3] && si[3]==si[4]) || (si[1]==si[2] && si[2]==si[5]) || (si[1]==si[3] && si[3]==si[5]))
            ans[j]=1;
        else
            ans[j]=0;
    }
    for(j=0; j<t; j++)
    {
        if(ans[j]==0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
