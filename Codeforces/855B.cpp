#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[3][100000];
ll E[100000];
main()
{
	ll a,i;
	ll R[3];
	scanf("%I64d",&a);
	scanf("%I64d %I64d %I64d",&R[0],&R[1],&R[2]);
	for(i=0;i<a;i++)
	{
		scanf("%I64d",&E[i]);
	}
	s[0][0]=E[0]*R[0];
	for(i=1;i<3;i++)
	{
		s[i][0]=s[i-1][0]+R[i]*E[0];
	}
	for(i=1;i<a;i++)
	{
		s[0][i]=max(s[0][i-1],R[0]*E[i]);
	}
	ll j;
	for(i=1;i<3;i++)
	{
		for(j=1;j<a;++j)
		{
			s[i][j]=max(s[i][j-1],R[i]*E[j]+s[i-1][j]);
		}
	}
	ll max1=-1000000000000000000000;
	for(i=0;i<a;i++)
	{
		if(s[2][i]>max1)max1=s[2][i];
	}
	printf("%I64d",max1);
	ll x= -3000000000000000000;
}
