#include<bits/stdc++.h>
using namespace std ;
vector<pair<int,int> >v;
vector<pair<int,int> >::iterator it;
set<int>s;
set<int>::iterator its,itp;
main()
{
	int i,j,n,m,x,co=0 ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x);
			v.push_back({x,i+j-1});
		}
	}
	sort(v.begin(),v.end(),greater<pair<int,int> >());
	for(it=v.begin();it!=v.end();it++)
	{
		if(it->second>1)
		{
			if(s.empty())
			{
				co+=it->first;
				s.insert(-it->second);
			}
			else 
			{
				its=lower_bound(s.begin(),s.end(),-it->second);
				if(*its!=it->second*-1)
				{
					co+=it->first;
					s.insert(-it->second);
				}
				else 
				{
					its++;
					if(its==-it->second+1);
					else
					{
						
					}
				}
			}
		}
	}
	printf("%d",co);
}
