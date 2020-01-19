#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > u,v;
vector<pair<int,int> >::iterator it1,it2;
main()
{
	int i,a,j,x,y;
	for(i=0;i<5;i++)
	{
		scanf("%d",&a);
		for(j=0;j<a-1;j++)
		{
			scanf("%d %d",&x,&y);
			if(x>y)swap(x,y);
			u.push_back({x,y});
		}
		for(j=0;j<a-1;j++)
		{
			scanf("%d %d",&x,&y);
			if(x>y)swap(x,y);
			v.push_back({x,y});
		}
		bool k=0;
		sort(u.begin(),u.end());
		sort(v.begin(),v.end());
		for(j=0;j<a-1;j++)
		{
			if(u[j].first!=v[j].first||u[j].second!=v[j].second)
			{
				k=1;
				break;
			}
		}
		if(k==1)printf("N");
		else printf("Y");
		v.clear();
		u.clear();
	}
}
