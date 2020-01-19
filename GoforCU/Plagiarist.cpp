#include<bits/stdc++.h>
using namespace std ;
int size;
int bi[500009];
int a[500009];
void update(int in,int co)
{
	for(in;in<=size;in+=in&-in)bi[in]+=co;
}
int find(int in)
{
	int w=0,j=size/2;
	for(j;j>0;j/=2)
	{
		if(bi[w+j]<in)in-=bi[w+j],w+=j;
	}
	return w+1;
}
main()
{
	int n,i,x,y ;
	scanf("%d",&n);
	for(size=1;size<=n;size*=2);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		update(i,1);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		y=find(x);
		printf("%d\n",a[y]);
		update(y,-1);
	}
}
