#include<bits/stdc++.h>
using namespace std ;
char v[1009][1009]={0};
main()
{
	string s,q,p;
	cin >> s >> q;
	int a,i,m,n,i1,j1,j;
	m=s.size();
	n=q.size();
	for(j=2;j<=n+1;j++)
	{
		v[0][j]=q[j-2];
	}
	for(i=2;i<=m+1;i++)
	{
		v[i][0]=s[i-2];
	}
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		cin >> p ;
		v[1][1]=i;
		for(j=2;j<=n+1;j++)
		{
			if(v[0][j]==p[j-2]&&v[1][j-1]==i)
			{
				v[1][j]=i;
			}
		}
		for(i1=2;i1<=m+1;i1++)
		{
			if(v[i1][0]==p[i1-2]&&v[i1-1][1]==i)
			{
				v[i1][1]=i;
			}
		}
		for(i1=2;i1<=m+1;i1++)
		{
			for(j=2;j<=n+1;j++)
			{
				if(v[0][j]==p[i1+j-3]&&v[i1][j-1]==i)
				{
					v[i1][j]=i;
				}
				else if(v[i1][0]==p[i1+j-3]&&v[i1-1][j]==i)
				{
					v[i1][j]=i;
				}
			}
		}	
		if(v[m+1][n+1]==i)printf("Yes\n");
		else printf("No\n");
}
}
