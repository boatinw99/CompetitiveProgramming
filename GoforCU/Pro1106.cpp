#include<bits/stdc++.h>
using namespace std ;
set<int>s;
set<int>::iterator it;
main()
{
	int n,k,i;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)s.insert(i);
	it=s.begin()+k;
	s.erase(it);
}
