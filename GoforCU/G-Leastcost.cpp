#include<bits/stdc++.h>
using namespace std ;
string s;
typedef long long ll;
ll co=0;
priority_queue<pair<ll,ll> > pq ;
bool b[50009];
main()
{
	ll i,l=0,x,y ;
	cin >> s;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='(')
		{
			l++;
			b[i]=0;
		}
		else if(s[i]==')')
		{
			l--;
			b[i]=1;
		}
		else
		{
			scanf("%I64d %I64d",&x,&y);
			b[i]=1;
			pq.push({y-x,i});
			co+=y;
			l-- ;
		}
		if(l<0)
		{
			if(pq.empty())
			{
				break ;
			}
			else 
			{
				co-=pq.top().first;
				b[pq.top().second]=0;
				pq.pop();
				l+=2;
			}
		}
	}
	if(l!=0)
	{
		printf("-1");
		return 0;
	}
	printf("%I64d\n",co);
	for(i=0;i<s.length();i++)
	{
		printf("%c",(b[i])?(')'):('('));
	}
}
