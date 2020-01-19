#include<bits/stdc++.h>
using namespace std; 
int n,m,max1=0; 
vector<int> v[300009];
string s;
bool b[300009];
int dfs(int i,string q)
{
	vector<int>::iterator it;
	if(v[i].empty())
	{
		int d[26],j ;
		cout << q << endl ;
		for(j=0;j<26;j++)d[j]=0;
		for(j=0;j<q.size();j++)d[q[j]-'a']++;
		for(j=0;j<26;j++)max1=max(max1,d[j]);		
	}
	else
	{
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			if(max1==-2)return 0;
			if(b[*it]++)return 0*printf("-1"),max1=-2;
			dfs(*it,q+s[*it-1]);
		}
	}
}
main()
{
	int i,x,y ;
	string q ;
	scanf("%d %d",&n,&m);
	cin >> s;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
	}
	for(i=1;i<=n;i++)
		if(!b[i]++)q=s[i-1],dfs(i,q);
	if(max1<0);
	else printf("%d",max1);
}
