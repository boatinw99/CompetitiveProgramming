#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll v[100009];
ll co=0 ;
set<ll>s;
set<ll>::iterator it,it1;
main()
{
	ll n,i,x,y ;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&x,&y);
		v[y]=x;
	}
	for(i=1;i<=n;i++)
	{
		s.insert(v[i]); 
	}
	
}
