#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 3e4+9,LOG=log2(N)+1 ;
int st[N*LOG+N*4],L[N*LOG+N*4],R[N*LOG+N*4],root[N];
vector<pii> v ;
map<int,int> mp ;
int a[N],n,id=1;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id;
    int mid=l+r>>1;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int m)
{
    int tmp=++id,mid=l+r>>1;
    if(l==r)
    {
        st[tmp]=st[m]+1;
        return tmp;
    }
    L[tmp]=L[m],R[tmp]=R[m];
    if(x<=mid)L[tmp]=update(l,mid,x,L[m]);
    else R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp ;
}
int findsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    int mid=l+r>>1;
    return findsum(l,mid,x,y,L[m])+findsum(mid+1,r,x,y,R[m]);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,m,x,l,r,ans=0,k ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        v.emplace_back(a[i],i);
    }
    sort(v.begin(),v.end());
    root[0]=1;
    construct(1,n,1);
    i=1;
    for(auto it:v)
    {
        root[i]=update(1,n,it.se,root[i-1]);
        mp[it.fi]=root[i];
        i++;
    }
    cin >> m ;
    while(m--)
    {
        cin >> l >> r >> k ;
        ///while(l>1e9||r>1e9||k>1e9);
        l^=ans,r^=ans,k^=ans;
        ///while(l>1e9||r>1e9||k>1e9);
        auto it=upper_bound(v.begin(),v.end(),make_pair(k,n+1));
        if(it==v.begin())x=1;
        else x=mp[(it-1)->fi];
        //printf("aaaaaaaa %d %d\n",it->fi,x);
        l=max(1,l),r=min(r,n);
        if(l>r)ans=0;
        else ans=(r-l+1)-findsum(1,n,l,r,x);
        cout << ans << '\n';
    }
}
