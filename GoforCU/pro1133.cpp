#include<bits/stdc++.h>
using namespace std ;
vector<int>v[1000009];
vector<int>::iterator it,it1;
int all[509][509];
main()
{
	int n,m,i,j,k,p,q,x,y; 
	scanf("%d %d",&n,&m);
	for(i=0;i<507;i++)
	{
		for(j=0;j<507;j++)
		{
			all[i][j]=10000;
		}
		all[i][i]=0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		while(x--)
		{
			scanf("%d",&y);
			if(v[y].empty()||*(v[y].end()-1)!=i)
			v[y].push_back(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			for(it1=it+1;it1!=v[i].end();it1++)
			{
				all[*it][*it1]=1;
				all[*it1][*it]=1;
			}
		}
	}
	for(k=1;k<=m;k++)
	{
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=m;j++)
			{
				all[i][j]=min(all[i][j],all[i][k]+all[k][j]);
			}
		}
	}
	int t,min1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		min1=10000;
		for(it=v[x].begin();it!=v[x].end();it++)
		{
			for(it1=v[y].begin();it1!=v[y].end();it1++)
			{
				min1=min(min1,all[*it][*it1]);
			}
		}
		if(min1==10000)printf("impossible\n");
		else printf("%d\n",min1);
	}
}
