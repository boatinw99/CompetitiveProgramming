#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 1e5+9 , inf = 2e9 , mod = 1e9+7 , LOG = log2(N)+1;
int n,sz;
pair<pii,pii> s[N];
vector<int> cc ;
vector<int> F ;  
int idx=1;
int L[N*LOG*8],R[N*LOG*8];
pii st[N*LOG*8];
int root[N];
int getidx(int val)
{
    return lower_bound(cc.begin(),cc.end(),val)-cc.begin()+1;
}
void init()
{
    memset(L,0,sizeof L);
    memset(R,0,sizeof R);
    memset(st,0,sizeof st); /// 
    F.clear();
    idx=1;
    memset(root,0,sizeof root);
}
pii operate(pii a,pii b)
{
    return {a.fi+b.fi,a.se+b.se};
}
void construct(int m=1,int l=1,int r=sz)
{
    if(l==r)return ; 
    L[m]=++idx;
    R[m]=++idx;
    construct(L[m],l,mid);
    construct(R[m],mid+1,r);
}
int update(int m,int x,int val,int l=1,int r=sz)
{
    if(r<x||l>x)return m ;
    int tmp = ++idx ; 
    if(l==r)
    {
        st[tmp]=st[m];
        if(val==1)st[tmp].fi++;
        else st[tmp].se++;
        return tmp ; 
    }
    L[tmp]=update(L[m],x,val,l,mid);
    R[tmp]=update(R[m],x,val,mid+1,r);
    st[tmp]=operate(st[L[tmp]],st[R[tmp]]);
    return tmp ; 
}
pii getsum(int m,int x,int y,int l=1,int r=sz)
{
    if(r<x||l>y)return {0,0};
    if(l>=x&&r<=y)return st[m];
    return operate(getsum(L[m],x,y,l,mid),getsum(R[m],x,y,mid+1,r));
}
int solve()
{
    init();
    sort(s+1,s+1+n);
    sz=cc.size();
    for(int i=1;i<=n;i++)
    {
        F.push_back(s[i].fi.fi);
        //printf("check s[i] = %d %d %d %d \n",s[i].fi.fi,s[i].fi.se,s[i].se.fi,s[i].se.se);
    }
    root[n+1]=1;
    construct();
    for(int i=n;i>=1;i--)
    {
        int x = getidx(s[i].se.fi),y=getidx(s[i].se.se);
        root[i]=update(root[i+1],x,1);
        root[i]=update(root[i],y,-1);
    }
    for(int i=1;i<=n;i++)
    {
        int l = s[i].fi.se ; 
        int st = upper_bound(F.begin(),F.end(),l)-F.begin()+1;
        if(st>n)continue ;
        //root[st]
        int x = getidx(s[i].se.fi),y=getidx(s[i].se.se);
        pii sum1 = getsum(root[st],1,x-1);
        pii sum2 = getsum(root[st],x,y);
        if((sum1.fi-sum1.se>0)||sum2.fi>0||sum2.se>0)return 0 ;
        //printf("plss st= %d sum = %d \n",st,sum);
    }
    return 1 ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i].fi.fi >> s[i].fi.se >> s[i].se.fi >> s[i].se.se ; 
        cc.push_back(s[i].fi.fi);
        cc.push_back(s[i].fi.se);
        cc.push_back(s[i].se.fi);
        cc.push_back(s[i].se.se);
    }
    cc.push_back(-1);
    cc.push_back(inf);
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    int ret1 = solve();
    for(int i=1;i<=n;i++)
    {
        pii a=s[i].fi,b=s[i].se;
        s[i]={b,a};
    }
    int ret2 = solve();
    int all = min(ret1,ret2);
    cout << (all==0?"NO":"YES") << '\n' ;
    return 0 ;
}