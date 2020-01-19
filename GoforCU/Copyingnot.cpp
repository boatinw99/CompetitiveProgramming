#include<bits/stdc++.h>
using namespace std ;
int n,m,p ;
int l=-1,r=1e9+2,mid;
bool b[40009];
int d[40009];
vector<pair<int,int> > v[40009],s;
void dfs(int in,int k,int parent)
{
	vector<pair<int,int> >::iterator it;
	b[in]++;
	d[in]=parent;
	for(it=v[in].begin();it!=v[in].end();it++)
	{
		if(b[it->first]==0&&it->second<k)
		{
			dfs(it->first,k,parent);
		}
	}
}
main()
{
	int x,y,val,n,m,p,i,j ;
	scanf("%d %d %d",&n,&m,&p);
	while(m--)
	{
		scanf("%d %d %d",&x,&y,&val);
		v[x].push_back({y,val});
		v[y].push_back({x,val});
	}
	while(p--)	
	{
		scanf("%d %d",&x,&y);
		s.push_back({x,y});
	}
	vector<pair<int,int> >::iterator it;
	while(l+1<r)
	{
		bool q=0;
		mid=(l+r)/2;
		for(i=0;i<=n;i++)b[i]=0;
		for(i=1;i<=n;i++)
		{
			if(b[i]==0)
			dfs(i,mid,i);
		}
		for(it=s.begin();it!=s.end();it++)
		{
			if(d[it->first]==d[it->second])
			{
				q++;
				break;
			}
		}
		if(q==0)l=mid;
		else r=mid;
	}
	if(l>1e9)printf("-1");
	else
	printf("%d",l);
}
