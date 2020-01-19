#include<bits/stdc++.h>
using namespace std;
int pat[5000009];
char s[10000009];
main()
{
	int n,i,j ;
	scanf("%d ",&n);
	gets(s);
	for(i=0;i<n;i++)s[i+n]=s[i];
	for(i=1,j=0;i<n;)
	{
		if(s[i]==s[j])
		{
			pat[i]=j+1;
			i++,j++;
		}
		else
		{
			if(j==0)i++;
			else j=pat[j-1];
		}
	}
	for(i=1,j=0;;)
	{
		if(s[i]==s[j])
		{
			i++;j++;
		}
		else
		{
			if(j==0)i++;
			else j=pat[j-1];
		}
		if(j==n)return 0*printf("%d",i-n);
	}
}
