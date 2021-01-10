#include<bits/stdc++.h>
using namespace std;
int a[200009];
int qu[200009];
main()
{
	string s;
	int n,i,j,x ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	cin >> s;
	for(i=1;i<=s.size();i++)
	{
		qu[i]+=qu[i-1]+s[i-1]-'0';
	}
	for(i=1;i<=n;i++)
	{
		if(i!=a[i])
		{
			if(a[i]>i&&qu[a[i]-1]-qu[i-1]!=a[i]-i)
			{
				printf("NO");
				return 0;
			}
			else if(i>a[i]&&qu[i-1]-qu[a[i]-1]!=i-a[i])
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
}
