#include<bits/stdc++.h>
using namespace std;
int b[100000][2];
main()
{
	int a,i;
	string s;
	scanf("%d",&a);
	int N=0,M=a+1;
	cin >> s;
	b[0][s[0]-48]++;
	for(i=1;i<a;i++)
	{
		b[i][s[i]-48]++;	
		b[i][0]+=b[i-1][0];
		b[i][1]+=b[i-1][1];
	}
	int Q;
	bool k=0;
	while(N+1<M)
	{
		k=0;
		Q=(N+M)/2;
		if(b[Q-1][0]==b[Q-1][1])k=1;
		for(i=Q;i<a;i++)
		{
			if(b[i][0]-b[i-Q][0]==b[i][1]-b[i-Q][1])
			{
				k=1;
				break;
			}
		}
		if(k==1)N=Q;
		else M=Q;
		printf("%d %d\n",N,M);
	}
	printf("%d",N);
}

