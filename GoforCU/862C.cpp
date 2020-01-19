#include<bits/stdc++.h>
using namespace std;
int s[500000];
main()
{
	int n,x,i;
	scanf("%d %d",&n,&x);
	if(n==1)printf("YES\n%d",x);
	else if(n==2)
	{
		if(x==0)printf("NO");
		else printf("YES\n0 %d",x);
	}
	else 
	{
		int ch=0;
		for(i=1;n==0;i++)
		{
			if(s[i]==0)
			{
				s[i]=1;
				n--;
				ch=i^ch;
			}	
		}
	}
}
