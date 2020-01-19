#include<bits/stdc++.h>
using namespace std;
int size;
int bi[100009];
int change(int in,int co)
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
	int n,k,i,j,y,x ;
	scanf("%d %d",&n,&k);
	for(size=1;size<=n;size*=2);
	for(i=1;i<=n;i++)change(i,1);
	y=k%n; if(y==0)y=n;
	while(n>0)
	{
		x=find(y);
		n--;
		printf("%d\n",x);
		if(n==0)return 0;
		change(x,-1);
		y=(y+k-1)%n; if(y==0)y=n;		
	}
}
