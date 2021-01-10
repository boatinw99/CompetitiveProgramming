#include<bits/stdc++.h>
using namespace std;
vector<int>v[1009];
vector<int>::iterator it;
queue<pair<int,int> > q;
int s[1009];
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
	q.push({y,0});
	b[y]++;
	int c;
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
	int i,co=0,j;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(!u[i][j]&&max(s[i]-s[x],s[x]-s[i])+1+s[j]>=s[x])co++;
		}
	}
	printf("%d",co);
}
