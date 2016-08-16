#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define mod 1000000007
using namespace std;

void quicksort(int x[300005],int pos[300005],int first,int last)
{
    int pivot,j,temp,i,temp1;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(x[i]<=x[pivot]&&i<last)
                i++;
            while(x[j]>x[pivot])
                j--;
            if(i<j)
            {
                temp=x[i];
                temp1=pos[i];
                x[i]=x[j];
                pos[i]=pos[j];
                x[j]=temp;
                pos[j]=temp1;
            }
        }
        temp=x[pivot];
        temp1=pos[pivot];
        x[pivot]=x[j];
        pos[pivot]=pos[j];
        x[j]=temp;
        pos[j]=temp1;
        quicksort(x,pos,first,j-1);
        quicksort(x,pos,j+1,last);
    }
}

int check(int a, int b, int c, int x, int tpl[300005])
{
    int i;
    for(i=0; i<x; i++)
    {
        if(tpl[i]==a)
            return 1;
        if(tpl[i]==b)
            return 1;
        if(tpl[i]==c)
            return 1;
    }
    return 0;
}

int lo(int a[300005], int n)
{
    int i,l1=2001,l2=2002,l3=2003;
    for(i=0; i<3*n; i++)
    {
        if(min(l3,a[i]) < l3)
        {
            if(min(l2,a[i]) < l2)
            {
                if(min(l1,a[i]) < l1)
                {
                    l3=l2;
                    l2=l1;
                    l1=min(l3,a[i]);
                }
                else
                {
                    l3=l2;
                    l2=min(l2,a[i]);
                }
            }
            else
                l3=min(l3,a[i]);
        }
    }
    return (l1+l2+l3);
}

int hi(int a[300005], int n)
{
    int i,h1=-1,h2=-2,h3=-3;
    for(i=0; i<3*n; i++)
    {
        if(max(h3,a[i]) > h3)
        {
            if(max(h2,a[i]) > h2)
            {
                if(max(h1,a[i]) > h1)
                {
                    h3=h2;
                    h2=h1;
                    h1=max(h1,a[i]);
                }
                else
                {
                    h3=h2;
                    h2=max(h2,a[i]);
                }
            }
            else
                h3=max(h3,a[i]);
        }
    }
    return (h1+h2+h3);
}

int fnd(int a[300005], int pos[300005], int tpl[300005], int n, long long s)
{
    int i,x=0,ans=0,l,r,tmp[300005];
    for(i=0; i<=3*n-1; i++)
    {
        tmp[i]=a[i];
        pos[i]=i+1;
    }
    quicksort(tmp,pos,0,3*n-1);
    for(i=0; i<=3*n-3; i++)
    {
        if(tmp[i]+tmp[i+1]+tmp[i+2]>s)
            break;
        l=i + 1;
        r = 3*n - 1;
        while (l < r)
        {
            if(tmp[i]+tmp[l]+tmp[r]==s && check(pos[i],pos[l],pos[r],x,tpl)==0)
            {
                ans++;
                tpl[x++]=pos[i];
                tpl[x++]=pos[l];
                tpl[x++]=pos[r];
            }
            else if (tmp[i] + tmp[l] + tmp[r] < s)
                l++;
            else
                r--;
        }
    }
    return ans;
}

int main()
{
    int a[300005],pos[300005],tpl[300005],n,i,ans=0;
    scanf("%d", &n);
    for(i=0; i<3*n; i++)
    {
        scanf("%d", &a[i]);
        pos[i]=i+1;
    }
    long long s=(lo(a,n)+hi(a,n))/2;
    ans=fnd(a,pos,tpl,n,s);
    printf("%d\n", ans);
    for(i=0; i<ans*3; i++)
        printf("%d ", tpl[i]);
    printf("\n");
    return 0;
}

