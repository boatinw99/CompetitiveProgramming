#include<bits/stdc++.h>
using namespace std;
typedef long long lld; 
map<lld,lld>p1,p2,p3;
map<lld,lld>::iterator it1;
map<pair<lld,lld>,lld>p4,p5,p6;
map<pair<lld,lld>,lld>::iterator it2;
map<pair<lld,pair<lld,lld> >,lld>p7;
map<pair<lld,pair<lld,lld> >,lld>::iterator it3;
main()
{
	int a,i;
	lld value=0,b,x,y,z;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%lld",&b);
		x=b/100;
		b=b%100;
		y=b/10;
		z=b%10;
		p1[x]++;
		p2[y]++;
		p3[z]++;
		p4[{x,y}]++;
		p5[{x,z}]++;
		p6[{y,z}]++;
		p7[{x,{y,z}}]++;
	}
		for(it1=p1.begin();it1!=p1.end();it1++)
		{
			value+=it1->second*(it1->second-1)/2;
		}
		for(it1=p2.begin();it1!=p2.end();it1++)
		{
			value+=it1->second*(it1->second-1)/2;
		}
		for(it1=p3.begin();it1!=p3.end();it1++)
		{
			value+=it1->second*(it1->second-1)/2;
		}
		for(it2=p4.begin();it2!=p4.end();it2++)
		{
			value-=it2->second*(it2->second-1)/2;
		}
		for(it2=p5.begin();it2!=p5.end();it2++)
		{
			value-=it2->second*(it2->second-1)/2;
		}
		for(it2=p6.begin();it2!=p6.end();it2++)
		{
			value-=it2->second*(it2->second-1)/2;
		}
		for(it3=p7.begin();it3!=p7.end();it3++)
		{
			value+=it3->second*(it3->second-1)/2;
		}
		printf("%lld",value);
}
