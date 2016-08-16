#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int i,j,k,x,ctr=0,start=-1,sum=15;
    char s[6][55]={"CCGCCCGACGCAGGCTTCCGGCGAGACATGGCAGGGCAAGGATGGCAGCC",
    "GCAGCCGCTGCAGCGCCAGGGTCCACCTGGTCGGCTGCACCTGTGGAGGA",
    "CTCAAAACCGCTTGCCTCGCAGGGGCTGAGCTGGAGGCAGCGAGGCCGCC",
    "TCCCAGACAGAACCTACTATGTGCGGCGGCAGCTGGGGCGGGAAGGCGGG",
    "GAGGAGGAGGTGGATTTCAGGCTTCCCGTAGACTGGAAGAATCGGCTCAA",
    "GCGGGAGCTGGGGGCGCTGGGGGCGCTGCGGCCGCTGCGGCCGCTGCAGC"};
    char ch[6]={'N','Q','I','S','U','E'};
    /*for(i=0; i<6; i++)
        scanf("%s", s[i]);*/
    char st[6][10], en[6][10];
    for(i=0; i<6; i++)
    {
        x=0;
        for(j=0; j<5; j++)
            st[i][j]=s[i][j];
        st[i][j]='\0';
        for(j=45; j<50; j++)
            en[i][x++]=s[i][j];
        en[i][x]='\0';
    }
    for(i=0; i<5; i++)
    {
        ctr=0;
        for(j=0; j<6; j++)
        {
            if(strcmp(st[i],en[j])==0 && i!=j)
                break;
            else if(strcmp(st[i],en[j])!=0 && i!=j)
                ctr++;
            if(ctr==5)
            {
                start=i;
                printf("\n%c-> %s\n", ch[i], s[i]);
                sum=sum-i;
                break;
            }
        }
        if(start==i)
            break;
    }
    x=start;
    ctr=0;
    for(k=0; k<6; k++)
    {
        if(strcmp(en[start],st[k])==0 && start!=k)
        {
            start=k;
            printf("%c-> %s\n", ch[k], s[k]);
            sum=sum-k;
            ctr++;
            k=0;
        }
        if(ctr==4)
        {
            printf("%c-> %s\n", ch[sum], s[sum]);
            ctr=0;
        }
    }
    return 0;
}
