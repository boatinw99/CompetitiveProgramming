#include<bits/stdc++.h>
using namespace std ;
const int N=599;
vector<pair<int,int> >v[N];
vector<pair<int,int> >::iterator it ;
int bmf[N];
int APS[N][N];
main()
{
	int n,m,x,y,i,j,val,st;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d %d",&x,&y,&val);
		v[x].push_back({y,val});
	}
	st=n+1;
	for(i=1;i<=n;i++)bmf[i]=0;
	for(i=0;i<n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(it=v[j].begin();it!=v[j].end();it++)
			{
				bmf[it->first]=min(bmf[it->first],bmf[j]+it->second);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			it->second=bmf[i]+it->second-bmf[it->first];
		}
	}
	
}
