#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second 
const pll pb(29,37) ; 
const ll mod = 1e9+7 ;
const int N = 6e5+9 ; 
string t,s[N] ;
char S[N];
vector<int> V ; 
pll hashh[N];
pll P[N];
int n,m,str[N],pos[N],sa[N],tmp[N],gap;
ll ans[N],ansrev[N];
pll gethash(int l,int r)
{
    return {(hashh[r].fi-(hashh[l-1].fi*P[r-l+1].fi)%mod+mod)%mod,(hashh[r].se-(hashh[l-1].se*P[r-l+1].se)%mod+mod)%mod};
}
bool cmp(int i,int j)
{
    if(pos[i]!=pos[j])return pos[i]<pos[j];
    i+=gap;
    j+=gap;
    return (i<=n&&j<=n?pos[i]<pos[j]:i>j);
}
void constructSA()
{
    for(int i=1;i<=n;i++)
    {
        sa[i]=i ;
        pos[i]=S[i];
    }
    for(gap=1;gap<=n;gap<<=1)
    {
        sort(sa+1,sa+1+n,cmp);
        for(int i=1;i<=n;i++)tmp[i]=tmp[i-1]+cmp(sa[i-1],sa[i]);
        for(int i=1;i<=n;i++)pos[sa[i]]=tmp[i];
    }
}
bool check_pop(int x,int j)
{
    int len = s[str[x]].size();
    if(j+len-1>n)return 1 ;
    pll h1 = gethash(x,x+len-1),h2 = gethash(j,j+len-1);
    return h1.fi!=h2.fi || h1.se!=h2.se; 
}
void re()
{
    V.clear();
    for(int i=1;i<=n;i++)
    {
        str[i]=0;
    }
}
void comp()
{
    constructSA();
    for(int i=1;i<=n;i++)
    {
        hashh[i].fi=(hashh[i-1].fi*pb.fi+S[i])%mod;
        hashh[i].se=(hashh[i-1].se*pb.se+S[i])%mod;
    }
    for(int i=1;i<=n;i++)///in sa[i]
    {
        while(!V.empty()&&check_pop(V.back(),sa[i]))
        {
            V.pop_back();
        }
        if(sa[i]<=t.size())
        {
            ans[sa[i]]=V.size();
        }
        if(str[sa[i]]>0)
        {
            V.push_back(sa[i]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int idx = 0 ;
    cin >> t ;  
    cin >> m ;
    S[0]='#' ;
    int sh = t.size();
    for(int j=0;j<sh;j++)
    {
        S[++idx]=t[j];
    }
    S[++idx]='z'+1 ; 
    P[0]={1,1};
    for(int i=1;i<N;i++)P[i]={P[i-1].fi*pb.fi%mod,P[i-1].se*pb.se%mod};
    for(int i=1;i<=m;i++)
    {
        S[++idx]='#';
        str[idx+1]=i;
        cin >> s[i] ; 
        int pp = s[i].size();
        for(int j=0;j<pp;j++)S[++idx]=s[i][j] ;
    }
    n = idx ;
    idx = 0 ;
    comp();
    for(int i=1;i<=n;i++)ansrev[i]=ans[i];
    re();
    reverse(t.begin(),t.end());
    for(int i=1;i<=m;i++)reverse(s[i].begin(),s[i].end());
    for(int j=0;j<int(t.size());j++)
    {
        S[++idx]=t[j];
    }
    S[++idx]='z'+1 ; 
    for(int i=1;i<=m;i++)
    {
        S[++idx]+='#';
        str[idx+1]=i;
        int pp = s[i].size();
        for(int j=0;j<pp;j++)S[++idx]=s[i][j] ;
    }
    comp();
    int len = t.size();
    ll pr = 0 ;
    for(int i=1;i<=len;i++)
    {
        pr+=ansrev[i]*ans[len-i+2];
    }
    cout << pr << '\n' ;
    return 0 ;
}