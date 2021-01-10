#include<bits/stdc++.h>
using namespace std;
int s[200009] ;
bool b[1000009];
stack<int> st;
main()
{
	int n,m,k,i,j,count=0,x=0,d=0,ch=0 ;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++)scanf("%d",&s[i]);
	sort(s,s+n);
	if(k==1)return 0*printf("%d",n);
	for(i=0;i<n;i++)
	{
		while(b[s[d]])d++;
		if(st.empty())st.push(s[i]),ch++;
		else
		{
			if(s[i]<s[d]+m)st.push(s[i]),ch++;
			else
			{
				if(ch-k+1>0)
				count+=ch-k+1;
				b[s[d]]++;
				while(ch-k+1>0)b[st.top()]++,st.pop(),ch--;
				st.push(s[i]);
			}
		}
	}
	if(ch-k+1>0)count+=ch-k+1;
	printf("%d",count);

}
