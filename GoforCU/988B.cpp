#include<bits/stdc++.h>
using namespace std ;
vector<string> v[109];
vector<string> ::iterator it;
bool find1(int i,int j)
{
	string s=*v[i].begin();
	string q=*v[j].begin();
	bool d=0;
	for(int x=0;x+s.length()<=q.length();x++)
	{
		if(q.substr(x,s.length())==s)
		{
			d++;
			break;
		}
	}
	return !d;
}
main()
{
	int n,i,j ;
	bool d=0;
	string s; 
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cin >> s;
		if(!v[s.length()].empty()&&*v[s.length()].begin()!=s)
		{
			d++;
		}
		v[s.length()].push_back(s);
	}
	for(i=1;i<=100;i++)
	{
		if(!v[i].empty())
		for(j=i+1;j<=100;j++)
		{
			if(!v[j].empty())
			{
				bool k=find1(i,j);
				if(k==1)d++;
				break;
			}
		}
	}
	if(d==1)printf("NO");
	else
	{
		printf("YES\n");
		for(i=1;i<=100;i++)
		{
			for(it=v[i].begin();it!=v[i].end();it++)
			{
				cout << *it << endl ;
			}
		}
	}
}
