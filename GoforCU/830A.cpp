#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
vector<ll> v[1000];
vector<ll>::iterator it ;
vector<ll> s,s1 ;
ll N=1e10,M=0,R;
main()
{
	ll a,b,c,i,j,in,in1,k=0,d ;
	scanf("%I64d %I64d %I64d",&a,&b,&c);
	for(i=0;i<a;i++)
	{
		scanf(" %I64d",&in);
		s.push_back(in);
	}
	for(i=0;i<b;i++)
	{
		scanf(" %I64d",&in);
		s1.push_back(in);
	}
	sort(s.begin(),s.end());
	sort(s1.begin(),s1.end());
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			in=max(s[i]-s1[j],s1[j]-s[i]);
			in1=max(s1[j]-c,c-s1[j]);
			v[i].push_back(in+in1);
		}
	}
	while(N>M+1)
	{
		R=(N+M)/2;
		d=0;
		k=0;
		for(i=0;i<a;i++)
		{			
			d=0;	
			for(it=v[i].begin()+k;it!=v[i].end();++it)
			{
				k++;
				if(*it<R)
				{
					d=99;
					break;
				}
			}
			if(d==0)break;
		}
		if(d==0)
		{
			M=R;
		}
		else
		{
			N=R;
		}
	}
	printf("%I64d",M);
}
