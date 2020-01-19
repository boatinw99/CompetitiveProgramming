#include<bits/stdc++.h>
using namespace std;
int d[1009][1009];
queue<pair<int,pair<int,int> > > qu;
string s ,q ,in ;
main()
{
	int n,i,j,x,y,w ;
	cin >> s; cin>> q;
	scanf("%d",&n);
	for(j=1;j<=n;j++)
	{
		cin>> in;
		qu.push({0,{0,0}});
		while(!qu.empty())
		{
			w=qu.front().first;
			x=qu.front().second.first;
			y=qu.front().second.second;
			qu.pop();
			if(s[y]==in[w]&&d[x][y+1]!=j&&y+1<=s.size())
			{
				d[x][y+1]=j;
				qu.push({w+1,{x,y+1}});
			}
			if(q[x]==in[w]&&d[x+1][y]!=j&&x+1<=q.size())
			{
				d[x+1][y]=j;
				qu.push({w+1,{x+1,y}});
			}
		}
		if(d[q.size()][s.size()]==j)printf("Yes\n");
		else printf("No\n");
	}
			
}
