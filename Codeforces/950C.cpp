#include<bits/stdc++.h>
using namespace std;
string s ;
int sz;
vector<pair<int,string> > e;
int v[2][200009];
int c[200009];
int Call(int in,int count)
{
	if(c[in]!=-1)
	{
		Call(c[in]-1,count+1);
		//c[in]=0;
	}
	else 
	{
		int i;
		//c[in]=0;
		printf("\n%d ",count+1);
	}
	
}
int Pr(int in)
{
	printf("%d ",in+1);
	if(c[in]!=-1)
	{
		Pr(c[in]-1);
		c[in]=0;
	}
	else
	{
		c[in]=0;
	 } 
}
main()
{
	int i,j,k=0,n=0,m=0 ;
	cin >> s;sz=s.size();
	for(i=0;i<sz;i++)
	{
		if(s[i]-48==0)
		v[0][n++]=i+1;
		else v[1][m++]=i+1;
	}
	int u=0;
	for(i=0,j=0;i<sz;i++)
	{
		if(s[i]-48==0)
		{
			if(j==m)c[i]=-1;
			else if(i+1>v[1][j])return 0*printf("-1");
			else
			{
				c[i]=v[1][j];
				j++;
			}
		}
		else
		{	
			while(i+1>v[0][u])
			{
				u++;	
				if(u>=n)return 0*printf("-1");
			}
				c[i]=v[0][u];
				u++;
		}
	}
	string q;
	for(i=0;i<sz;i++)if(c[i]==-1)k++;	
	printf("%d",k);
	for(i=0;i<sz;i++)
	{
		q=i+1+48;
		if(c[i]==-1)printf("\n1 %d",i+1);
		else if(c[i]!=0)
		{
			Call(i,0);
			Pr(i);
		}
	}

}
