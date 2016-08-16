#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define PI 3.14159265
using namespace std;

double modd(double x)
{
    if(x<0)
        return (0-x);
    else
        return x;
}

double side(int x1, int y1, int x2, int y2)
{
    return(sqrt(pow( abs(x2 - x1) , 2) + pow( abs(y2 - y1) , 2)));
}

int equality(double a, double b)
{
    if(modd(a-b) < 0.000001)
        return 1;
    else
        return 0;
}

double angle(double a, double b, double c)
{
    return(acos((pow(a,2) + pow(b,2) - pow(c,2))/(2*a*b))*180/PI);
}

int main()
{
    int t,sid;
    scanf("%d%d", &sid, &t);
    while(t--)
    {
        int x1,y1,x2,y2,x3,y3;
        scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
        double a,b,c;
        a=side(x1,y1,x2,y2);
        b=side(x2,y2,x3,y3);
        c=side(x3,y3,x1,y1);
        if(equality(a,b)==1 || equality(b,c)==1 || equality(c,a)==1)
            printf("Isosceles ");
        else
            printf("Scalene ");
        if(sid==2)
        {
            if(equality(angle(a,b,c),90) || equality(angle(c,a,b),90) || equality(angle(b,c,a),90))
                printf("right ");
            else if(angle(a,b,c)>90 || angle(c,a,b)>90 || angle(b,c,a)>90)
                printf("obtuse ");
            else if(angle(a,b,c)<90 || angle(c,a,b)<90 || angle(b,c,a)<90)
                printf("acute ");
        }
        printf("triangle\n");
    }
    return 0;
}
