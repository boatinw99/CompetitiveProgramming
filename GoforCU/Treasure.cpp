#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,pair<bool,ll> > > v;
vector<pair<ll,pair<bool,ll> > > ::iterator it ;
ll g[4]={2,3,5,7};
ll d[4];
main()
{
	ll n,m,x,s,t,i,j ; bool k;
	ll max1=0 , range =0 , r  ;
	scanf("%lld %lld",&m,&n);
	while(m--)
	{
		scanf("%lld %lld %lld",&x,&s,&t);
		v.push_back({s,{0,x}});
		v.push_back({t,{1,x}});
	}
	ll co;
	sort(v.begin(),v.end());
	for(it=v.begin();it!=v.end();it++)
	{
		i=it->first ; k=it->second.first ; x=it->second.second;
		if(k==0)
		{
			r= i ;
			for(j=0;x>1;)
			{
				if(x%g[j]==0)d[j]++,x/=g[j];
				else j++;
			}
		}
		else
		{
			co=1;
			for(j=0;j<4;j++)co*=d[j]+1;
			if(co>max1)max1=co,range=i-r+1;
			else if(co==max1)range+=i-r+1;
			for(j=0;x>1;)
			{
				if(x%g[j]==0)d[j]--,x/=g[j];
				else j++;
			}
		}
	}
	printf("%lld %lld",max1,range);
}
