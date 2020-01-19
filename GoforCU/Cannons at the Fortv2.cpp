#include<bits/stdc++.h>
using namespace std;
vector<int>v(2);
vector<int>::iterator p1,p2;
main()
{
	int m,n,k,l,i,j,x,co,count=0;
	scanf("%d %d %d %d",&n,&m,&k,&l);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		v.push_back(x);
	}
	v.push_back(-1);
	while(k--)
	{
		co=0,count=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			if(co<n)
			{
			p2=lower_bound(v.begin()+co,v.end()-1,x+l);
			if(x+l<*p2)p2--;
			p1=lower_bound(v.begin()+co,v.end()-1,x-l);	
			count+=(p2-p1)+1;
			co=p2-v.begin()+1;
			if(p2==v.end()-1||p1==v.end()-1)count--;
			}
		}
		printf("%d\n",count);
		
	}
}
