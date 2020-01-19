#include<bits/stdc++.h>
using namespace std ;
const int N=259;
int a[N][N];
int qst[N][N],qsb[N][N];
int slideb[N][N],slidet[N][N],n,m,K;
void take1(int x)
{
	int p,i,j,k ;
	for(i=x;i<=n;i++)
	{
		k=1;
		p=0;
		for(j=1;j<=m;j++)
		{
			p+=qsb[i][j]-qsb[x-1][j];
			while(k<j&&p-(qsb[i][k]-qsb[x-1][k])>=K)
			{
				p-=qsb[i][k]-qsb[x-1][k];
				k++;
			}
			slidet[i][j]=min(slidet[i][j],slidet[i-1][j]);
			slidet[i][j]=min(slidet[i][j],slidet[i][j-1]);
			if(p==K)
			{
				slidet[i][j]=min(slidet[i][j],(i-x+1)*2+(j-k+1)*2);
			}
		}		
	}
}
void take2(int x)
{
	int p,i,j,k ;
	for(i=x;i>0;i--)
	{
		p=0;
		k=m;
		for(j=m;j>0;j--)
		{
			p+=qst[i][j]-qst[x+1][j];
			while(k>j&&p-(qst[i][k]-qst[x+1][k])>=K)
			{
				p-=qst[i][k]-qst[x+1][k];
				k--;
			}		
			slideb[i][j]=min(slideb[i][j],slideb[i+1][j]);
			slideb[i][j]=min(slideb[i][j],slideb[i][j+1]);
			if(p==K)
			{
				slideb[i][j]=min(slideb[i][j],(x-i+1)*2+(k-j+1)*2);
			}
		}
	}
}
main()
{
	int i,j,q,x,y ;
	scanf("%d %d",&n,&m);
	scanf("%d %d",&q,&K);
	while(q--)
	{
		scanf("%d %d",&x,&y);
		a[x][y]++;
	}
	for(i=0;i<=n+2;i++)
	{
		for(j=0;j<=m+2;j++)
		{
			slideb[i][j]=1e6;
			slidet[i][j]=1e6;
		}
	}
	for(i=n;i>0;i--)
	{
		for(j=1;j<=m;j++)
		{
			qst[i][j]+=qst[i+1][j]+(a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			qsb[i][j]+=qsb[i-1][j]+a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		take1(i);
	}
	for(i=n;i>=1;i--)
	{
		take2(i);
	}
	int max1=1000009;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			max1=min(max1,slidet[i][j]+slideb[1][j+1]);
			max1=min(max1,slidet[i][j]+slideb[i+1][1]);
		}
	}
	if(max1==1000009)
	{
		printf("NO");
	}
	else printf("%d",max1);
}
