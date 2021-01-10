#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v;
main()
{
	int a,i,x,y,l1,r1,l2,r2,count=0 ;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d %d",&x,&y);
		v.push_back({x,y});
	}
	sort(v.begin(),v.end());
	if(a==2)
	{
		printf("YES");
		return 0;
	}
	for(i=0;i<a;i++)
	{
		if(count==0)
		{
			l1=v[i].first;
			r1=v[i].second;
			count=1;
		}
		else if(v[i].first>r1)
		{
			l1=v[i].first;
			r1=v[i].second;
			if(v[i].first>r2&&count==2)
			{
				count=1;
			}
		}
		else if(v[i].first>r2&&count==2)
		{
			l2=v[i].first;
			r2=v[i].second;
		}
		else if(count==1&&v[i].first<=r1)
		{
			l2=v[i].first;
			r2=v[i].second;
			count=2;
		}
		else if(v[i].first>=l1&&v[i].first>=l2&&count==2)
		{
			printf("NO");
			return 0;
		}
		else 
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}
