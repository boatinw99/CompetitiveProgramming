#include<bits/stdc++.h>
using namespace std ;
int s[60009];
const int p=30000;
main()
{
	int m,i,j,q,t,x;
	scanf("%d",&m);
	s[p]=m+4;
	for(q=1;q<=m;q++)
	{
		scanf("%d",&x);
		for(j=-30000;j<=30000;j++)
		{
			if(s[j+p]!=q&&s[j+p]!=0)
			{
				t=j+x;
				if(t<-30000)t+=60001;
				else if(t>30000)t-=60001;
				if(s[t+p]==0)s[t+p]=q;
			}
		}
	}
	for(i=30000;i>=0;i--)
	{
		if(s[i+p]!=0)
		{
			printf("%d ",i);
			return 0;
		}
	}
}
