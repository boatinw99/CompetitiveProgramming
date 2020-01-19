#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
typedef long long ll ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 2e5+9 ,inf =1e9+7 ;
string s ;
pii st[N<<2];
int n,gap,lcp[N],sa[N],tmp[N],pos[N],L[N],R[N];
ll ans[N];
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
        while(s[j+k]==s[i+k]&&i+k<=n&&j+k<=n)k++;
        lcp[pos[i]]=k;
        if(k)k--;
    }
}
pii operate(pii a,pii b)///min,max
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
void updatemx(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m].se=cst;
        return ;
    }
    updatemx(l,mid,x,cst,m<<1);
    updatemx(mid+1,r,x,cst,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void updatemn(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m].fi=cst;
        return ;
    }
    updatemn(l,mid,x,cst,m<<1);
    updatemn(mid+1,r,x,cst,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
pii getans(int l,int r,int x,int y,int m)
{
    if(r<x||l>y||x>y)return {inf,-inf} ;
    if(l>=x&&r<=y)return st[m];
    return operate(getans(l,mid,x,y,m<<1),getans(mid+1,r,x,y,m<<1|1));
}
void getl(int x)
{
    L[x]=getans(0,n,0,lcp[x],1).se+1;
    updatemx(0,n,lcp[x],x,1);
}
void getr(int x)
{
    R[x]=getans(0,n,0,lcp[x]-1,1).fi-1;
    updatemn(0,n,lcp[x],x,1);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ;
    cin >> T ;
    while(T--)
    {
        cin >> s ;
        n=s.size();
        s="#"+s ;
        constructsa();
        constructlcp();
        construct(0,n,1);
        updatemx(0,n,0,0,1);
        for(int i=1;i<=n;i++)getl(i);
        for(int i=n;i>=1;i--)getr(i);
        for(int i=1;i<=n;i++)
        {
            if(lcp[i])
            {
                ans[R[i]-L[i]+2]+=1ll*(lcp[i]-max(lcp[L[i]-1],lcp[R[i]+1]))
                    *(R[i]-L[i]+2);
            }
        }
        for(int i=n;i>=2;i--)ans[i]+=ans[i+1];
        ans[1]=1ll*n*(n+1)/2 ;
        int m ;
        cin >> m ;
        while(m--)
        {
            int x ;
            cin >> x ;
            cout << ans[x] << '\n' ;
        }
        for(int i=1;i<=n;i++)ans[i]=0;
    }
    return 0 ;
}
