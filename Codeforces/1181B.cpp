#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second 
const double pi = 3.141592653589 ; 
const ll INF = 1e18 ; 
const int N = 1e5+9 , mod = 1e9+7 , inf = 1e9 ;
string pluss(string a,string b)
{
    if(a.size()<b.size())swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int n = a.size(),m=b.size(),ex=0;
    string ret = a ; 
    for(int i=0;i<m;i++)
    {
        int u = a[i]-'0' , v = b[i]-'0' ;
        int tmp = u+v+ex ;
        if(tmp>=10)tmp-=10,ex=1;
        else ex=0;
        ret[i]=tmp+'0';
    }
    for(int i=m;i<n;i++)
    {
        int tmp = a[i]-'0'+ex ;
        if(tmp>=10)tmp-=10,ex=1;
        else ex=0;
        ret[i]=tmp+'0' ;
    }
    reverse(ret.begin(),ret.end());
    return ret ;
}
string cmp(string a,string b)
{
    if(a.size()<b.size())return a ;
    if(b.size()<a.size())return b ;
    return (a<b?a:b) ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    string s,x,y,ans; 
    cin >> n ;
    cin >> s ;
    ans=s;
    for(int i=n/2-1;i>=0;i--)
    { 
        if(s[i+1]!='0')
        {
            ans = pluss(s.substr(0,i+1),s.substr(i+1,n-i-1));
            break;
        }
    }
    for(int i=n/2;i<n-1;i++)
    {
        if(s[i+1]!='0')
        {
            ans = cmp(ans,pluss(s.substr(0,i+1),s.substr(i+1,n-i-1)));
            break; 
        }
    }
    cout << ans << '\n' ;
    return 0 ;
}