#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
map<int,int>::iterator it;
int s[5000009];
main()
{
	int n,k,i ;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	for(i=1;i<=n;i++)
	{
		if(s[i]>s[i-1]&&s[i]>s[i+1])
		{
			m[s[i]]++;
			i++;
		}
	}
	if(m.empty())return 0*printf("-1");
	if(m.size()>=k)
	{
		it=m.end(); it--;
		for(;k;it--,k--)printf("%d\n",it->first);
	}
	else 
	for(it=m.begin();it!=m.end();it++)printf("%d\n",it->first);
}
