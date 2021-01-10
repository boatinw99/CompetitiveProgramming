#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll;
ll s[40];
ll n,k;
ll find(ll r,ll co)
{
	ll j,y,w;
	if(r<=0)return co ;
	for(j=-1;pow(2,j)<r;j++);
	if(j==0); else j--;
	ll q=pow(2,j);	
	if(q<=0)return co;
	w=((r-1)/q+1)*s[j];
	y=find(r-(r/q*q),(r/q*s[j]));
	ll e=min(w,y);
	printf("%I64d\n",e+co);
	return e+co;
	
}
main()
{
	ll i,j,in,z,y ;
	scanf("%I64d %I64d",&n,&k);
	for(j=0;j<=32;j++)s[j]=1e18+3;
	for(j=0;pow(2,j)<k;j++);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&in);
		if(in<s[i])
		{
			y=in;
			for(z=i;z<=j;z++,y*=2)
				s[z]=y;
			for(z=i;z>=0;z--)s[z]=min(s[z],in);
		}
	}
	ll pr=min(s[j],find(k,0));
	printf("%I64d",pr);
}
