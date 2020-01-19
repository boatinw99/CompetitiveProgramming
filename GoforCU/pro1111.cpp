#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v[100009];
vector<pair<int,int> >::iterator it;
queue<int>q;
int s[100009];
main()
{
	int m,i,j,wi,n ;
	scanf("%d",&m);
	n=m;
	m--;
	q.push(1);
	for(i=1;i<=n;i++)s[i]=0;
	while(m--)
	{
		scanf("%d %d %d",&i,&j,&wi);
		v[i].push_back({j,wi});
		v[j].push_back({i,wi});
	}
	while(!q.empty())
	{
		i=q.front();
		q.pop();
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			if(!s[it->first])
			{
				s[it->first]=s[i]+it->second;
				q.push(it->first);
			}
		}
		s[1]=1;
	}
	int max1=0;
	for(i=1;i<=n;i++)max1=max(max1,s[i]);
	printf("%d",max1);
}
