#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e9+7;
ll dy[1009],k,co1=0;
ll pas[1009][1009];
string s;
ll e;
ll sum(ll in)
{
	ll i,x=0;
	for(i=0;i<e;i++)
	{
		if(s[i]=='1')
		{
			co1=(co1+pas[e-i-1][in-x])%N;
			x++;
			if(x>=in)return 0*co1++;
		}
	}
}
main()
{
	ll i,co,x ,j;
	cin >> s;
	e=s.size();
	scanf("%I64d",&k);
	dy[1]=1;
	if(k==0)return 0*printf("1");
	//if(e==1)return 0*printf("0");
	for(i=2;i<=e;i++)
	{
		x=i;co=0;
		while(x)
		{
			co+=x%2;
			x=x/2;
		}
		dy[i]+=dy[co]+1;
	}
	pas[0][0]=1;
	for(i=1;i<=e;i++)
	{
		pas[i][0]=1;
		for(j=1;j<=e;j++)
		{
			pas[i][j]=(pas[i-1][j]+pas[i-1][j-1])%N;
		}
	}
	for(i=1;i<=e;i++)
	{
		if(dy[i]==k)
		{
			sum(i);
		}
	}
	if(k==1)co1--;
	printf("%I64d",co1%N);
}
