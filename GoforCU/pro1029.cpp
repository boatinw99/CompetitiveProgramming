#include<bits/stdc++.h>
using namespace std ;
map<int,int>mp;
map<int,int>::iterator itp;
vector<int>v;
vector<int>::iterator it;
main()
{
	int n,m,q,x,y ;
	scanf("%d %d %d",&n,&m,&q);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		mp[x]++; mp[x+y]++;
	}
	itp=mp.begin();
	v.push_back(1);
	if(itp->first==1)itp++;
	for(itp;itp!=mp.end();itp++)
	{
		if(itp->second%2)v.push_back(itp->first);
	}
	if(*(v.end()-1)!=n+1)v.push_back(n+1);
	while(q--)
	{
		scanf("%d",&x);
		it=upper_bound(v.begin(),v.end(),x);
		printf("%d\n",*it-*(it-1));
	}
}
