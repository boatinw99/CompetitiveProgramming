#include<bits/stdc++.h>
using namespace std ;
int pattern[500];
string s,p;
main()
{
	int i,j=0 ;
	printf("Pattern : "); cin >> p;
	printf("Parent : "); cin >> s;
	for(i=1;i<p.size();)
	{
		if(p[i]==p[j])
		{
			j++;
			pattern[i]=j;
			i++;
		}
		else 
		{
			if(j==0)i++;
			else j=pattern[j-1];
		}
	}
	for(i=0,j=0;i<s.size();)
	{
		if(s[i]==p[j])
		{
			i++; j++;
		}
		else
		{
			if(j==0)i++;
			else j=pattern[j-1];
		}
		if(j==p.size())
		{
			printf("%d",i-p.size()+1);
			return 0;
		}
	}
	printf("-1");
}
