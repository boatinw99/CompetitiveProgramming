#include<bits/stdc++.h>
using namespace std ;
string s;
char c[9]={'v','c','o','d','e','c','u','b','e'};
int pr[9];
main()
{
	int i,n,j ;
	int min1=INT_MAX,p;
	char q;
	cin >> s;
	n=s.length();
	pr[0]=1;
	for(i=1;i<=8;i++)pr[i]=1e9;
	for(i=0;i<n;i++)
	{
		q=s[i];
		for(j=1;j<9;j++)
		{
			if(q==c[j])
			{
				pr[j]=pr[j-1];		
			}
			else
			{
				pr[j]++;
			}
		}
		if(pr[8]<min1)
		{
			min1=pr[8];
			p=i;
		}
	}
	p++;
	if(min1>1e6)printf("-1");
	else
	printf("%d %d",p-min1+1,p);
}
