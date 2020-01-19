#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
ll a[100009];
queue<pair<ll,ll> > q;
bool b[100009];
vector<ll> v[100009];
vector<ll> ::iterator it;
vector<pair<ll,ll> > d;
ll bi[600009],size=1;
void bfs(ll x)
{
	q.push({0,x});
	ll i,j;
	b[x]++;
	while(!q.empty())
	{
		i=q.front().first;
		j=q.front().second;
		q.pop();
		d.push_back({-a[j],i});
		for(it=v[j].begin();it!=v[j].end();it++)
		{
			if(!b[*it]++)
			{
				q.push({i+1,*it});
			}	
		}
	}
}
void update(ll in,ll co)
{
	for(in;in<=size;in+=in&-in)bi[in]+=co;
}
ll find(ll in)
{
	ll w=0,j=size/2;
	for(j;j>0;j/=2)
	{
		if(bi[w+j]<in)in-=bi[w+j],w+=j;
	}
	return w+1 ;
}
ll getsum(ll in)
{
	ll sum=0;
	for(in;in>0;in-=in&-in)sum+=bi[in];
	return sum;
}
main()
{
	ll n,m,k,i,j,x,y ;
	ll co=0;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(size=1;size<=n;size*=2);
	for(i=1;i<=n;i++)
	{
		update(i,1);
	}
	while(m--)
	{
		scanf("%lld %lld",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(k);
	vector<pair<ll,ll> >::iterator itq;
	sort(d.begin(),d.end());
	ll p,E;
	for(itq=d.begin();itq!=d.end();itq++)
	{
		x=itq->first;
		y=itq->second;
		p=getsum(y);
		if(p>0&&x<0)
		{
			co+=-x;
			E=find(p);
			update(E,-1);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0&&a[i]>0)
		{
			co+=a[i];
		}
	}
	printf("%lld",co);
	
}

