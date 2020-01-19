#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int>::iterator it,it1;
int s[5000009];
main()
{
	int n,k,i,si=1 ;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	for(i=1;i<=n;i++)if(s[i]>s[i-1]&&s[i]>s[i+1])v.push_back(s[i]);
	if(v.empty())return 0*printf("-1");
	sort(v.begin(),v.end()); it1=v.begin();
	for(it=v.begin()+1;it!=v.end();it++,it1++)if(*it!=*it1)si++;
	if(si>=k)
	{
		it=v.end()-1;
		it1=v.end()-1;
		printf("%d\n",*it); k--;
		for(it--;k;it--,it1--)
		{
			if(*it!=*it1)printf("%d\n",*it),k--;
		}
	}
	else
	{
		it=v.begin();
		it1=v.begin();
		printf("%d\n",*it); k--;
		for(it++;it!=v.end();it++,it1++)
		{
			if(*it!=*it1)printf("%d\n",*it);
		}
	}
}
