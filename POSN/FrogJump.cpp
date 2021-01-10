#include<bits/stdc++.h>
using namespace std ;
main()
{
	int m,n,i,j,d,e,f ;
	scanf("%d %d",&m,&n);
	int a[m][n],b[m][n];
	vector<vector<pair<int,int> > > v;
	for(i=0;i<m;i++) //1
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&d);
			a[i][j]=d;
		}
	}
	for(i=0;i<m;i++)//2
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&d);
			b[i][j]=d;
		}
	}
	for(i=0;i<m;i++)//input
	{
		for(j=0;j<n;j++)
		{
			f=a[i][j];
			e=b[i][j];
			v.insert(v[i][j],{f,e});
			printf("%d ",v[i][j].first,v[i][j].second);
		}
		printf("\n");
	}
} 
