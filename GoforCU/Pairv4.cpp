#include<bits/stdc++.h>
using namespace std ;
int a[100009];
int qs[100009];
long long pr=0 ;	
int L[100009],R[100009];
int qsL[100009],qsR[100009];
void merge(int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1; int n2=r-m ;
	for(i=0;i<=100000;i++)qsL[i]=qsR[i]=0;
	for(i=1;i<=n1;i++)L[i]=a[l+i-1],qsL[i]+=L[i]+qsL[i-1];
	for(j=1;j<=n2;j++)R[j]=a[m+j],qsR[j]+=R[j]+qsR[j-1];
	i=1,j=1,k=l;
	while(i<=n1&&j<=n2)
	{
		if(L[i]<=R[j])
		{
			a[k++]=L[i++];
		}
		else
		{
			pr+=qsL[n1]-qsL[i-1]+(R[j]*(n1-i+1));
			a[k++]=R[j++];
		}
	}
	while(i<=n1)a[k++]=L[i++];
	while(j<=n2)a[k++]=R[j++];
}
void mergesort(int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2 ;
		mergesort(l,m);
		mergesort(m+1,r);
		printf("a %d %d %d\n",l,m,r);
		merge(l,m,r);
	}
}
main()
{
	int n,x,y,i,j ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		a[y]=x;
	}
	mergesort(1,n);
	printf("%lld",pr);
}
