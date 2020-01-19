#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
string s ;
char ans[N];
int n ;
bool chk(int len)
{
    for(int i=0;i<len;i++)ans[i]=s[i];
    for(int j=len;j<n;j++)
    {
        if(ans[j-len]=='?')
        {
            ans[j]=s[j];
            continue ;
        }
        else if(s[j]!='?'&&s[j]!=ans[j-len])return 0 ;
        ans[j]=ans[j-len];
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> s ;
    n = s.size();
    int i ;
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            if(chk(i))break;
        }
    }
    for(int j=0;j<n;j++)if(ans[j]!='?')ans[j%i]=ans[j];
    for(int j=0;j<n;j++)ans[j]=ans[j%i];
    for(int i=0;i<n;i++)
    {
        cout << (ans[i]!='?'?ans[i]:'0') ;
    }
    return 0 ;
}
