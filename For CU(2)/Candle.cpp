#include<bits/stdc++.h>
using namespace std ;
char q[4000],s[4000];
main()
{
	int i,j,count=0,m,n;
	scanf("%d %d ",&m,&n);
	gets(s);
	for(i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			if(s[i-1]!='1')count++;
		}
	}
	for(i=1;i<m;i++)
	{
		gets(q);
		for(j=0;j<n;j++)
		{
			if(q[j]=='1')
			{
				if(j==0&&s[j]=='0'&&s[j+1]=='0')count++;
				else if(j==n-1&&q[j-1]=='0'&&s[j-1]=='0'&&s[j]=='0')count++;
				else if(j==0&&s[j]=='1'&&s[j+1]=='1');
				else if(j==n-1&&q[j-1]=='1'&&s[j-1]=='1'&&s[j]=='1');
				else if(s[j-1]=='1'&&s[j+1]=='1'&&s[j]=='0'&&q[j-1]=='0')count--;
				else if(q[j-1]=='0'&&s[j-1]=='0'&&s[j]=='0'&&s[j+1]=='0')count++;
				else if(q[j-1]=='1'&&s[j+1]=='1'&&s[j]=='0'&&s[j-1]=='0')count--;
			}
		}printf("%d",count);
		for(j=0;j<n;j++)
		{
			s[j]=q[j];
		}
	}
	
}
