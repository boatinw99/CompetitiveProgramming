#include<bits/stdc++.h>
using namespace std ;
const int N=500009;
vector<pair<int,int> >v[100009];
struct node
{
	int min1;
	int k;	
};
int p=1;
int euler[N],depth[N],FAI[N],XOR[N],lvl[N];
node st[N];
void dfs(int i,int dep,int xo)
{
	vector<pair<int,int> > ::iterator it;
	if(FAI[i]==0)FAI[i]=p,XOR[i]=xo;
	lvl[i]=dep;
	euler[p]=i;
	p++;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(FAI[it->first]==0)
		{
			dfs(it->first,dep+1,xo^it->second);
			euler[p]=i;
			p++;
		}
	}
}
void construct(int l,int r,int m)
{
	int mid=(l+r)/2;
	if(l==r)
	{
		st[m].min1=depth[l];
		st[m].k=euler[l];
	}
	else
	{
		construct(l,mid,m*2);
		construct(mid+1,r,m*2+1);
		if(st[m*2].min1<st[m*2+1].min1)
		{
			st[m].min1=st[m*2].min1;
			st[m].k=st[m*2].k;
		}
		else
		{
			st[m].min1=st[m*2+1].min1;
			st[m].k=st[m*2+1].k;
		}
	}
}
node lca(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2; 
	node q,p1,p2 ;
	if(l>=x&&r<=y)
	{
		q.k=st[m].k;
		q.min1=st[m].min1;	
		return q;
	}
	if(r<x||l>y)
	{
		q.k=0;
		q.min1=INT_MAX;
		return q;
	}
	p1=lca(l,mid,x,y,m*2);
	p2=lca(mid+1,r,x,y,m*2+1);
	if(p1.min1<p2.min1)
	{
		q.min1=p1.min1;
		q.k=p1.k;
	}
	else
	{
		q.min1=p2.min1;
		q.k=p2.k;
	}
	return q;
}
main()
{
	int n,m,i,x,y,wi ;
	scanf("%d %d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&wi);
		v[x].push_back({y,wi});
		v[y].push_back({x,wi});
	}
	dfs(1,0,0);
	for(i=1;i<p;i++)
	{
		depth[i]=lvl[euler[i]];
	}
	construct(1,p,1);
	int p1,p2,d,t1,t2;
	node r;
	while(m--)
	{
		scanf("%d %d",&x,&y);
		p1=FAI[x]; p2=FAI[y];
		if(p2<p1)swap(p1,p2);
		d=lca(1,p,p1,p2,1).k;
		t1=XOR[x]^XOR[d];
		t2=XOR[y]^XOR[d];
		printf("%d\n",t1^t2);
	}
}
