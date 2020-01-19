#include<bits/stdc++.h>
using namespace std ;
const int N=50009;
int a[N] ;
struct Node
{
	int gcd=0,num=0;
}st[N];
void construct(int l,int r,int m)
{
	int mid=(l+r)/2;
	if(l==r)
	{
		st[m].gcd=a[l];
		st[m].num=1;
		return ;
	}
	construct(l,mid,m*2+1); construct(mid+1,r,m*2+2);
	st[m].gcd=__gcd(st[m*2+1].gcd,st[m*2+2].gcd);
	if(st[m].gcd!=st[m*2+1].gcd&&st[m].gcd!=st[m*2+1].gcd)
	{
		st[m].num=0;
	}
	else if(st[m*2+1].gcd<st[m*2+2].gcd)
	{
		st[m].num=st[m*2+1].num;
	}
	else if(st[m*2+2].gcd<st[m*2+1].gcd)
	{
		st[m].num=st[m*2+2].num;
	}
	else st[m].num=st[m*2+1].num+st[m*2+2].num;
}
struct Node getgcd(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	Node tree;
	tree.gcd=0; tree.num=0;
	if(r<x||l>y)
	{
		return tree;
	}
	if(l>=x&&r<=y)
	{
		tree=st[m];
		return tree;
	}
	Node ans1,ans2,ans;
	ans1=getgcd(l,mid,x,y,m*2+1); 
	ans2=getgcd(mid+1,r,x,y,m*2+2);
	ans.gcd=__gcd(ans1.gcd,ans2.gcd);
	if(ans.gcd!=ans1.gcd&&ans.gcd!=ans2.gcd)
	{
		ans1.num=0;
		return ans ;
	}
	if(ans1.gcd==0)
	{
		ans.num=ans2.num;
		return ans;
	}
	if(ans2.gcd==0)
	{
		ans.num=ans1.num;
		return ans;
	}
	if(ans1.gcd<ans2.gcd)
	{
		ans.num=ans1.num;
		return ans;
	}
	else if(ans2.gcd<ans1.gcd)
	{
		ans.num=ans2.num;
		return ans;	
	}
	else
	{
		ans.num=ans1.num+ans2.num;
		return ans;
	} 
	
}
main()
{
	int n,i ;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	construct(0,n-1,0);
	printf("1-6 is %d \n",getgcd(0,n-1,0,5,0).num);
	printf("1-4 is %d\n",getgcd(0,n-1,0,3,0).num);
	printf("2-6 is %d\n",getgcd(0,n-1,1,5,0).num);
	printf("3-6 is %d\n",getgcd(0,n-1,2,5,0).num);	
	printf("1-5 is %d\n",getgcd(0,n-1,0,4,0).num);	
	printf("2-4 is %d\n",getgcd(0,n-1,1,3,0).num);	
	printf("4-6 is %d\n",getgcd(0,n-1,3,5,0).num);	
	printf("2-5 is %d\n",getgcd(0,n-1,1,4,0).num);	
	printf("5-6 is %d\n",getgcd(0,n-1,4,5,0).num);	
	
	
	
}
