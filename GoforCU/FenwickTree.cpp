#include<bits/stdc++.h>
using namespace std;
int fr[11]={3,2,-1,6,5,4,-3,3,7,2,3},n=11;
int bi[40];
int update(int in,int co)
{	
	in++;
	while(in<=n)
	{
		bi[in]+=co;	
		in+=in&-in;
		
	}
}
int getsum(int in)
{
	int count=0;
	while(in>0)
	{
		count+=bi[in];
		in-=in&-in;
	}
	return count;
}
main()
{
	int index=0,i,x=0;
	for(i=0;i<n;i++)
	{
		update(i,fr[i]);
	}
	printf("%d",x=getsum(2));
	//Fenwick Tree is algorithm to find sum of lenght that wanted
}
