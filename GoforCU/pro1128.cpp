#include<bits/stdc++.h>
using namespace std ;
int s[1000009];
main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	for(i=1;i<=n;i++)s[i]=(s[i]+s[i-1])%2553;
	for(i=1;i<=n;i++)s[i]=(s[i]+s[i-1])%2553;
	for(i=1;i<=n;i++)s[i]=(s[i]+s[i-1])%2553;
	printf("%d",s[n]);
	
}
