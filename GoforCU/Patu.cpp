#include<bits/stdc++.h>
using namespace std ;
vector<int> v[10009];
vector<int> ::iterator it1,it2;
int a[300009];
int ty(int size)
{
	int x;
	if(size>50000)
	{
		x=(rand()%1000)*100;
		x=x%size;
		return x;
	}
	else 
	{
		x=rand()%size ;
		return x;
	}
}
int query(int l,int r)
{
	int k,ran,size=r-l+1,x,y ;
	for(k=1;k<=50;k++)
	{
		ran=ty(size);
		x=a[l+ran];
		it1=lower_bound(v[x].begin(),v[x].end(),l);
		it2=upper_bound(v[x].begin(),v[x].end(),r);
		it2--;
		if(it2-it1+1>size/2)return x;
	}
	return -1 ;
}
main()
{
	int n,m,k,l,r,i,j ;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
	}
	scanf("%d",&m);
	int b;
	while(m--)
	{
		scanf("%d %d",&l,&r);
		b=query(l,r);
		if(b==-1)printf("no");
		else
		{
			printf("yes %d",b);
		}
		printf("\n");
	}
}
