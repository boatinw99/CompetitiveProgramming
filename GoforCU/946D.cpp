#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int q[509];
int dy[509][509];
int p[509];
main()
{
	int i,j,l,t,d,co=0 ;
	string s;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		cin >> s;
		l=0;
		for(j=0;j<s.size();j++)
			if(s[j]=='1')q[++l]=j+1;
		for(j=1;j<=l;j++)
		{
			for(d=1;d<=j;d++)
			{
				p[j]=max(p[j],(q[d]-q[1])+(q[l]-q[l-j+d]));		
				printf("%d ",p[j]);
			}
			printf("\n");
		}

		/*
		for(j=1;j<=l;j++)
		{
			for(d=0;d+j<=k;d++)
			{	
				dy[i][d+j]=max(dy[i-1][d+j],dy[i][d+j]);
				dy[i][d+j]=max(p[j]+dy[i-1][d],dy[i][d+j]);
			}
		}*/
		for(d=0;d<=l;d++)p[d]=0;
	}
}
