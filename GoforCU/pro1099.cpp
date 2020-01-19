#include<bits/stdc++.h>
using namespace std ;
stack<int> st;
main()
{
	int a,b,gc,i ;
	scanf("%d %d",&a,&b);
	gc=__gcd(a,b);
	for(i=1;i*i<gc;i++)
	{
		if(gc%i==0)
		{
			printf("%d %d %d\n",i,a/i,b/i);	
			st.push(gc/i);		
		}
	}
	if(i*i==gc)printf("%d %d %d\n",i,a/i,b/i);
	while(!st.empty())
	{
		printf("%d %d %d\n",st.top(),a/st.top(),b/st.top());
		st.pop();
	}
}
