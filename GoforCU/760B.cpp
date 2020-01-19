#include<bits/stdc++.h>
using namespace std;
int n,m,k;
main()
{
	scanf("%d %d %d",&n,&m,&k);
	if(k==1||k==n)
		return 0*printf("%d",((m-n)/2+(m-n)%2)+1);
}
