#include<bits/stdc++.h>
using namespace std;
vector<int>v[200009],p;
vector<int>::iterator it;
set<int> s;
set<int>::iterator its ;
int n,m,q=1 ;
queue<int>qp;
bool b[200009];
int bfs(int in)
{
	int x;
	qp.push(in);
	while(!qp.empty())
	{
		x=qp.front();
		qp.pop();
		it=v[x].begin();
		its=s.begin();
		for(it;it!=v[x].end()&&its!=s.end();it++)
		{
			while(*its<*it&&its!=s.end())
			{
				q++;
				b[*its]++;
				qp.push(*its);
				s.erase(its++);
			}
			if(its!=s.end()&&*its<=*it)
				its++;
		}	
		for(its;its!=s.end();)
		{
			q++;
			b[*its]++;
			qp.push(*its);
			s.erase(its++);	
		}
	}
}
main()
{
	int i,j,x,y,co=0 ; 
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)s.insert(i);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
	for(i=1;i<=n;i++)
	{
		if(!b[i]++)
		{
			co++;
			s.erase(i);
			bfs(i);
			p.push_back(q);
			q=1;
		}
	}
	printf("%d\n",p.size());
	sort(p.begin(),p.end());
	for(it=p.begin();it!=p.end();it++)
		printf("%d ",*it);
}
