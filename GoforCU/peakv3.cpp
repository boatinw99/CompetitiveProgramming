#include<bits/stdc++.h>
using namespace std;
int s[5000009];
vector<pair<int,int> >v;
main()
{
	int n,k,i ;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		v.push_back({s[i],i});
	}
	sort(v.begin(),v.end());
}
