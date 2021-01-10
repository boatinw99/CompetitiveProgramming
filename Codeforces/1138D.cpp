#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5+9 ;
string s,t ;
int a[2];
int pat[N];
void clearq()
{
    for(;a[0];a[0]--)cout << "0";
    for(;a[1];a[1]--)cout << "1";
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,i,j,ans=0,w0=0,w1=0 ;
    cin >> s ;
    cin >> t ;
    n=s.size();
    m=t.size();
    for(i=0;i<n;i++)a[s[i]-'0']++;
    for(i=0;i<m;i++)
    {
        if(t[i]=='0')w0++;
        else w1++;
    }
    for(i=1,j=0;i<m;)
	{
		if(t[i]==t[j])
		{
			pat[i]=j+1;
			i++;j++;
		}
		else
		{
			if(j>0)j=pat[j-1];
			else i++;
		}
	}
	if(a[0]<w0||a[1]<w1)
    {
        cout << s;
        return 0 ;
    }
    cout << t ;
    a[0]-=w0,a[1]-=w1;
    for(j=pat[m-1];;)
	{
        if(a[t[j]-'0']<=0)
        {
            clearq();
            return 0 ;
        }
        cout << t[j];
        a[t[j]-'0']--;
        j++;
        if(j==m)j=pat[m-1];
	}
}
