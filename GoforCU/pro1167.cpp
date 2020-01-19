#include<bits/stdc++.h>
using namespace std;
string s;
main()
{
	int N=0,S=0,E=0,W=0;
	int a,i;
	cin >> s;
	scanf("%d",&a);
	for(i=0;i<s.size();i++)
	{
		N+=(s[i]=='N');
		S+=(s[i]=='S');
		W+=(s[i]=='W');
		E+=(s[i]=='E');
	}
	if(N<S)swap(N,S);
	if(S<=a)a-=S,S=0;
	else S-=a,a=0;
	if(W<E)swap(W,E);
	if(E<=a)a-=E,E=0;
	else E-=a,a=0;
	printf("%d",(N+W-a-S-E)*2);
	
}
