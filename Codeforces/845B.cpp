#include<bits/stdc++.h>
using namespace std;
vector<int>l,r ;
vector<int>::iterator it1,it2 ;
int sum1,sum2;
main()
{
	int i,j,co=0 ;
	string s,q,e ;
	cin >> s ;
	q=s.substr(0,3);
	e=s.substr(3,3);
	for(i=0;i<=2;i++)
	{
		sum1+=q[i]-'0';
		sum2+=e[i]-'0';
		l.push_back(q[i]-'0');
		r.push_back(e[i]-'0');
	}
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());
	while(sum1!=sum2)
	{
		co++;
		if(sum1>=sum2)
		{
			it1=r.begin();
			it2=l.end();
			it2--;
			if(9-*it1>=*it2)
			{
				sum2+=9-*it1;
				r.erase(it1);
				if(sum2>=sum1)break;
			}
			else 
			{
				
				sum1-=*it2;
				l.erase(it2);
				if(sum1<=sum2)break;
			}
		}
		else
		{
			it2=r.end();
			it2--;
			it1=l.begin();
			if(9-*it1>=*it2)
			{
				sum1+=9-*it1;
				l.erase(it1);
				if(sum1>=sum2)break;
			}
			else if(9-*it1<*it2)
			{
				sum2-=*it2;
				r.erase(it2);
				if(sum2<=sum1)break;
			}
		}
	}
	printf("%d",co);
}
