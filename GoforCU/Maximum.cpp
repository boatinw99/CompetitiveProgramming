#include<bits/stdc++.h>
using namespace std ;
const int N=1e5+5;
typedef long long ll;
ll qsa[N],qsb[N];
main()
{	
	int n,i,j ;
	ll h,w,x,y;
	scanf("%d %lld %lld",&n,&h,&w);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		qsa[i]=qsa[i-1]+x;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		qsb[i]=qsb[i-1]+x;
	}
	ll max1=0,co=0;
	for(i=h;i<=n;i++)
	{
		max1=max(max1,qsa[i]-qsa[i-h]);
	}
	co+=max1*w;
	max1=0;
	for(i=w;i<=n;i++)
	{
		max1=max(max1,qsb[i]-qsb[i-w]);
	}
	co+=max1*h;
	printf("%lld",co);
}
