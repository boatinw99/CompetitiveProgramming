#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
typedef long long ll ;
#define fi first
#define se second
#define mid (l+r>>1)
const int N = 2e5+9 ,inf = 1e9+7 ,LOG = log2(N)+1 ;
pii st[N<<2];
int K,n,a[N],gap,pos[N],sa[N],tmp[N],lcp[N],comp[N],Lp[N],Rp[N];///L,R pointer
int stpst[N*LOG*2],L[N*LOG*2],R[N*LOG*2],root[N*LOG*2],preval[N],id=1;
ll ans[N],add[N];
string s,t ;
pii operate(pii a,pii b)///mn mx
{
    return {min(a.fi,b.fi),max(a.se,b.se)};
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]={inf,-inf};
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}

void update(int l,int r,int x,pii y,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=operate(st[m],y);
        return ;
    }
    update(l,mid,x,y,m<<1);
    update(mid+1,r,x,y,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
pii getans(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {inf,-inf};
    if(l>=x&&r<=y)return st[m];
    return operate(getans(l,mid,x,y,m<<1),getans(mid+1,r,x,y,m<<1|1));
}
void getl(int x)
{
    Lp[x]=getans(0,n,0,lcp[x],1).se+1;
    update(0,n,lcp[x],{inf,x},1);
}
void getr(int x)
{
    Rp[x]=getans(0,n,0,lcp[x]-1,1).fi-1;
    update(0,n,lcp[x],{x,-inf},1);
}
bool cmp(int i,int j)
{
    if(pos[i]!=pos[j])return pos[i]<pos[j];
    i+=gap,j+=gap;
    return (i<=n&&j<=n?pos[i]<pos[j]:i>j);
}
void constructsa()
{
    for(int i=1;i<=n;i++)sa[i]=i,pos[i]=s[i];
    for(gap=1;gap<=n;gap<<=1)
    {
        sort(sa+1,sa+1+n,cmp);
        for(int i=1;i<=n;i++)tmp[i]=tmp[i-1]+cmp(sa[i-1],sa[i]);
        for(int i=1;i<=n;i++)pos[sa[i]]=tmp[i];
    }
}
void constructlcp()
{
    for(int i=1,k=0;i<=n;i++)if(pos[i]!=n)
    {
        int j = sa[pos[i]+1];
        while(s[i+k]==s[j+k]&&i+k<=n&&j+k<=n&&s[i+k]!='z'+1)k++;
        lcp[pos[i]]=k;
        if(k)k--;
    }
}

void constructpst(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id ;
    constructpst(l,mid,L[m]);
    constructpst(mid+1,r,R[m]);
}
int updatepst(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return m ;
    int nw = ++id ;
    if(l==r)
    {
        stpst[nw]=stpst[m]+cst;
        return nw ;
    }
    L[nw]=updatepst(l,mid,x,cst,L[m]);
    R[nw]=updatepst(mid+1,r,x,cst,R[m]);
    stpst[nw]=stpst[L[nw]]+stpst[R[nw]];
    return nw ;
}
int getsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return stpst[m];
    return getsum(l,mid,x,y,L[m])+getsum(mid+1,r,x,y,R[m]);
}
void query(int x)
{
    //int len = Rp[x]-Lp[x]+2 ;
    int len = getsum(1,n,Lp[x],Rp[x]+1,root[Rp[x]+1]);
    if(len>=K)
    {
        ll tmp = lcp[x]-max(lcp[Lp[x]-1],lcp[Rp[x]+1]);
        add[Lp[x]]+=tmp;
        add[Rp[x]+2]-=tmp;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int num ;
    cin >> num >> K ;
    char c = 'z'+1 ;
    int ptr = 0 ;
    a[0]=-1;
    for(int i=1;i<=num;i++)
    {
        cin >> t ;
        s+=c+t;
        a[i]=a[i-1]+t.size()+1;
        for(ptr++;ptr<=a[i];ptr++)comp[ptr]=i;
        if(K==1)cout << 1ll*t.size()*(t.size()+1)/2 << " " ;
    }
    if(K==1)return 0 ;
    n = s.size()-1;
    constructsa();
    constructlcp();
    construct(0,n,1);
    root[0]=1;
    constructpst(1,n,1);
    for(int i=1;i<=n;i++)
    {
        root[i]=root[i-1];
        int com = comp[sa[i]];
        if(preval[com])root[i]=updatepst(1,n,preval[com],-1,root[i]);
        preval[com]=i;
        root[i]=updatepst(1,n,preval[com],1,root[i]);
    }
    update(0,n,0,{inf,0},1);
    for(int i=1;i<=n;i++)getl(i);
    //update(0,n,0,{n,-inf},1);
    for(int i=n;i>=1;i--)getr(i);
    for(int i=1;i<=n;i++)if(lcp[i])query(i);
    for(int i=1;i<=n;i++)
    {
        add[i]+=add[i-1];
        if(comp[sa[i]]>=1)ans[comp[sa[i]]]+=add[i];
    }
    for(int i=1;i<=num;i++)cout << ans[i] << " " ;
    return 0 ;
}
