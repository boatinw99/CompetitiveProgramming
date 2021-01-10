#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
ll s[4]={0,0,0,0};
ll r[4][2]={(-1,-1),(-1,-1),(-1,-1),(-1,-1)};
//+ - + -
ll E[5000];
ll T[5000][2];
main()
{
	ll n,i,in,j,f ;
	ll x=500000000000000,o,x1;
	ll d=0; // 0 1 2 3 // + - + -  
	bool k=0;
	scanf("%I64d",&n);
	scanf(" %I64d",&E[0]);
	T[0][0]=0;
	T[0][1]=0;
	j=0;
	for(i=1;i<n;i++)
	{
		scanf("%I64d",&in);
		if(E[j]<=0&&in<=0)
		{
			E[j]+=in;
			T[j][1]=i;
		}
		else if(E[j]>=0&&in>=0)
		{
			E[j]+=in;
			T[j][1]=i;
		}
		else 
		{
			E[j+1]=in;
			T[j+1][0]=i;
			T[j+1][1]=i;
			j++;
		}
	}
	d=0;
	f=j;
	for(i=0;i<=f;i++)
	{
		printf("%d ",E[i]);
	}
	for(i=0;i<=f;i++)
	{
		x=500000000000000;
		k=0;
		in=E[i];
	//	printf("%d ",in);
		if(in>0)
		{
			if(d==0)
			{
				s[0]+=in;	
				r[0][0]=T[0][0];
				r[0][1]=T[0][1];
				d=1;
			}
			else if(d==2)
			{
				s[2]+=in;
				r[2][0]=T[i][0];
				r[2][1]=T[i][1];
				d=3;
			}
			else if(d==3)
			{
				k=1;
			}
		}
		//
		else if(in<0)
		{
			if(d==0)
			{
				d=2;
				s[1]+=in;
				r[0][0]=0;
				r[0][1]=0;
				r[1][0]=T[0][0];
				r[1][1]=T[0][1];
			}
			else if(d==1)
			{
				d=2;
				s[1]+=in;
				r[1][0]=T[i][0];
				r[1][1]=T[i][1];
			}
			else if(d==3)
			{
				s[3]+=in;
				r[3][0]=T[i][0];
				r[3][1]=T[i][1];
			}
		}
		//start step
		
		if(k==1)
		{
			j=0;
			if(s[0]+s[1]<0)
			{
				j=1;
			}
			for(j;j<4;j++)
			{
				if(s[j]>0)o=s[j];
				else o=-s[j];
				if(o<=x)
				{
					x=o;
					x1=j;
				}
			}
			if(in<=x)
			{
				x=in;
				x1=4;
			}
			//printf("%I64d %I64d\n",x,x1);
			if(x1==0)
			{
				
			}
			else if(x1==1)
			{
				d=3;
				s[0]+=s[1]+s[2];
				s[1]=s[3];
				s[2]=in;
				s[3]=0;
				r[0][1]=r[2][1];
				r[1][0]=r[3][0];
				r[1][1]=r[3][1];
				r[2][0]=T[i][0];
				r[2][1]=T[i][1];
				r[3][0]=-1;
				r[3][1]=-1;
			}
			else if(x1==2)
			{
				d=3;
				s[1]+=s[2]+s[3];
				s[2]=in;
				s[3]=0;
				r[1][1]=r[3][1];
				r[2][0]=T[i][0];
				r[2][1]=T[i][1];
				r[3][0]=-1;
				r[3][1]=-1;
			}
			else if(x1==3)
			{
				d=3;
				s[2]+=s[3]+in;
				s[3]=0;
				r[2][1]=T[i][1];
				r[3][0]=-1;
				r[3][1]=-1;
			}
			else if(x1==4)
			{
				if(s[3]+in==0)
				{
					d=3;
					s[3]=0;
					r[2][1]=T[i][1];
				}
				else 
				{
					s[3]+=in;
					r[3][1]=T[i][1];
					d=3;
				}
			}
		}
	}
	//end
	for(i=0;i<=3;i++)
	{
		printf("%I64d ",s[i]);
	}
	printf("\n\n");
	if(s[0]>=0)
	{
		for(i=1;i<=3;i++)
		{
			if(s[i]==0)
			{
				printf("%I64d ",n);
			}
			else printf("%I64d ",r[i][0]);
		}
	}
	else
	{
		printf("0 ");
		for(i=2;i<=3;i++)
		{
			if(s[i]==0)
			{
				printf("%I64d ",n);
			}
			else printf("%I64d",r[i][0]);
		}
	}
}
