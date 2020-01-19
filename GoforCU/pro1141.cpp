#include<bits/stdc++.h>
using namespace std ;
set<int> q,e ; //lr , updown
set<int>::iterator it;
main()
{
	int n,m,i,j,d ;
	char c;
	bool kl=0,ku=0;
	int l=INT_MAX,r=0,up=INT_MAX,down=0;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf(" %c %d",&c,&d);
		if((c=='N'||c=='S')&&ku==0)
		{
			kl++;
			l=min(l,d); r=max(r,d);
			if(binary_search(q.begin(),q.end(),d))printf("0\n");
			else printf("%d\n",n);
			q.insert(d);
		}
		else if((c=='W'||c=='E')&&kl==0)
		{
			ku++;
			up=min(up,d); down=max(down,d);
			if(binary_search(e.begin(),e.end(),d))printf("0\n");
			else printf("%d\n",n);
			e.insert(d);
		}
		else if(c=='N')
		{
			l=min(l,d); r=max(r,d);
			if(binary_search(q.begin(),q.end(),d))printf("0\n");
			else printf("%d\n",up-1);
			q.insert(d);
		}
		else if(c=='S')
		{
			l=min(l,d); r=max(r,d);
			if(binary_search(q.begin(),q.end(),d))printf("0\n");
			else printf("%d\n",n-down);
			q.insert(d);
		}		
	}
}
