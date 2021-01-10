#include<bits/stdc++.h>
using namespace std ;
int S[10000];
const int N=1e9;
main()
{
	int a,x,y,R,i,p;
	bool t=0;
	scanf("%d",&a);
	S[0]=2;
	R=1;
	for(i=3;i*i<=N;i++)
	{
		t=0;
		for(p=0;p<R&&S[p]*S[p]<=i;p++)
		{
			if(i%S[p]==0)
			{
				t=1;
				break;
			}
		}
		if(!t)
		{
			S[R]=i;
			R++;
		}
	}
	printf("%d",R);	
	/*
	for(i=0;i<a;i++)
	{
		scanf("%d %d",&x,&y);
		//less more
		if(x>y)
		{
			R=x;
			x=y;
			y=R;
		}
		R=2;
		while(x!=1&&y!=1)
		{
			if(x%R==0&&y%(R*R)==0)
			{
				x=x/R;
				y=y/R/R;
			}
			else if(x%(R*R)==0&&y%R==0)
			{
				x=x/R/R;
				y=y/R;
			}
			else if(R>x||R>y)
			{
				break;
			}
			else R++;
		}
		if(x==1&&y==1)printf("YES\n");
		else printf("NO\n");
	}*/
}
