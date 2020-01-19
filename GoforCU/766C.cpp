#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
int n;
int dy[1009];
int sub[1009];
int a[26];
string s;
main()
{
	int i,k,j,max1=0,d;
	scanf("%d",&n);
	cin >> s;
	for(i=1;i<1009;i++)sub[i]=1e5;
	for(i=0;i<26;i++)scanf("%d",&a[i]);
	dy[0]=1;
	for(i=0;i<n;i++)
	{
		k=a[s[i]-'a'];
		for(j=1;j<=k&&i+j-1<n;j++)
		{
			k=min(k,a[s[i+j-1]-'a']);
			if(j>k)break;	
		}j--;max1=max(max1,j);
		for(d=i+j-1;d>=i;d--)sub[d+1]=min(sub[d+1],sub[i]+1);
		for(d=i+j-1;d>=i;d--)dy[d+1]=(dy[d+1]+dy[i])%N;
	}
	printf("%d\n",dy[n]);
	printf("%d\n",max1);
	printf("%d",sub[n]);
}
