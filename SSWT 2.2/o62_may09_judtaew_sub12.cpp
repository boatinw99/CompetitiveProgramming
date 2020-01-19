#include<bits/stdc++.h>
using namespace std ;
const int N = 2509 , mod = 1e9+7 ;
int A[N],p[N],n,k,ans=0 ;
bool chk(vector<int> &a,vector<int> &b,vector<int> &c)
{
    for(int i=1;i<a.size();i++)
    {
        if(abs(a[i]-a[i-1])>k)return 0 ;
    }
    for(int i=1;i<b.size();i++)
    {
        if(abs(b[i]-b[i-1])>k)return 0 ;
    }
    for(int i=1;i<c.size();i++)
    {
        if(abs(c[i]-c[i-1])>k)return 0 ;
    }
    return 1;
}
void solve(int idx,vector<int> a,vector<int> b,vector<int> c)
{
    if(!chk(a,b,c))return ;
    if(idx==n+1)
    {
        ans++;
        return ;
    }
    a.push_back(A[idx]);
    solve(idx+1,a,b,c);
    a.pop_back();
    b.push_back(A[idx]);
    solve(idx+1,a,b,c);
    b.pop_back();
    c.push_back(A[idx]);
    solve(idx+1,a,b,c);
    c.pop_back();
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> k ;
    p[0]=1;
    for(int i=1;i<N;i++)p[i]=1ll*p[i-1]*3%mod;
    for(int i=1;i<=n;i++)cin >> A[i];
    if(n<=10)
    {
        vector<int> a,b,c;
        a.clear();
        b.clear();
        c.clear();
        solve(1,a,b,c);
        cout << ans ;
        return 0 ;
    }
    cout << p[n] ;
    return 0 ;
}
