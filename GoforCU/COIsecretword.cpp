#include<bits/stdc++.h>
using namespace std ;
const int N=1e6+7;
char s[N],p[N];
bool Q[N];
int pat[N];
stack<pair<char,int> > st;
inline void print()
{
	int x=st.top().first;
	st.pop();
	while(!st.empty())
	{
		print();
	}
	printf("%c",x);
}
main()
{
	int m,i,j,size ;
	scanf("%d ",&m);
	while(m--)
	{
		gets(s);
		scanf(" ");
		gets(p);
		scanf("");
		for(i=1,j=0;p[i]!='\0';)
		{
			if(p[i]==p[j])
			{
				pat[i]=j+1;
				i++; j++;
			}
			else
			{
				if(j==0)pat[i]=0,i++;
				else j=pat[j-1];
			}
		}
		size= i ;
		for(i=0,j=0;s[i]!='\0';)
		{
			if(s[i]==p[j])
			{
				j++;
				st.push({s[i],j});
				i++;
				if(j==size)
				{
					while(j--)
					{
						st.pop();
					}
					j=0;
					if(!st.empty())j=st.top().second;
				}	
			} 
			else
			{
				if(j==0)st.push({s[i],j}),i++;
				else j=pat[j-1];
			}
			
		}
		if(st.empty())printf("No COI Secret Code");
		else print();
		printf("\n");
	}
}
