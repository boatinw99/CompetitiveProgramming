#include<bits/stdc++.h>
using namespace std ;
int bi[280009],n,size=1;
int change(int in,int co)
{
	for(in;in<=size;in+=in&-in)bi[in]+=co;
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
	int i,x,k,p ;
	scanf("%d %d",&n,&k); p=n;
	for(size;size<=n;size*=2);
	for(i=1;i<=n;i++)
	{
		change(i,1);
	}
	while(p)
	{
		x=find(k);
		p--;
		if(p==0)return 0*printf("%d",x);
		change(x,-1);
		k=(x+k-1)%p; if(!k)k=p; 
	}
}

