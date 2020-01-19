#include<bits/stdc++.h>
using namespace std ;
map<int,int> m;
map<int,int>::iterator it;
main()
{
	int n,k,x,i ;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		m[x]=i;
	}
	if(m.size()>=k)
	{
		printf("YES\n");
		for(it=m.begin();k>0;k--,it++)
		{
			printf("%d ",it->second);
		}
	}
	else
	{
		printf("NO");
	}
}
