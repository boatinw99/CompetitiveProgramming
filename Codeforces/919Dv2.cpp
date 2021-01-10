#include<bits/stdc++.h>
using namespace std;
vector<int>v[300009];
int n,m ;
bool p=0;
string s;
int a[300009][26];
bool loop[300009];
bool b[300009];
int dfs(int i)
{
	int j;
	vector<int>::iterator it;
	loop[i]++;
	b[i]++;	
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(p)return 0;
		if(loop[*it])return 0*printf("-1"),p++;		
		if(!b[*it])dfs(*it);
		for(j=0;j<26;j++)a[i][j]=max(a[*it][j],a[i][j]);
	}
	loop[i]=0;
	a[i][s[i-1]-'a']++;
}
main()
{
	int i,j,x,y ;
	scanf("%d %d",&n,&m);	
	cin >> s;
	for(i=0;i<m;i++)scanf("%d %d",&x,&y),v[x].push_back(y);
	for(i=1;i<=n;i++)
	{
		if(!b[i])dfs(i);
	}
	int max1=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<26;j++)
		{
			max1=max(max1,a[i][j]);
		}
	}
	if(!p)
	printf("%d",max1);
}
