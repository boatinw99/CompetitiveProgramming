#include<bits/stdc++.h>
using namespace std ;
char c[1000009];
int s[1000009][2];
int l=-1,r;
main()
{
	int n,k,i,j,m ;
	scanf("%d %d ",&n,&k);
	gets(c+1);
	r=n/(k+1)+3;
	for(i=1;i<=n;i++)
	{
		s[i][0]+=s[i-1][0]+(c[i]=='O');
		s[i][1]+=s[i-1][1]+(c[i]=='R');
	}
	bool q;
	while(l+1<r)
	{
		m=(l+r)/2;
		q=0;
		for(i=m*(k+1);i<=n;i++)
		{
			if(s[i][0]-s[i-m*(k+1)][0]==k*(s[i][1]-s[i-m*(k+1)][1]))
			{
				q++;
				break;
			}
		}
		printf("a %d %d\n",q,m);
		if(!q)r=m;
		else l=m;
	}
	printf("%d",l*(k+1));
}
