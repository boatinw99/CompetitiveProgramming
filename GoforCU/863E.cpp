#include<bits/stdc++.h>
using namespace std ;
vector<pair<pair<int,int>,int> > v ;
vector<pair<pair<int,int>,int> >::iterator it ;
main()
{
	int a,i,x,y,x1,y1,x2,y2;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d %d",&x,&y);
		v.push_back({{x,y},i});
	}
	sort(v.begin(),v.end());
	for(it=v.begin();it!=v.end();it++)
	{
		x=it->first.first;
		y=it->first.second;
		x1=(it-1)->first.first;
		y1=(it-1)->first.second;
		x2=(it+1)->first.first;
		y2=(it+1)->first.second;
		if(it!=v.begin())
		{
			if(x==x1)
			{
				printf("%d",(it-1)->second+1);
				return 0 ;
			}
			else if(x>x1&&y<=y1)
			{
				printf("%d",(it)->second+1);
				return 0 ;
			}
		}
		if(it!=v.end()-1)
		{
			if(x>=x2&&y<=y2)
			{
				printf("%d",it->second+1);
				return 0 ;
			}
		}
		if(it!=v.end()-1&&it!=v.begin())
		{
			if(x>=x1&&y<=y2&&y1+1>=x2)
			{
				printf("%d",it->second+1);
				return 0;
			}
		}
	}
	printf("-1");
}
