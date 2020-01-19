#include<bits/stdc++.h>
using namespace std ;
string text;
int n;
int L[309];
int find()
{
	int i,N=2*n+1;
	int C = 1 ,R=2,diff,maxLPS=1,mir;
	bool expand  ;
	for(i=2;i<N;i++)
	{
		diff=R-i;
		expand=0;
		if(diff>0)
		{
			mir=C*2-i;
			if(L[mir]<diff)L[i]=L[mir];
			else if(L[mir]==diff&&i==N-1)L[i]=L[mir];
			else if(L[mir]==diff)L[i]=L[mir],expand++;
			else if(L[mir]>diff)L[i]=diff,expand++;
		}
		else expand++;
		if(expand)
		{
			while((i+L[i]<N&&i-L[i]>0)&&(((i+L[i]+1)%2==0)||
				text[(i+L[i]+1)/2]==text[(i-L[i]-1)/2]))
			{
				L[i]++;
			}
		}
		if(i+L[i]>R)C=i,R=i+L[i];
		maxLPS=max(maxLPS,L[i]);
	}
	return maxLPS ;
}
main()
{
	cin>>text;
	n=text.length();
	printf("%d",find());
}
