#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll l=0,r=1e6,T,n;
struct node
{
	ll ter ;
	ll str ;
	ll time ;	
};
vector<node> v[100009];
vector<node>::iterator it;
priority_queue<pair<ll,ll> > pq;
bool q[100009];
bool Dijkstra(ll mid)
{
	ll x,y;
	pq.push({0,1});
	while(!pq.empty())
	{
		x=pq.top().first*-1;
		y=pq.top().second;
		pq.pop();
		if(y==n)
		{
			if(x<=T)return 1;
			return 0;
		}
		if(!q[y]++)
		{
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				if(!q[it->ter]&&it->str<=mid)
				{
					pq.push({-x-(it->time),it->ter});
				}
			}
		}
	}
	return 0 ;
}
main()
{
	ll m,k,ti,i,j,a,b,d,pr ; 
	struct node p;
	scanf("%lld %lld %lld %lld",&n,&m,&k,&T);
	while(m--)
	{
		scanf("%lld %lld %lld %lld",&a,&b,&d,&ti);
		p.ter = b ; p.str =d ; p.time=ti;	
		v[a].push_back(p); p.ter=a;
		v[b].push_back(p);
	}
	while(l+1<r)
	{
		bool Y=0;
		for(i=0;i<=n+5;i++)q[i]=0;
		ll mid=(l+r)/2;
		while(!pq.empty())pq.pop();
		Y=Dijkstra(mid);
		if(Y==1)
		{
			r=mid;
		}
		else if(Y==0)
		{
			l=mid;
		}
	}
	ll max1=INT_MAX;
	while(k--)
	{
		ll pi,si;
		scanf("%lld %lld",&pi,&si);
		if(r<=si)
		{
			max1=min(max1,pi);
		}
	}
	if(max1==INT_MAX)printf("-1");
	else	
	printf("%lld",max1);
}
