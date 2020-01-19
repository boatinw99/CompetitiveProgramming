#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[500009];
ll bi[500009],n;
ll bi2[500009];
vector<pair<ll,ll> > se;
vector<pair<ll,ll> >::iterator it;
ll change(ll in,ll co)
{
	for(;in<=n;in+=in&-in)bi[in]+=co;
}
ll getsum(ll in)
{
	ll count=0;
	for(in;in>0;in-=in&-in)count+=bi[in];
	return count ;
} 
main()
{
	ll i,x,y,co=0,n1 ;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&x,&y);
		s[y]=x;	
		se.push_back({x,y});
	}
	n1=n;
	sort(se.begin(),se.end());
	for(i=1;i<=n;i++)change(i,1);
	ll sum;
	for(i=1;i<=n;i++)bi2[i]=bi[i];
	for(it=se.begin();it!=se.end();it++)
	{
		sum=getsum(it->second);
		co+=it->first*(sum-1);
		change(it->second,-1);
	}
	for(i=1;i<=n;i++)bi[i]=bi2[i];
	for(it=se.end()-1;it>=se.begin();it--)
	{
		sum=getsum(it->second);
		co+=it->first*(n1-sum);
		change(it->second,-1);
		n1--;
	}
	printf("%lld",co);
}
