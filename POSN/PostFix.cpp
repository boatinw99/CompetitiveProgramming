#include<bits/stdc++.h>
using namespace std ;
main()
{
	queue<char> q ;
	stack<char> prob ;
	string s ;
	cin >> s ;
	int i,k=0,check=0 ;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='(')
		{
			check--;
			k=0;
		}
		else if(s[i]==')')
		{
			check++;
			if(check==0)
			{
				while(!prob.empty())
				{
					q.push(prob.top());
					prob.pop();
				}
			}
			else
			{
			q.push(prob.top());
			prob.pop();
		}
			
			k=0;
		}
		else if(s[i]=='+')
		{
			if(k==2)
			{
				q.push(prob.top());
				prob.pop();
			}
			prob.push('+');
		}
		else if(s[i]=='-')
		{
			if(k==2)
			{
				q.push(prob.top());
				prob.pop();
			}
			prob.push('-');
		}
		else 
		{
			
			q.push(s[i]);
			k++;
		}
	}
	while(!q.empty())
		{
			printf("%c",q.front());
			q.pop();
		}
}
