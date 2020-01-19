#include<bits/stdc++.h>
using namespace std ;
int n,a[100009],pr=0;
void merge(int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1,n2=r-m ;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)L[i]=a[l+i];
	for(j=0;j<n2;j++)R[j]=a[m+1+j];
	i=0 ; j=0 ; k=l ;
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k++]=L[i++];
		}
		else
		{
			printf("a %d %d %d %d\n",L[i],R[j],m,i);
			pr+=n1-i ;
			a[k++]=R[j++];
		}
	}
	while(i<n1)a[k++]=L[i++];
	while(j<n2)a[k++]=R[j++];	
}
void mergesort(int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2 ;
		mergesort(l,m);
		mergesort(m+1,r);
		merge(l,m,r);
	}
}
main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	mergesort(0,n-1);
	for(i=0;i<n;i++)printf("%d ",a[i]);
	printf("\n%d",pr);
}
