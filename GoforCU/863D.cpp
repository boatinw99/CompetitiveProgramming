#include<bits/stdc++.h>
using namespace std;
int s[300009];
int A[300009][3];
main()
{
	int n,q,m,i,j,in;
	scanf("%d %d %d",&n,&q,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&s[i]);
	}
	for(i=1;i<=q;++i)
	{
		scanf("%d %d %d",&A[i][0],&A[i][1],&A[i][2]);
	}
	int k ;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&in);
		for(j=q;j>0;j--)
		{
			if(A[j][1]<=in&&in<=A[j][2])
			{
				if(A[j][0]==1)
				{
					if(in==A[j][1])in=A[j][2];
					else in--;
				}
				else 
				{
					in-=A[j][1];
					in=A[j][2]-in;
				}
			}
		}
		printf("%d ",s[in]);
	}
}
