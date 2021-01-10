#include<bits/stdc++.h>
using namespace std;
vector<int> v[10009];
vector<int>::iterator it;
bool b[10009];
queue<pair<int,int> > q;
main()
{
	int n,k,m,x,y,max1=0; 
	scanf("%d %d %d",&k,&n,&m);
	while(m--)scanf("%d %d",&x,&y),v[x].push_back(y); q.push({0,1});
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		q.pop();
		max1=max(max1,y);		
		if(x<k)
		{
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				if(!b[*it]++)
				{
					q.push({x+1,*it});
				}
			}
		}
	}
	printf("%d",max1);
}
