#include<bits/stdc++.h>
using namespace std;
int n,d;
string s;
dfs(int in,int co)
{
	int i ;
	if(in+d>=n-1)return 0*printf("%d",co+1),n=0;
	for(i=in+d;i>in;i--)
		if(s[i]=='1')return 0*dfs(i,co+1);
}
main()
{
	scanf("%d %d",&n,&d);	
	cin >> s ;
	dfs(0,0);
	if(n>0)printf("-1");
}
