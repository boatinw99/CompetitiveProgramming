#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[40][40];
ll n,l;
main()
{
	ll i,in,j;
	scanf("%I64d %I64d",&n,&l);
	ll d,y=1 ;
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&in);
		y=in;
		for(j=i;pow(2,j-1)<=l;j++,y*=2)
			s[i][j]=y;
		for(j=i;j>=0;j--)s[i][j]=in;
	}
	ll pr=0,min1;
	ll p,q;
	for(j=0;pow(2,j-1)<=l;j++);
	for(j;j>=0;j--)
	{
		q=pow(2,j);
		if(q<=l)
		{
			min1=1e18+2;
			for(i=0;i<n;i++)
			{
				if(s[i][j]<=min1)
				{
					min1=s[i][j];
					p=i;
				}
			}
			if(p>j)printf("a"),l=0,pr+=min1;
			else
			{
				pr+=min1*(l/q);
				l-=l/q*q;
			}
			printf("%I64d %I64d %I64d\n",l,pr,q);
		}
	}
	printf("%I64d",pr);
}	
