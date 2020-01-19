#include<bits/stdc++.h>
using namespace std ;
double dy[(2<<20)+9];
queue<pair<int,int> >q;
double s[29];
main()
{
	int n,i,j,k;
	double x,y;
	scanf("%d",&n); 
	q.push({0,0});	
	dy[0]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)scanf("%lf",&s[j]),s[j]/=100;
		while(q.front().first==i)
		{
			k=q.front().second;
			for(j=0;j<n;j++)
			{
				if((k&1<<j)==0)
				{
					if(dy[k|1<<j]==0)
					{
						q.push({q.front().first+1,k|1<<j});
					}
					dy[k|1<<j]=max(dy[k|1<<j],dy[k]*s[j]);			
				}
			}	
			q.pop();
		}
	}
	printf("%.6f",dy[(1<<n)-1]*100);
}
