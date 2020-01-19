#include<bits/stdc++.h>
using namespace std ;
vector<int> v[100009];
vector<int>::iterator it,it1 ;
int s[11][100009];
int pr[11];
main()
{
	int n,p,i,j,x,st,ed ;
	scanf("%d %d",&n,&p);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x); v[x].push_back(i); 
		for(j=2;j<=p;j++)
		{
			scanf("%d",&x);
			s[j][i]=x;
		}
	}
	for(i=1;i<=p;i++)scanf("%d",&pr[i]); bool k;
	for(it=v[pr[1]].begin();it!=v[pr[1]].end();it++)
	{
		k=0;
		for(j=2;j<=p;j++)
		{
			if(s[j][*it]!=pr[j])
			{
				k++; break;
			}
		}	
		if(k==0)
		{
			printf("%d",*it);
			return 0;
		}
	}
	printf("NO");
}
