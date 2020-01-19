#include<bits/stdc++.h>
using namespace std;
char s[1009];
char a[1009][1009];
bool b[1009][1009];
// L R U D
int d1[4]={0,0,-1,1};
int d2[4]={-1,1,0,0};
queue<pair<int,pair<int,int> > > q;
vector<pair<int,int> >v;
main()
{
	int n,m,i,j,x,p,y ;
	scanf("%d %d ",&n,&m);
	for(i=1;i<=n;i++)
	{
		gets(s);
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1];
			if(a[i][j]=='E')q.push({0,{i,j}}),b[i][j]++;
		}
	}
	int Q=-1 ;
	while(!q.empty())
	{
		p=q.front().first;
		x=q.front().second.first;
		y=q.front().second.second;
		q.pop();
		if(a[x][y]>'0'&&a[x][y]<='9')
		{
			v.push_back({p,a[x][y]-'0'});
		}
		for(i=0;i<4;i++)
		{
			if((!b[x+d1[i]][y+d2[i]]++)&&a[x+d1[i]][y+d2[i]]>='0'&&a[x+d1[i]][y+d2[i]]<='9'
				&&x+d1[i]>=1&&x+d1[i]<=n&&y+d2[i]>=1&&y+d2[i]<=m)
			{
				q.push({p+1,{x+d1[i],y+d2[i]}});
			}
			else if(a[x+d1[i]][y+d2[i]]=='S'&&Q==-1)
			{
				Q=p+1;
			}
		}
	}
	sort(v.begin(),v.end());
	int co=0;
	vector<pair<int,int> >::iterator it;
	for(it=v.begin();it!=v.end();it++)
	{
		if(it->first<=Q)co+=it->second;
	}
	printf("%d ",co);
}
