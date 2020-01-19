#include<bits/stdc++.h>
using namespace std ;
int s[19];
string p="";
main()
{
	int i,j,n,k=INT_MAX,q,r;
	scanf("%d",&n);
	for(i=1;i<=9;i++)scanf("%d",&s[i]);
	for(i=1;i<=9;i++)
	{
		if(s[i]<k)
		{
			k=s[i];
			q=i;
		}
	}
	k=n/k;
	n-=k*s[q];
	for(i=1;i<=k;i++)
	{
		p+='0'+q;
	}
	for(i=0;i<k&&n>0;i++)
	{
		for(j=9;j>q;j--)
		{
			if(n>=s[j]-s[q])
			{
				p[i]='0'+j;
				n-=s[j]-s[q];
				break;
			}
		}
	}
	cout << p;
}
