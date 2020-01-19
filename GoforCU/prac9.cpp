#include<bits/stdc++.h>
using namespace std ;
int n ;
string s;
int L[309];
int find()
{
	int N=2*n+1,i;
	int R=2,C=1,diff,maxLPS=1,mir ;
	bool expand ;
	for(i=2;i<N;i++)
	{
		diff=R-i;
		expand=0;
		if(diff>0)
		{
			mir=2*C-i;
			if(L[mir]<diff)L[i]=L[mir];
			else if(L[mir]==diff&&i==N-1)L[i]=L[mir];
			else if(L[mir]==diff)L[i]=L[mir],expand++;
			else if(L[mir]>diff)L[i]=diff,expand;
		}
		else expand++;
		if(expand)
		{
			while((i+L[i]<N&&i-L[i]>0)&&(((i+L[i]+1)%2==0)||
				s[(i+L[i]+1)/2]==s[(i-L[i]-1)/2]))
			{
				L[i]++;
			}
		}
		if(i+L[i]>R)C=i,R=i+L[i];
		maxLPS=max(maxLPS,L[i]);
	}
	return maxLPS;
}
main()
{
	scanf("%d",&n);
	cin>> s;
	printf("%d",find());
}
