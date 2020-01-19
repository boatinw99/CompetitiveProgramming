#include<bits/stdc++.h>
using namespace std;
vector<int>v[2009];
vector<int>col[2009];
vector<int>::iterator it1,itcol;
vector<int>::iterator it;
priority_queue<int>pq;
int s[2009];
bool q[2009];
int n,m ;
bool b[2009][2009];
main()
{
	int i,x,y,j,k,l,r,p=INT_MAX;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		b[x][y]++;
		b[y][x]++;
		v[x].push_back(y);
		v[y].push_back(x);
		p=min(min(p,x),min(p,y));
	}
	pq.push(-p);
	q[p]++;
	bool d=0;
	while(!pq.empty())
	{
		x=pq.top()*-1;
		pq.pop();
		for(i=0;;i++)
		{		
				d=0;
			for(itcol=col[i].begin();itcol!=col[i].end();itcol++)
				if(b[x][*itcol])
				{
					d=1; break;
				}
			if(d==0)
			{
				s[x]=i+1;
				col[i].push_back(x);
				break;	
			}
		}
		for(it1=v[x].begin();it1!=v[x].end();it1++)
		{
			if(!q[*it1]++)
			{
				pq.push(*it1*-1);
			}
		}
	}
	i=1;
	while(n)
	{
		if(s[i])printf("%d\n",s[i]),n--;
		i++;
	}
		
}
