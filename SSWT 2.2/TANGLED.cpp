#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mid (l+r>>1)
const int N = 4e5+9 ,inf = 1e9+7 ;
struct node
{
    int sum,mn,mx ;
}st[N<<2];
string a,b,s ;
int n,m,p,gap,pos[N],sa[N],tmp[N],lcp[N],L[N],R[N];
ll ans[N];
node operate(node a,node b)
{
    return {a.sum+b.sum,min(a.mn,b.mn),max(a.mx,b.mx)};
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]={(sa[l]<=n),inf,-inf};
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void updatemn(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m].mn=cst;
        return ;
    }
    updatemn(l,mid,x,cst,m<<1);
    updatemn(mid+1,r,x,cst,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void updatemx(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m].mx=cst;
        return ;
    }
    updatemx(l,mid,x,cst,m<<1);
    updatemx(mid+1,r,x,cst,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
node getans(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {0,inf,-inf};
    if(l>=x&&r<=y)return st[m];
    return operate(getans(l,mid,x,y,m<<1),getans(mid+1,r,x,y,m<<1|1));
}
bool cmp(int i,int j)
{
    if(pos[i]!=pos[j])return pos[i]<pos[j];
    i+=gap,j+=gap;
    return (i<=p&&j<=p?pos[i]<pos[j]:i>j);
}
void constructsa()
{
    for(int i=1;i<=p;i++)sa[i]=i,pos[i]=s[i];
    for(gap=1;gap<=p;gap<<=1)
    {
        sort(sa+1,sa+1+p,cmp);
        for(int i=1;i<=p;i++)tmp[i]=tmp[i-1]+cmp(sa[i-1],sa[i]);
        for(int i=1;i<=p;i++)pos[sa[i]]=tmp[i];
    }
}
void constructlcp()
{
    for(int i=1,k=0;i<=p;i++)if(pos[i]!=p)
    {
        int j = sa[pos[i]+1];
        while(i+k<=p&&j+k<=p&&s[i+k]==s[j+k])k++;
        lcp[pos[i]]=k ;
        if(k)k--;
    }
}
void getl(int x)
{
    L[x] = getans(0,p,0,lcp[x],1).mx+1;
    updatemx(0,p,lcp[x],x,1);
}
void getr(int x)
{
    R[x] = getans(0,p,0,lcp[x]-1,1).mn-1;
    updatemn(0,p,lcp[x],x,1);
}
void query(int x)
{
    node ret = getans(0,p,L[x],R[x]+1,1);
    int len = R[x]-L[x]+2;
    ll add = 1ll*ret.sum*(len-ret.sum);
    ans[lcp[x]]+=add ;
    ans[max(lcp[L[x]-1],lcp[R[x]+1])]-=add;
}
void init()
{
    memset(ans,0,sizeof ans);
    memset(sa,0,sizeof sa);
    memset(lcp,0,sizeof sa);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ;
    cin >> T ;
    while(T--)
    {
        char c = 'z'+1 ;
        int len ;
        cin >> a >> b >> len ;
        init();
        n = a.size() , m = b.size();
        s = "#"+a+c+b+"#";
        p = n+m+1 ;
        constructsa();
        constructlcp();
        construct(0,p,1);
        updatemx(0,p,0,0,1);
        for(int i=1;i<=p;i++)getl(i);
        for(int i=p;i>=1;i--)getr(i);
        for(int i=1;i<=p;i++)if(lcp[i])query(i);
        for(int i=min(n,m);i>=1;i--)ans[i]+=ans[i+1];
        for(int i=1;i<=len;i++)cout << ans[i] << " " ;
        cout << '\n' ;
    }
    return 0 ;
}
