#include<bits/stdc++.h>
using namespace std;
vector<int>v[1009];
vector<int>::iterator it;
queue<pair<int,int> > q;
int s[1009];
int t[1009];
bool b[1009];
bool u[1009][1009];
main()
{
	int n,m,x,y,l,r,d;
	scanf("%d %d %d %d",&n,&m,&x,&y);
	while(m--)
	{
		scanf("%d %d",&l,&r);
		v[l].push_back(r);
		v[r].push_back(l);
		u[l][r]++;
		u[r][l]++;
	}
	b[x]++;
	q.push({x,0});
	int c,co=0,i ;
	while(!q.empty())
	{
		d=q.front().first;
		c=q.front().second;
		q.pop();
		for(it=v[d].begin();it!=v[d].end();it++)
		{
			if(!b[*it]++)
			{
				s[*it]=c+1;
				q.push({*it,c+1});
			}
		}
	}
	for(i=1;i<=n;i++)b[i]=0;
	b[y]++;
	q.push({y,0});
	while(!q.empty())
	{
		d=q.front().first;
		c=q.front().second;
		q.pop();
		for(it=v[d].begin();it!=v[d].end();it++)
		{
			if(!b[*it]++)
			{
				t[*it]=c+1;
				q.push({*it,c+1});
			}
		}
	}
	int j;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(!u[i][j]&&min(s[i]+t[j]+1,t[i]+s[j]+1)>=t[x])co++;
		}
	}
	printf("%d",co);
}
