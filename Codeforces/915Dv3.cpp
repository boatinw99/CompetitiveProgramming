#include<bits/stdc++.h>
using namespace std;
vector<int>v[509];
int town[509];
int count1 ;
int dfs(int i)
{
	if(count1>=2)return 0;
	vector<int>::iterator it;
	town[i]=2;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(town[*it]==2)count1++;
		else if(!town[*it])
		{
			dfs(*it);
		}
	}
	town[i]=1;
}
main()
{
	int n,m,i,j,x,y ;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
	}
	for(i=1;i<=n;i++)
	{
		count1=0;
		for(j=1;j<=n;j++)town[j]=0;
		dfs(i);
		for(j=1;j<=n;j++)if(!town[j])dfs(j);
		if(count1<2)return 0*printf("YES");
	}
	printf("NO");
}
