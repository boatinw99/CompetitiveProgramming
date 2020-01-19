#include<bits/stdc++.h>
using namespace std ;
map<string,pair<string,int> > m;
map<string,pair<string,int> > ::iterator it;
main()
{
	int i,j,n,k ;
	m["purple"]={"Power",0};
	m["green"]={"Time",0};
	m["blue"]={"Space",0};
	m["orange"]={"Soul",0};
	m["red"]={"Reality",0};
	m["yellow"]={"Mind",0};
	scanf("%d",&n);
	string s;
	for(i=0;i<n;i++)
	{
		cin >> s;
		m[s].second++;
	}
	printf("%d\n",6-n);
	for(it=m.begin();it!=m.end();it++)
	{
		if(it->second.second==0)
		{
			cout << it->second.first << endl ;
		}
	}
}
