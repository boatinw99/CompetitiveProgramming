#include<bits/stdc++.h>
using namespace std ;
int N=0,M=150009,K ;
char s[100000];
int a[100000],b[100000],A=0,B=0,C,P,O;
bool k,q;
main()
{
	int d,i,j;
	scanf("%d ",&d);
	gets(s);
	for(i=0;i<d;i++)
	{
		if(s[i]=='P')
		{
			b[B]=i;
			B++;
		}
		else if(s[i]=='*')
		{
			a[A]=i;
			A++;
		}
	}
	//P O
	while(N+1<M)
	{
		K=(N+M)/2;
		C=0;
		k=0;
		for(i=0;i<B;i++)
		{
			q=0;
			P=C,O=A-1; 
			while(P+1<O)
			{
				i=(P+O)/2;
				if(a[C]>b[i])
				{
					if(a[j]-b[i]<=K)
					{
					//	printf("%d %d\n",a[j],b[i]);
						C=j+1;
						q=1;
					}
				}
				else if(b[i]-a[C]>=a[j]-b[i])
				{
					if((a[j]-b[i])*2+b[i]-a[C]<=K)
					{
					//	printf("%d %d %d\n",i,j,(a[j]-b[i])*2+b[i]-a[C]);
						C=j+1;
						q=1;
						break;
					}
				}
				else 
				{
					if((b[i]-a[C])*2+a[j]-b[i]<=K)
					{
					//	printf("%d %d %d\n",i,j,(b[i]-a[C])*2+a[j]-b[i]);
						C=j+1;	
						q=1;
						break;
					}
				}	
			}
			if(q==0)
			{
				if(b[i]-a[C]>K&&b[i]>a[C])
				{
					
				}
				else if(a[C]-b[i]>K&&a[C]>b[i])
				{
					
				}
				else 
				{
					//printf("%d %d\n",b[i],a[C]);
					C=j+1;	
				}	
			}
			if(C==A)
			{
				k=1;
				break;
			}
		}
		if(k==1)
		{	
			M=K;
		}
		else 
		{
			N=K;
		}
	}
	printf("%d",M);
}
