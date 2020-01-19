#include<bits/stdc++.h>
using namespace std ;
const int Mod=2009;
int dy[200009];
main()
{
	int i,n,k ;
	scanf("%d %d",&n,&k);
	dy[100001]=1; dy[100002]=1;
	for(i=100003;i-100001<=n;i++)
	{
		dy[i]=(dy[i-1]*2-dy[i-k-1])%Mod;
		if(dy[i]<0)dy[i]+=2009;
	}
	printf("%d",dy[100001+n]);
}
