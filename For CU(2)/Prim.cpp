#include<bits/stdc++.h>
using namespace std;
main()
{
	int y,x,i,u,sum=0;
	int c1,c2,c3,k=0;
	scanf("%d %d",&u,&y);
	int s[u+5]={0};
	priority_queue<pair<int,int> > pq;
	vector<vector<pair<int,int> > > v(20) ;
	vector<pair<int,int> >::iterator it ;
    for(i=0;i<y;i++)
    {
        scanf(" %d %d %d",&c1,&c2,&x);
		v[c1].push_back({x,c2});
		v[c2].push_back({x,c1});
    }
    for(it=v[1].begin();it!=v[1].end();it++)
    {
    	pq.push({it->first*-1,it->second});
    	s[1]=9;
	}
	while(!pq.empty()&&k!=99)
	{
		c1=pq.top().first;
		c2=pq.top().second;
		pq.pop();
		if(s[c2]!=9)
		{
		sum+=(c1*-1);
		s[c2]=9;
		for(it=v[c2].begin();it!=v[c2].end();it++)
		{
			pq.push({it->first*-1,it->second});
		}
		k=99;
		for(i=1;i<=u;i++)
		{
			if(s[i]==0){k=0;break;}
		}
		}	
	}
	printf("%d",sum);
     
}
