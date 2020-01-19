#include<bits/stdc++.h>
using namespace std ;
priority_queue<pair<double,int> > pq ;
main()
{
	int n;
	double x,y,f ;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf %lf",&x,&y);
		pq.push({-(x/y),y});
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf",&f);
		double co=0;
		while(f)
		{
			x=pq.top().first*-1;
			y=pq.top().second;
			pq.pop();
			if(y>f)
			{
				co+=x*f;	
				pq.push({-x,y-f});
				f=0;
			}
			else if(y<=f)
			{
				co+=y*x;
				f-=y;
			}
		}
		printf("%.3f\n",co);
	}
}
