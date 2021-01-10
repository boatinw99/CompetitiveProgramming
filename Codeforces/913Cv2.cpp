#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[40][40];
ll n,l;
ll find(ll r,ll b)
{
	return 1000;
}
main()
{
	ll i,in,j;
	ll y;
	scanf("%I64d %I64d",&n,&l);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&in);
		y=in;
		for(j=i;pow(2,j)<=l;j++,y*=2)
			s[i][j]=y;
		for(j=i;j>=0;j--)s[i][j]=in;
	}
	ll pr=0,min1=1e18+2,p;
	for(j=0;pow(2,j)<=l;j++);j--;
	for(i=0;i<n;i++)
	{
		if(s[i][j]<=min1)printf("a %d\n",s[i][j]),min1=s[i][j],p=i;
	}
	ll d=pow(2,j);
	ll t=find(n%d,min1*(l/d*d));
	printf("%d ",(l-1)/d+1);
	pr=min(min1*((l-1)/d+1),t);
	printf("%I64d",pr);
	
}
