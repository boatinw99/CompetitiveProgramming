#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 1e5+9 ,inf = 2e9 ;
set<int> s ;
int st[N<<2],n,m,pos[N],lcp[N],tmp[N],sa[N],gap;
char a[N];
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=lcp[l];
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
}
int findmin(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return inf ;
    if(l>=x&&r<=y)return st[m];
    return min(findmin(l,mid,x,y,m<<1),findmin(mid+1,r,x,y,m<<1|1));
}
bool cmp(int i,int j)
{
    if(pos[i]!=pos[j])return pos[i]<pos[j];
    i+=gap,j+=gap ;
    return (i<=n&&j<=n?pos[i]<pos[j]:i>j);
}
void constructSA()
{
    for(int i=1;i<=n;i++)sa[i]=i,pos[i]=a[i];
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
        while(a[i+k]==a[j+k])k++;
        lcp[pos[i]]=k;
        if(k)k--;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=n;i++)cin >> a[i] ;
    constructSA();
    constructlcp();
    construct(1,n,1);
    s.emplace(pos[1]);
    while(m--)
    {
        int typ,x ;
        cin >> typ >> x ;
        if(typ==1)s.insert(pos[x]);
        else
        {
            auto it = s.lower_bound(pos[x]);
            if(*it==pos[x])
            {
                cout << n-x+1 << '\n' ;
                continue ;
            }
            int ans = 0 ;
            if(it!=s.end())ans=findmin(1,n,pos[x],*it-1,1);
            if(it!=s.begin())ans=max(ans,findmin(1,n,*prev(it),pos[x]-1,1));
            cout << ans << '\n' ;
        }
    }
    return 0 ;
}
