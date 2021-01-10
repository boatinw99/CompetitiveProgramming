#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
vector<pair<ll,pair<ll,ll> > > v;
vector<pair<ll,pair<ll,ll> > >::iterator it,it1;
stack<pair<ll,ll> > st;
main()
{
	ll n,i,x,y,val,max1=0,co=0 ;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d %I64d %I64d",&x,&y,&val);
		v.push_back({y,{x,val}});
	}
	sort(v.begin(),v.end());
	for(it=v.end()-1;it>=v.begin();it--)
	{
		while(!st.empty()&&it->first<=st.top().first)
		{
			co-=st.top().second;
			st.pop();
		}
		st.push({it->second.first,it->second.second});		
		co+=it->second.second;
		max1=max(max1,co);
	}
	printf("%I64d",max1);
}
