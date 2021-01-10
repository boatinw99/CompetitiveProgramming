#include<bits/stdc++.h>
using namespace std ;
int dy[59][2];
bool b[59];
main()
{
	int n,k,p,i,j,x ;
	scanf("%d %d %d",&n,&k,&p);
	while(n--)
	{
		scanf("%d",&x);
		for(i=k;i>1;i--)if(b[i-1])break;
		for(;i>1;i--)
		{
			b[i]++;
			if(dy[i-1][0]+dy[i-1][1]>=dy[i][0])
			{
				dy[i][0]=dy[i-1][0]+dy[i-1][1];
				dy[i][1]=x%p;
			}
			else 
			{
				dy[i][1]=(dy[i][1]+x)%p;
			}
		}
		dy[1][1]=(dy[1][1]+x)%p; b[1]++;
	}
	printf("%d",dy[k][0]+dy[k][1]);
}
