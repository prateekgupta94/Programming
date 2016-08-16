/*GCD or HCF*/
int gcd(int a,int b)
{
if(b==0)
return a;
else
return gcd(b,a%b);
}

/*quicksort(increasing order)*/
void quicksort(int x[100010],int first,int last)
{
    int pivot,j,temp,i;

    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(x[i]<=x[pivot] && i<last)
                 i++;
            while(x[j] > x[pivot])
                 j--;
            if(i<j)
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        quicksort(x,first,j-1);
        quicksort(x,j+1,last);
    }
}

/*quicksort(decreasing order)*/
void quicksort(int x[100010],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(x[i]>=x[pivot] && i<last)
                 i++;
            while(x[j] < x[pivot])
                 j--;
            if(i<j)
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        quicksort(x,first,j-1);
        quicksort(x,j+1,last);
    }
}

/*Convert array into variable OR binary string into decimal number*/
a=(a<<1)|(sa[i]-'0');

/*Prime Number Generator (Sieve of Eratothenes)*/
bool prime[1000010];
void sieve(int n)
{
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}
if prime[x]==true
    it is a prime no.
else
    not;

/*n^2 complexity to nlogn*/
while(i<n && j<k+m)
    {
        if(diff[i]==c[j])
        {
            diff[i]=0;
            c[j]=-1;
            i++;
            j++;
        }
        else if(diff[i]>c[j])
            i++;
        else
            j++;
    }

/*Calculation of mod 1000000007*/
long long mod=1000000007;
long long modl(long long a)
{
    return (a%mod);
}

/*time limits*/
For a 1sec time limit,
N=10^6-10^7 : O(n) solution is required.
N=10^5 : O(nlogn) solution.
N=10^4 : O(n^1.5 or n(logn)^2) solution.
N=10^3 : O(n^2) solution.

