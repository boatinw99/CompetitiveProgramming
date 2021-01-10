#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<ll,int> pli ; 
typedef pair<int,ll> pil ; 
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 509 , mod = 1e9+7, inf = 1e9 ; 
int n,mn[N],val[N],arr[N];
string s ;
int compute()
{
    int ans = 0 ;
    for(int i=1;i<=n;i++)
    {
        val[i]=val[i-1]+arr[i];
        mn[i]=min(mn[i-1],val[i]);
    }
    int cst = 0 , mn2 = 0 ;
    for(int i=n;i>=1;i--)
    {
        cst+=arr[i];
        mn2=min(mn2,mn[i]);
        if(mn[i-1]+cst==0&&mn2-val[i-1]>=0)
        {
            ans++;
        }
    } 
    return ans ;   
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    cin >> s ;
    s='-'+s; 
    pair<int,pii> ans = {0,{1,1}};
    int cnt = 0 ;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(')cnt++,arr[i]=1;
        else cnt--,arr[i]=-1;
    }
    if(cnt!=0)
    {
        cout << "0 \n1 1" << '\n' ;
        return 0 ;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            swap(arr[i],arr[j]);
            ans=max(ans,{compute(),{i,j}});
            swap(arr[i],arr[j]);
        }
    }
    cout << ans.fi << '\n' ;
    cout << ans.se.fi << " " << ans.se.se << '\n' ;
    return 0 ;
}