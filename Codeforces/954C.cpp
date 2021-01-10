#include<bits/stdc++.h>
using namespace std;
const int N=1e9;
main()
{
	int y=1,n,i,in;
	bool k=0;
	scanf("%d",&n);
	scanf("%d",&i);n--;
	while(n--)
	{
		scanf("%d",&in);
		if(in+1==i)
		{
			if(i-in+1!=y&&k==1)return 0*printf("NO");			
			y=max(y,i-in+1);
		}
		else if(i+1==in)
		{
		//	if(in-i+1)
		}
		else if(in>i) 
		{
			k=1;
			if(in-i<y)return 0*printf("NO");
			else y=in-i;
		}
		else if(i>in)
		{
			k=1;
			if(i-in<y)return 0*printf("NO");
			else y=i-in;
		}
	}
	printf("YES\n%d %d",N,y);
}
