#include<bits/stdc++.h>
using namespace std ;
int s[2][20009];
main()
{
	int n,k,i,j,l=0,r,p,x=0,y=1 ;
	scanf("%d %d",&n,&k);
	s[0][0]=1;s[1][0]=1;
	for(i=2;i<=n;i++)
	{
		r=i*(i-1)/2;
		for(j=1;j<=r&&j<=k;j++)
		{
			s[y][j]=s[y][j-1]+s[x][j];
			s[y][j]%=2012;
			if(r+1-j<=l)
			{
				if(r+1-j>=k&&l-(r+1-j)>=0&&l-(r+1-j)<=k)s[y][j]-=s[x][l-(r+1-j)]; 
				else if(r+1-j<=k)s[y][j]-=s[x][r+1-j];
				if(s[y][j]<0)s[y][j]+=2012;
			}	
		}
		swap(x,y);
		l=r;
	}
	printf("%d",s[x][k]);
}
