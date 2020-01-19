#include<bits/stdc++.h>
using namespace std ;
string s;
stack<char> st;
priority_queue<pair<int,int> > pql,pqr;
int l=0,r=0;
void count()
{
	int i,x=0,y=0 ; 
	for(i=0;i<s.length();i++)
	{
		if(st.empty())st.push(s[i]);
		else if(st.top()=='('&&s[i]==')')st.pop();
		else st.push(s[i]);	
	}	
	while(!st.empty())
	{
		if(st.top()=='(')x++;
		else y++;
		st.pop();
	}
	if(y==0)l+=x;
	else if(x==0)r+=y;
	else if(x>=y)
	{
		pql.push({-y,x});
	}
	else
	{
		pqr.push({x,-y});
	}
}
main()
{
	int m,x,y ;
	scanf("%d ",&m);
	while(m--)
	{
		cin >> s;
		count();
	}
	while(!pql.empty())
	{
		y=pql.top().first*-1;
		x=pql.top().second ;	
		if(l>=y)
		{
			l+=x;
			l-=y;
		}
		else if(l<y)break;
		pql.pop();
	}
	while(!pqr.empty())
	{
		y=-pqr.top().second;
		x=pqr.top().first;
		if(l>=y)
		{
			l-=y;
			l+=x;
		}
		else break ;
		pqr.pop();
	}
	printf("%s",(pql.empty()&&pqr.empty()&&l==r)?("yes"):("no"));
}
