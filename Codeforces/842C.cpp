#include<bits/stdc++.h>
using namespace std ;
int s[200009];
int Q[200009];
vector<int>v[200009];
vector<int>::iterator it,it1 ;
void dfs(int x,int gc,int a1,int a2)
{
	vector<int>::iterator it2;
	int p=gc;
	if(a1!=0)
	{
		a1=__gcd(a1,s[x]);
	}
	if(a2!=0)
	{
		a2=__gcd(a2,s[x]);		
	}
	gc=__gcd(gc,s[x]);
	if(a1<=gc)a1=a2,a2=0;
	if(a2<=gc)a2=0;
	if(a1==a2)a2=0;
	if(p>gc)
	{
		if(a1==0)a1=p;
		else if(a2==0)a2=p;
		else 
		{
			printf("%d %d %d %d %d \n",gc,a1,a2,p,s[x]);
		}
	}
	Q[x]=max(a1,a2);
	Q[x]=max(gc,Q[x]);
	for(it2=v[x].begin();it2!=v[x].end();it2++)
	{
		if(Q[*it2]==0)
		{
			dfs(*it2,gc,a1,a2);
		}
	}
}
main()
{
	int a,i=0,x,y;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%d",&s[i]);
		Q[i]=0;
	}
	for(i=1;i<a;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	Q[1]=s[1];
	x=s[1];
	y=0;
	int gc,a1=0,a2=0;
	for(it=v[1].begin();it!=v[1].end();++it)
	{
	    gc=__gcd(s[1],s[*it]);
		if(s[1]>gc)
		{
			a1=s[1];
		}
		if(s[*it]>gc)
		{
			a2=s[2];
		}
		Q[*it]=max(gc,a1);
		Q[*it]=max(Q[*it],a2);
		for(it1=v[*it].begin();it1!=v[*it].end();++it1)
		{
			if(Q[*it1]==0)
			dfs(*it1,gc,a1,a2);
		}
	} 
	for(i=1;i<=a;i++)
	printf("%d ",Q[i]);
}
