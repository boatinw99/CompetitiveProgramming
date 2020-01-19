#include<bits/stdc++.h>
using namespace std;
int s[100009];
main()
{
	int n,i,gcd=0 ;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
		gcd=__gcd(gcd,s[i]);
	}
	if(gcd>1)return 0*printf("YES\n0");
	if(gcd==0)return 0*printf("NO");
	int pr=0;
	for(i=0;i<n;i++)
	{
		if(s[i]%2)
		{
			if(s[i+1]%2)
			{
				pr++;		
			}
			else pr+=2;
			i++;
		}
	}
	printf("YES\n%d",pr);
}
