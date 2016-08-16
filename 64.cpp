#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t,n;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld", &n);
		int alpha=97;
		while(n--)
		{
			if(alpha>122)
				alpha = 97;
			printf("%c", alpha);
			alpha++;
		}
		printf("\n");
	}
	return 0;
}
