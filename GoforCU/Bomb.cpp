#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v;
vector<pair<int,int> >::iterator it;
main()
{
	int i,m,x,y ;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		v.push_back({x,y});
	}
	sort(v.begin(),v.end());
	int max1=0,max2=0;
	for(it=v.end()-1;it>=v.begin();it--)
	{
		if(it->second>=max1)
		{
			printf("%d %d\n",it->first,it->second);
			if(it->first==(it-1)->first)
			{
				max2=max(max2,it->second);
			}
			else 
			{
				max1=max(max1,max2);
				max1=max(max1,it->second);
			}
		}
		else max1=max(max1,max2);
	}
}
