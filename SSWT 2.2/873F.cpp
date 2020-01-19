#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 2e5+9 , inf = 1e9 ;
pii st[N<<2];
int n,qs[N],L[N],R[N],pos[N],tmp[N],sa[N],lcp[N],gap,t[N];
char s[N];
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
        int j=sa[pos[i]+1];
        while(s[i+k]==s[j+k])k++;
        lcp[pos[i]]=k;
        if(k)k--;
    }
}
pii operate(pii a,pii b)
{
    return {min(a.fi,b.fi),max(a.se,b.se)};
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
    L[x]=getans(0,n,0,lcp[x]-1,1).se+1;
    update(0,n,lcp[x],{inf,x},1);
}
void getr(int x)
{
    R[x]=getans(0,n,0,lcp[x]-1,1).fi-1;
    update(0,n,lcp[x],{x,-inf},1);
}
ll query(int x)
{
    int len = R[x]-L[x]+2;
    return 1ll*lcp[x]*(len-qs[R[x]+1]+qs[L[x]-1]);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=n;i>=1;i--)cin >> s[i];
    for(int i=n;i>=1;i--)
    {
        char c ;
        cin >> c ;
        t[i]=c-'0';
    }
    for(int i=1;i<=n;i++)qs[i]+=qs[i-1];
    constructsa();
    constructlcp();
    for(int i=1;i<=n;i++)qs[i]=qs[i-1]+t[sa[i]];
    for(int i=0;i<N*4;i++)st[i]={inf,-inf};
    update(0,n,0,{inf,0},1);
    for(int i=1;i<=n;i++)getl(i);
    for(int i=n;i>=1;i--)getr(i);
    ll ans = 0 ;
    for(int i=1;i<=n;i++)
    {
        if(lcp[i])ans=max(ans,query(i));
        ans=max(ans,1ll*(n-sa[i]+1)*((qs[i]-qs[i-1])^1));
    }
    cout << ans ;
    return 0 ;
}
