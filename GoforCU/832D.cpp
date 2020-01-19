#include<bits/stdc++.h>
using namespace std ;
int q,n,k=1 ;
vector<int> v[100009];
int s[100009];
int a[100009][2];
void dfs(int i,int path ,int c)
{
	s[i]=i;
	a[i][0]=1;
	a[i][1]=k;	
}
main()
{
	int i,in;
	scanf("%d %d",&n,&q);
	for(i=1;i<n;i++)
	{
		scanf("%d",&in);
		v[i+1].push_back(in);
		v[in].push_back(i+1);		
	}
	for(i=1;i<=n;i++)
	{
		if(v[i].size()==1)
		{
			dfs(i,1,1);
			break;
		}
	}
}
