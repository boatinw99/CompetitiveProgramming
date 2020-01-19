#include<bits/stdc++.h>
using namespace std;
int s[30];
int qs[30];
set<int>e;
set<int>::iterator it;
main()
{
	int n,i ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&s[i]),e.insert(s[i]);
	for(i=1;i<=n;i++)qs[i]+=qs[i-1]+s[i];
	int co=0,j=1;
	while(j<=n)
	{
		for(it=e.begin();it!=e.end();)
		{
			if(co+*it!=qs[j])
			{
				printf("%d %d\n",co,*it);
				e.erase(it++);
				j++;
				co+=*it;
				break;
			}
			else it++;
		}
	}
	
}
