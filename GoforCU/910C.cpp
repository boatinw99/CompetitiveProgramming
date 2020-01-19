#include<bits/stdc++.h>
using namespace std;
bool b[256];
int a[256];
priority_queue<pair<int,char> >pq;
main()
{
	int n,i=0,x=1,y;
	scanf("%d",&n);
	string s;
	while(n--)
	{
		cin >> s;
		b[s[0]]++;
		x=1;
		for(i=s.size()-1;i>=0;i--)
		{
			a[s[i]]+=x;
			x*=10;
		}
	}
	for(i='a';i<='j';i++)
	{
		pq.push({a[i],i});
	}
	bool k=0;
	int d=1;
	int co=0;
	while(!pq.empty())
	{
		x=pq.top().first;y=pq.top().second;
		if(!k&&!b[y])
		{
			k=1;
		}
		else co+=x*d,d++;
		pq.pop();
	}
	printf("%d",co);
	
}
