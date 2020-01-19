#include<bits/stdc++.h>
using namespace std ;
int a[20009];
int b[20009];
int rankq[20009];
int parent[20009];
stack<pair<char,pair<int,int> > > st;
vector<int> path[20009];
stack<bool> st2;
void dfs(int u,int par)
{
	vector<int> :: iterator it;
	parent[u]=par;
	for(it=path[u].begin();it!=path[u].end();it++)
	{
		if(b[u]>=1&&a[u]==*it);
		else if(b[*it]>=1&&a[*it]==u);
		else if(parent[*it]==0)
		{
			dfs(*it,par);
		}
	}
}
int find(int x)
{
	if(parent[parent[x]]!=parent[x])
	{
		parent[x]=find(parent[x]);
	}
	return parent[x];
}
void unionset(int x,int y)
{
	int x1=find(x),y1=find(y);
	//printf("a %d %d || %d %d\n",x1,y1,x,y); 
	if(x1!=y1)
	{
		if(rankq[x1]>=rankq[y1])
		{
			rankq[x1]+=rankq[y1];
			parent[y1]=parent[x1];
		}
		else
		{
			rankq[y1]+=rankq[x1];
			parent[x1]=parent[y1];
		}
	}
}
main()
{
	int T,n,m,i,j,z,x,y ;
	char c;
	scanf("%d",&T);
	for(z=1;z<=T;z++)
	{
		scanf("%d %d",&n,&m);
		parent[0]=0;
		rankq[0]=1;    
		b[0]=0;     
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			parent[i]=0;
			a[i]=x;
			b[i]=0;
			rankq[i]=1;
			if(x!=0)
			{
				path[x].push_back(i);
				path[i].push_back(x);
			}
			
		}
		while(m--)
		{
			scanf(" %c",&c);
			if(c=='Q')
			{
				scanf("%d %d",&x,&y);
				st.push({c,{x,y}});
			}
			else
			{
				scanf("%d",&x);
				b[x]++;
				st.push({c,{x,1}});
			}
		}
		printf("Case #%d:\n",z);
		for(i=1;i<=n;i++)
		{
			if(parent[i]==0)
			{
				dfs(i,i);
			}
		}
		while(!st.empty())
		{
			c=st.top().first;
			x=st.top().second.first;
			y=st.top().second.second;
			if(c=='Q')
			{
				st2.push((find(x)==find(y))?(1):(0));
			}
			else
			{
				b[x]--;
				if(b[x]==0&&a[x]!=0)
				unionset(x,a[x]);
			}
			st.pop();
		}
		while(!st2.empty())
		{
			printf("%s\n",(st2.top()==1)?("YES"):("NO"));
			st2.pop();;
		}
		for(i=0;i<=n;i++)path[i].clear();
	}
}
