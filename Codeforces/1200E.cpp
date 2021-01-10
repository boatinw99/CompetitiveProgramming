#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<ll,ll> pll ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll INF = 1e18 , PB = 98765431 ;
const int N = 2e6+9 , M = 1e5+9 , inf = 1e9 , mod = 1e9+7 ;
int n,sz=0; 
bool ch = 0 ;
vector<char> ans ;
ll hashr[N],P[N];
int size[N];
string S[N];
long long gethash(int l,int r)
{
    int len=r-l+1;
    return (hashr[r]-hashr[l-1]*P[len]+1ll*mod*mod)%mod;
}
void precomp()
{
    P[0]=1;
    for(int i=1;i<N;i++)
    {
        P[i]=(P[i-1]*PB)%mod ;
    }
}
void push(int x,int l,int r)
{
    for(int i=l;i<=r;i++)
    {
        sz++;
        hashr[sz]=(hashr[sz-1]*PB+S[x][i])%mod;
        cout << S[x][i] ;
    }
}
void comp(int i)
{   
    int mx = -1 ;
    ll tmp = 0 ;
    for(int j=0;j<size[i+1];j++)
    {
        if(sz-j<1)break;
        tmp = (tmp*PB+S[i+1][j])%mod; 
        if(tmp==gethash(sz-j,sz))
        {
            mx=j;
        }
    }
    push(i+1,mx+1,size[i+1]-1);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    precomp();
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> S[i];
        size[i]=S[i].size();
    }
    push(1,0,size[1]-1);
    for(int i=1;i<n;i++)
    {
        comp(i);
    }
    return 0 ;
}