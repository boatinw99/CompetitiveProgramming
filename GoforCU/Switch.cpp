#include<bits/stdc++.h>
using namespace std ;
const int N=1e7+9;
char s[N];
int pattern[N];
main()
{
	int n,i,j=0 ;
	scanf("%d ",&n);
	gets(s);
	for(i=0;i<n;i++)s[i+n]=s[i];
	for(i=1,j=0;i<n*2;)
	{
		if(s[i]==s[j])
		{
			pattern[i]=j+1; i++; j++;
		}
		else
		{
			if(j==0)i++;
			else j=pattern[j-1];
		}
	}
	for(i=1,j=0;i<n*2;)
	{
		if(s[i]==s[j])
		{
			i++; j++;
		}
		else
		{
			if(j==0)i++;
			else j=pattern[j-1];
		}
		if(j==n)
		{
			printf("%d\n",i-n);
			return 0;
		}
	}
}
