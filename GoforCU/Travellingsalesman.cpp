#include<bits/stdc++.h>
using namespace std;
int s[20][20];
main()
{
	int n,m,x,y,val ;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d %d",&x,&y,&val);
		s[x][y]=val;
		s[y][x]=val;
	}
}
