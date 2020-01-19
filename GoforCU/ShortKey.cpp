#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int dy[200009];
vector<int>v[200009];
vector<int>::iterator it;
main()
{
	int i,j,x,y ;
	scanf("%d %d %d",&n,&k,&m);
	while(k--)
	{
		scanf("%d %d",&x,&y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i++)
	{
		dy[i]=dy[i-1]+1;
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			dy[i]=min(dy[i],dy[*it]+1);
		}
	}
	printf("%d\n",dy[n]);
	if(dy[n]<=m)return 0*printf("1");
	printf("0 ");
	for(i=n;i>=0;i--)if(dy[i]<=m)return 0*printf("%d",i);
	
}
