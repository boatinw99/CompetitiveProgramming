#include<bits/stdc++.h>
using namespace std ;
int s[500009];	
int di=1,d=1,n;
int find(int i)
{
	int j;	
	if(di==-1)
	{
		if(i<=d)
		{
			j=d-i+1;
		}	
		else
		{
			j=(n-i)+d+1;
		}
	}
	else
	{
		if(d<=i)
		{
			j=i-d+1;
		}
		else
		{
			j=(i)+(n-d)+1;
		}
	}
	return j;
}
main()
{
	int i,j,x,y,m,l,r,k ;
	char c;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	while(m--)
	{
		scanf(" %c",&c);
		if(c=='q')
		{
			scanf("%d",&x);
			printf("%d\n",s[find(x)]);
		}
		else if(c=='a')
		{
			scanf("%d %d",&x,&y);
			swap(s[find(x)],s[find(y)]);
		}
		else if(c=='b')
		{
			scanf("%d %d",&x,&k);
			s[find(x)]=k;
		}
		else
		{
			scanf("%d",&x);
			di*=-1;
			if(d<=x)
			{
				l=d-1;
				r=x-d;
			}
			else
			{
				l=d-x-1;
				r=n-d;
			}
			if(l>r)d-=l-r;
			else d+=r-l;		
		}
	}
}
