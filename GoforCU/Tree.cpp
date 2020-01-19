#include<bits/stdc++.h>
using namespace std;
set<int>u[100009],v[100009];
set<int>::iterator it1,it2;
main()
{
	int i,a,j,x,y;
	for(i=0;i<5;i++)
	{
		scanf("%d",&a);
		for(j=0;j<a-1;j++)
		{
			scanf("%d %d",&x,&y);
			if(x>y)swap(x,y);
			u[x].insert(y);
		}
		for(j=0;j<a-1;j++)
		{
			scanf("%d %d",&x,&y);
			if(x>y)swap(x,y);
			v[x].insert(y);
		}
		bool k=0;
		for(j=1;j<=a;j++)
		{
			if(u[j].size()!=v[j].size())
			{
				k=1;
				break;	
			}
			for(it1=u[j].begin(),it2=v[j].begin();it1!=u[j].end()&&it2!=v[j].end();it1++,it2++)
			{
				if(*it1!=*it2)
				{
					k=1;
					break;
				}
			}
			if(k==1)break;
		}
		if(k==1)printf("N");
		else printf("Y");
		for(j=1;j<=a;j++)u[j].clear(),v[j].clear();
	}
	
	
	
}
