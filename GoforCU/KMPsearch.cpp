#include<bits/stdc++.h>
using namespace std;
int pat[5000009];
string p,s ;
main()
{
	int i,j,n,m ;
	cin >> p ;
	for(i=1,j=0;i<p.size();)
	{
		if(p[i]==p[j])
		{
			pat[i]=j+1;
			i++;j++;		
		}
		else
		{	
			if(j>0)j=pat[j-1];	
			else i++;
		}
	}
	cin >> s;
	for(i=0,j=0;i<s.size();)
	{
		if(s[i]==p[j])
		{
			i++,j++;
		}
		else 
		{
			if(j==0)i++;
			else j=pat[j-1];
		}
		if(j==p.size())return 0*printf("%d",i-p.size()+1);
	}
}
