#include<bits/stdc++.h>
using namespace std ;
const int N=1e6+9;
int a[N];
pair<int,int> q[N];
bool check(int x,int y)
{
	for(x;x<y;x++)
	{
		if(a[x]!=0)return 0;
	}
	return 1;
}
main()
{
	int n,x,i,y,k1,k2 ;
	bool d;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		q[i]={x,i};
	}
	sort(q+1,q+1+n,greater<pair<int,int> >());
	for(i=1;i<n;)
	{	
		k1=q[i].first ; x=q[i].second;
		i++;
		k2=q[i].first ; y=q[i].second ;
		if(y<x)swap(x,y),swap(k1,k2);
		d=check(x,y);
		int x1=x,y1=y;
		if(d==1)
		{
			for(x;x<y;x++)a[x]=min(k1,k2);
		}
		else
		{
			for(x;a[x]==0;x++)a[x]=k1;
			y--;
			for(;a[y]==0;y--)a[y]=k2;
		}
	}
	//a[q[n].second]=max(a[q[n].second],q[n].first);
	//a[q[n-1].second]=max(a[q[n-1].second],q[n-1].first);
	for(i=1;i<n;i++)
	{
		//if(a[i]==0)a[i]=min(a[i-1],a[i+1]);
		printf("%d ",a[i]);
	}
}
