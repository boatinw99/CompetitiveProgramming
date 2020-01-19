#include<bits/stdc++.h>
using namespace std;
typedef long double ld ;
set<ld>s;
set<ld>::iterator it,it1;
ld x,y,l,r;
ld sum(ld p)
{
	ld j=1;
	while(p+j<=r)
	{
		s.insert(p+j);
		j*=y;
	}	
	if(p*x<r)
	sum(p*x);
}
main()
{
	scanf("%Lf %Lf %Lf %Lf",&x,&y,&l,&r);
	sum(1);	
	ld max1=0;
	if(!s.empty())
	{
	it=s.begin();
	while(*it<l)
	{
		s.erase(it++);
	}
	if(!s.empty())
	{
		it=s.begin();
		max1=max(max1,*it-l);
		it++;
		it1=s.begin();
		for(;it!=s.end();it++,it1++)	
		{	
			max1=max(max1,*it-*it1-1);
		}
		max1=max(max1,r-*it1);
	}
	else max1=r-l+1;	
	}
	else max1=r-l+1;
	printf("%.0Lf",max1);
}
