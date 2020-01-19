#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool b[59][59];
ll a[59][59];
ll d[59][59];
queue<pair<ll,ll> > q;
main()
{
	ll m,n,k,x,y ;
	scanf("%lld %lld",&m,&n);
	scanf("%lld",&k);
	while(k--)
	{
		scanf("%lld %lld",&x,&y);
		b[n-y+1][x]++;
	}
	a[n][1]=1;
	q.push({n,1});
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		q.pop();
		if(!d[x][y])
		{
			d[x][y]++;
			if(b[x-1][y]==0&&x-1>=1)
			{
				a[x-1][y]+=a[x][y];
				q.push({x-1,y});
			}
			if(b[x][y+1]==0&&y+1<=m)
			{
				a[x][y+1]+=a[x][y];
				q.push({x,y+1});	
			}
		}
	}
	printf("%lld",a[1][m]);
}
