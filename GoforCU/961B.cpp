#include<bits/stdc++.h>
using namespace std;
int s[100009];
bool t[100009];
main()
{
	int n,k,co=0,i,plus=0,d ;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	for(i=1;i<=n;i++)scanf("%d",&t[i]);
	for(i=1;i<=k;i++)
	{
		if(t[i])co+=s[i];
		else plus+=s[i];
	} d=plus;
	for(i;i<=n;i++)
	{
		if(t[i])co+=s[i]; else d+=s[i];
		if(!t[i-k])d-=s[i-k];
		plus=max(d,plus);
	}
	printf("%d",plus+co);
}
