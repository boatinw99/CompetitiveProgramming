#include<bits/stdc++.h>
using namespace std ;
int s[300009];
vector<pair<int,pair<int,int> > > v;
vector<pair<int,pair<int,int> > >::iterator it;
main()
{
	int n,i,j,co=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]); co+=s[i];
		v.push_back({s[i],{s[i],i}});
	}
	sort(v.begin(),v.end(),greater<pair<int,pair<int,int> > >());
	for(it=v.begin()+1;it!=v.end();it++)
	{
		it->first+=(it-1)->first;
	}
	for(i=1;i<=n;i++)
	{
		it=upper_bound(v.begin(),v.end(),make_pair(co/2-s[i],make_pair(INT_MAX,INT_MAX)));
		if((s[i]==it->second.first&&i<=it->second.second)||s[i]>it->second.first)
		{
			it=upper_bound(v.begin(),v.end(),make_pair(co/2,make_pair(INT_MAX,INT_MAX)));
			printf("%d\n",it-v.begin());
		}
		else
		{
			printf("%d\n",it-v.begin()+1);
		}
	}
}
