#include<bits/stdc++.h>
using namespace std ;
int m,n,cy=0;
int a[509][509];
int town[509];
bool cycle[509];
bool b[509][509];
vector<int> v[509];
int loop(int i,int p)
{
	a[town[i]][i]++;
	if(b[i][town[i]])
	{
		a[town[i]][i]++;
		a[i][town[i]]++;
		cy++;
	}
//	printf("b %d %d\n",town[i],i);
	if(town[i]!=p)
	{		
		loop(town[i],p);	
	}
}
int dfs(int i)
{
	int o,e;
	vector<int>::iterator it,it1;
	cycle[i]++;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(!town[*it])
		{
			town[*it]=i;
			printf("%d %d\n",i,*it);
			dfs(*it);
		}
		else if(cycle[*it])
		{
			a[i][*it]++;
			cy++;
			if(b[*it][i])
			{
				a[*it][i]++;
				a[i][*it]++;
				cy++;
			}
			printf("a %d %d\n",i,*it);
			loop(i,*it);
		}
		else
		{
			for(e=1;e<=n;e++)
			{
				if(a[*it][e]>0)
				{
					printf("%d\n",i);
				}
			}
		}
	}
	cycle[i]=0;
}
main()
{
	int i,j,x,y;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		b[x][y]++;
		v[x].push_back(y);
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		if(!town[i])
		{
			dfs(i);	
			town[i]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==cy)return 0*printf("YES");
		}
	}
	printf("NO");
}
