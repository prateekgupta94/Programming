/*GCD or HCF*/
int gcd(int a,int b)
{
if(b==0)
return a;
else
return gcd(b,a%b);
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
