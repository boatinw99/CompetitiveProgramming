#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll a[5000];
ll b[5000][4];
ll c[5000][4];
stack<char> s;
main()
{
	ll n,i,j,x,MAX=-1 ;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<=3;j++)
		{
			b[i][j]=0;
			c[i][j]=0;
		}
	}
	for(i=0;i<=3;i++)
	{
		if(i%2==0)//+
		{
			b[0][i]=a[0];
		}
		else b[0][i]=-a[0];
		c[0][i]=i;
	}
	for(i=1;i<n;i++)
	{
		b[i][0]=b[i-1][0]+a[i];
		c[i][0]=0;
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<=3;j++)
		{
			if(j%2==1)
			{
		     	b[i][j]=max(b[i-1][j-1]-a[i],b[i-1][j]-a[i]);
		     	if(b[i-1][j-1]-a[i]>=b[i-1][j]-a[i])
		     	{
		     		c[i][j]=j-1;	
				}
				else c[i][j]=j;
			}
			else 
			{
				b[i][j]=max(b[i-1][j-1]+a[i],b[i-1][j]+a[i]);
				if(b[i-1][j-1]+a[i]>=b[i-1][j]+a[i])
		     	{
		     		c[i][j]=j-1;	
				}
				else c[i][j]=j;
			}
			
			
		}
	}
	for(i=0;i<=3;i++)
	{
		if(b[n-1][i]>MAX)
		{
			MAX=b[n-1][i];
			x=i;
		}
	}
	for(i=n-1;i>=0;i--)
	{
		if(x%2==0)
		{
			s.push('+');
		}
		else s.push('-');
		x=c[i][x];
	}
	x=0;
	ll y=0;
	char e;
	if(s.top()=='-')printf("0 "),e='-',y++;
	else e='+';
	while(!s.empty())
	{
		if(s.top()==e)
		{
			s.pop();
		}
		else 
		{
			printf("%I64d ",x);
			y++;
			if(e=='+')e='-';
			else e='+';
			s.pop();
		}
		x++;
	}
	for(y;y<3;y++)
	{
		printf("%I64d ",n);
	}
	/*
	for(i=0;i<n;i++)
	{
		for(j=0;j<=3;j++)
		{
			printf("%I64d ",c[i][j]);
		}
		printf("\n");
	}*/
}
