#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v[1009];
priority_queue<pair<int,int> >pq;
int n,m,st,ed,ca,min1=INT_MAX;
int fu[1009];
int ch[1009];
vector<pair<int,int> >::iterator it1;
int dfs(vector<pair<int,int> >u)
{
	int j=(u.end()-1)->first;
	vector<pair<int,int> >::iterator it;
	ch[j]++;
	if(j==ed)
	{
		int t=0,x,y,o;
		it1=u.begin();
		pq.push({-fu[it1->first],ca});
		it1++;
		for(;it1!=u.end();it1++)
		{
			o=it1->second;
			while(o>0)
			{
				x=pq.top().first*-1;
				y=pq.top().second;
				pq.pop();
				if(o>=y)o-=y,t+=x*y;
				else 
				{
					t+=x*o;
					pq.push({-x,y-o});	
					o=0;
				}
			}	
			pq.push({-fu[it1->first],ca});
			
		}
		ch[j]--;
		min1=min(min1,t);
		while(!pq.empty())pq.pop();
		return 0;
	}
	for(it=v[j].begin();it!=v[j].end();it++)
	{
		if(it->second<=ca&&!ch[it->first])
		{
			u.push_back({it->first,it->second});
			dfs(u);
			u.pop_back();
		}
	}
	ch[j]=0;
}
main()
{
	int i,x,y,val;
	vector<pair<int,int> >p;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&fu[i]);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&val);
		v[x].push_back({y,val});
		v[y].push_back({x,val});		
	}
	scanf("%d %d %d",&ca,&st,&ed);
	p.push_back({st,0});
	dfs(p);
	if(st==ed)printf("0");
	else if(min1==INT_MAX)
		printf("-99");
	else printf("%d",min1);
	
}
