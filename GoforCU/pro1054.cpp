#include<bits/stdc++.h>
using namespace std ;
vector<int>v[11][50009];
vector<int>::iterator it;
long long pr=0;
int check(int x,int y,int r)
{
	int i,j,k,co,R,X,mi,ma ;
	vector<int>::iterator it1;
	for(i=1;i<=10;i++)
	{
		co=(r+i)*(r+i);
		for(j=x-(i+r)+1;j<x+(i+r);j++)
		{
			if(!v[i][j].empty())
			{
				X=(x-j)*(x-j);
				R=co-(X);
				R=sqrt(R-1);
				mi=R+y;
				ma=-R+y;
				if(mi>ma)swap(mi,ma);
				pr+=upper_bound(v[i][j].begin(),v[i][j].end(),ma)-lower_bound(v[i][j].begin(),v[i][j].end(),mi);
			}
		}
	}
}
main()
{
	int n,i,j,x,y,r ;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&r);
		v[r][x+20030].push_back(y);
	}
	for(i=1;i<=10;i++)
	{
		for(j=0;j<=50005;j++)sort(v[i][j].begin(),v[i][j].end());
	}
	for(i=1;i<=10;i++)
	{
		for(j=0;j<=50005;j++)
		{
			for(it=v[i][j].begin();it!=v[i][j].end();it++)
			{
				check(j,*it,i);	
			}
		}
	}
	printf("%lld",(pr-n)/2);
}
