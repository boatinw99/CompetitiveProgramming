#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
#define mid (l+r>>1)
const int N = 2e5+9 ;
vector<int> v[N];
int a[N],cnt[N];
pii st[N*4]; ///sum,num
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]={0,0};
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]={0,0};
}
void update(int l,int r,int x,int y,int cst,int m)
{
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m].se+=cst ;
        if(st[m].se)st[m].fi=(r-l+1);
        else st[m].fi=st[m<<1].fi+st[m<<1|1].fi;
        return ;
    }
    update(l,mid,x,y,cst,m<<1);
    update(mid+1,r,x,y,cst,m<<1|1);
    if(st[m].se)st[m].fi=(r-l+1);
    else st[m].fi=st[m<<1].fi+st[m<<1|1].fi;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j ;
    long long ans= 0 ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> a[i] ;
    for(i=0;i<N;i++)v[i].emplace_back(0);
    for(i=1;i<=n;i++)
    {
        cnt[a[i]]++;
        v[a[i]].emplace_back(i);
        if(cnt[a[i]]==5)
        {
            update(1,n,1,v[a[i]][1],1,1);
        }
        else if(cnt[a[i]]>5)
        {
            cnt[a[i]]--;
            int sz=v[a[i]].size();
            update(1,n,v[a[i]][sz-7]+1,v[a[i]][sz-6],-1,1);
            update(1,n,v[a[i]][sz-6]+1,v[a[i]][sz-5],1,1);
        }
        ans+=st[1].fi;
    }
    cout << ans ;
}
