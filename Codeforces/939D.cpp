#include<bits/stdc++.h>
using namespace std;
string s,q ;
stack<pair<char,char> >st;
char a[256];
int rankr[256];
char find(char c)
{
	char w;
	if(a[c]!=c)
	{
		w=find(a[c]);
		a[c]=w;	
		return w ;
	}
	else return c;	
}
unionset(char c,char d)
{
	char l,r;
	l=find(c); r=find(d);
	if(l!=r)
	{
		st.push({c,d});
		if(rankr[l]>=rankr[r])
		{
			rankr[l]+=rankr[r];
			a[r]=l;
		}
		else
		{	
			rankr[r]+=rankr[l];
			a[l]=r;
		}
	}
}
main()
{
	int n,i ;
	scanf("%d",&n);
	cin >> s; cin >> q;
	for(i='a';i<='z';i++)a[i]=i,rankr[i]=1;
	for(i=0;i<n;i++)
	{
		unionset(s[i],q[i]);
	}
	printf("%d\n",st.size());
	while(!st.empty())
	{
		printf("%c %c\n",st.top().first,st.top().second);
		st.pop();
	}
}
