#include<bits/stdc++.h>
using namespace std ;
pair<pair<int,int>,int>s[101];
int q[101];
main()
{
	int n,k,m,a,x,d,j,check=-1;
	bool y=0;
	scanf("%d %d %d %d",&n,&k,&m,&a);
	int i,in=k,vote=m-a;
	for(i=0;i<=n;++i)
	{
		s[i].first.second=0;
		s[i].first.first=0;
		s[i].second=i;
		q[i]=0;
	}
	for(i=1;i<=a;i++)
	{
		scanf("%d",&x);
		s[x].first.first++;
		s[x].first.second=-i;
	}
	sort(&s[1],&s[n+1],greater<pair<pair<int,int>,int> >());
	if(n==k)
	{
		if(vote!=0)
		{
		for(i=1;i<=n;i++)
		{
			if(s[i].first.first!=0)
			q[s[i].second]=1;
			else q[s[i].second]=2;
		}
 		}
 		else 
		 {
		 	for(i=1;i<=n;i++)
		 	{	
			if(s[i].first.first==0)
		 	{
		 		q[s[i].second]=3;	
			}
			else q[s[i].second]=1;
			}
		 }
	}
	else
	{
	for(i=1;i<=n;i++)
	{
		d=vote;
		y=1;
		if(in<=0)
		{
		  q[s[i].second]=3;
		}
		else
		{
			for(j=i+1;j<=i+in&&j<=n;j++)	
			{
				d-=s[i].first.first-s[j].first.first+1;
				if(j==n)break;
			}
			if(d>=0&&j<=n)y=0;
			if(y==1)
			{
				if(s[i].first.first==0&&vote==0)
				{
					q[s[i].second]=3;
				}
				else if(s[i].first.first==0&&vote!=0)
				{
					q[s[i].second]=2;
				}
				else 
				q[s[i].second]=1;
				in--;
			}
			else 
			{
				q[s[i].second]=2;
				for(j=i+1;s[i+in-1].first.first-s[j].first.first+1<=vote&&j<=n;j++)
				{
					q[s[j].second]=2;
				}
				i=j-1;
				in=0;
			}
		}
	} 
	}
	for(i=1;i<=n;i++)
	printf("%d ",q[i]);
}
