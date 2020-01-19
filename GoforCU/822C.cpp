#include<bits/stdc++.h>
using namespace std ;
vector<pair<int,int> >L[200001],R[200001];
vector<pair<int,int> >::iterator it ;
int N=2e5+1;
main()
{
	int n,x,l,r,cost,i ;
	scanf("%d %d",&n,&x);
	long long s[N];
	long long max1=INT_MAX ;
	for(i=0;i<N;i++)s[i]=INT_MAX ;
	while(n--)
	{
		scanf("%d %d %d",&l,&r,&cost);
		L[l].push_back({r-l+1,cost});
		R[r].push_back({r-l+1,cost});
	}
	for(i=1;i<N;++i)
	{
		for(it=L[i].begin();it!=L[i].end();++it)
		{	
			if(x-it->first<=0)continue ;
			max1=min(max1,s[x-it->first]+it->second);
		}
		for(it=R[i].begin();it!=R[i].end();++it)
		{
			s[it->first]=min(s[it->first],1ll*it->second);
		}
	}
	if(max1==INT_MAX)printf("-1");
	else printf("%d",max1);
}
