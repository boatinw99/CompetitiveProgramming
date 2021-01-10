#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll n;
ll dfs(ll i)
{
	if(i%2)return 0*printf("%I64d\n",(i+1)/2);
	dfs(n-i/2+i);
}
main()
{
	ll q,x ;
	scanf("%I64d %I64d",&n,&q);
	while(q--)
		scanf("%I64d",&x),dfs(x);
}
