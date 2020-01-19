#include<bits/stdc++.h>
using namespace std ;
int bi[500009];
int s[500009],n,size;
void update(int in,int co)
{
	for(in;in<=size;in+=in&-in)bi[in]+=co;
}
int getsum(int in)
{
	int co=0;
	for(;in>0;in-=in&-in)co+=bi[in];
	return co;
}
int find(int in)
{
	int w=0,j=size/2;
	for(;j>0;j/=2)
	{
		if(bi[w+j]<in)in-=bi[w+j],w+=j;
	}
	return w+1;
}
main()
{
	int i,j,x,y,m ;
	char a;
	scanf("%d",&n);
	for(size=1;size<=n;size*=2);
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	for(i=1;i<=n;i++)update(i,s[i]);
	scanf("%d",&m);
	while(m--)
	{
		cin >> a;
		if(a=='a')
		{
			scanf("%d %d",&x,&y);
			printf("%d\n",getsum(y)-getsum(x-1));
		}
		else if(a=='b')
		{
			scanf("%d %d",&x,&y);
			update(x,y-s[x]);
			s[x]=y;
		}
		else 
		{
			scanf("%d",&x);
			printf("%d\n",find(x));
		}
	}
}
