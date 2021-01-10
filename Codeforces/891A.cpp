#include<bits/stdc++.h>
using namespace std;
int s[2009];
main()
{
	int n,i,c=0,count=INT_MAX;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
		if(s[i]==1)c++;
	}
	if(c)return 0*printf("%d",n-c);
	int ch=0,j;
	for(i=0;i<n;i++)
	{
		ch=s[i];
		for(j=i+1;j<n;j++)
		{
			ch=__gcd(ch,s[j]);
			if(ch==1)
			{
				if(j-i<count)count=j-i;
				break;
			}
		}
		
	}
	if(count==INT_MAX)return 0*printf("-1");
	printf("%d",n+count-1);
}
