#include<bits/stdc++.h>
using namespace std ;
string s,q;
main() 
{
	int n,k,i;
	scanf("%d %d",&n,&k);
	cin >> s;
	q=s;
	sort(q.begin(),q.end());
	//cout << q <<endl;
	if(k>n)
	{
		cout << s;
		for(n;n<k;n++)printf("%c",q[0]);
		return 0;
	}
	else 
	{
		int j;
		for(i=k-1;i>=0;i--)
		{
			if(q[n-1]>s[i])
			{
				for(j=n-1;q[j]>s[i];j--);
				s[i]=q[j+1];
				for(j=0;j<=i;j++)printf("%c",s[j]);
				for(j;j<k;j++)printf("%c",q[0]);
				return 0;
			}
		}
	}
}
