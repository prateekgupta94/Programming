#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int n,i,j;
    scanf("%d", &n);
    int a[100005]={0};
    for(i=0; i<n; i++)
    {
        scanf("%d", &j);
        if(j!=0)
            a[j-1]++;
    }
    for(i=0; i<n; i++)
        if(a[i]==0)
            printf("%d ", (i+1));
    printf("\n");
    return 0;
}
