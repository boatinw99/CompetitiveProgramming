#include<bits/stdc++.h>
using namespace std ;
int s[200009];
int Q[200009];
vector<int>v[200009];
vector<int>::iterator it,it1 ;
void dfs(int x,int gc,int d,vector<int> t)
{
	int j,p=gc;
	gc=__gcd(gc,s[x]);
	Q[x]=gc;
	vector<int> u(d+3);
	vector<int>::iterator it2;
	//3,2
	for(j=0;j<d&&d>0;)
	{
		u[j]=__gcd(t[j],s[x]);
		Q[x]=max(Q[x],u[j]);
		if(u[j]<=gc)
		{
			t.erase(t.begin()+j);
			d--;
		}
		else j++;
	}	
	if(p>gc)
	{
		u[d]=p;
		Q[x]=max(p,Q[x]);
		d++;
	}
	for(it2=v[x].begin();it2!=v[x].end();++it2)
	{
		if(Q[*it2]==0)
		{
			dfs(*it2,gc,d,u);
		}
	}
	
}
main()
{
	int a,i=0,x,y;
	vector<int>t(5);
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
	int gc,d=0,j;
	for(it=v[1].begin();it!=v[1].end();++it)
	{
	    gc=__gcd(s[1],s[*it]);
		if(s[1]>gc)
		{
			t[d]=s[1];
			d++;
		}
		if(s[*it]>gc)
		{
			t[d]=s[*it];
			d++;
		}
		for(j=0;j<d;j++)if(t[j]>Q[*it])Q[*it]=t[j];
		for(it1=v[*it].begin();it1!=v[*it].end();++it1)
		{
			if(Q[*it1]==0)
			dfs(*it1,gc,d,t);
		}
	} 
	//
	for(i=1;i<=a;i++)
	printf("%d ",Q[i]);
}
