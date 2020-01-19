#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll pb = 98765431 ;
const int N = 1e5+9,LOG=log2(N)+1;
int a[N],b[N],cnt[N],n,id=1;
ll qs[N],qs2[N];
struct T
{
    ll sum,add ;
    int num ;
};
T st[N*LOG*8];
int L[N*LOG*8],R[N*LOG*8],root1[N],root2[N],root3[N],root4[N];
ll hashl[N],hashr[N],p[N];
char c[N];
bool chk(int x,int y)
{
    return p[x-1]*(hashl[x]-hashl[y+1])==p[n-y]*(hashr[y]-hashr[x-1]);
}
int lpdm1(int x)///longest palindrome odd length
{
    int l=0,r=n ;
    while(l+1<r)
    {
        if(x-mid<=0||x+mid>n)
        {
            r=mid ;
            continue ;
        }
        if(chk(x-mid,x+mid))l=mid;
        else r=mid;
    }
    return l ;
}
int lpdm2(int x)/// longest palindrome even length
{
    int l=-1,r=n;
    while(l+1<r)
    {
        if(x-mid<=0||x+mid+1>n)
        {
            r=mid;
            continue ;
        }
        if(chk(x-mid,x+mid+1))l=mid;
        else r=mid;
    }
    return l ;
}
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id ;
    construct(l,mid,L[m]);
    construct(mid+1,r,R[m]);
}
T operate(T t1,T t2)
{
    return {t1.sum+t2.sum,t1.add+t2.add,t1.num+t2.num};
}
int update(int l,int r,int x,T now,int m)
{
    if(r<x||l>x)return m ;
    int tmp = ++id ;
    if(l==r)
    {
        st[tmp]=operate(st[m],now); ///sum num
        return tmp ;
    }
    L[tmp]=update(l,mid,x,now,L[m]);
    R[tmp]=update(mid+1,r,x,now,R[m]);
    st[tmp]=operate(st[L[tmp]],st[R[tmp]]);
    return tmp ;
}
T getsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y||x>y)return {0,0};
    if(l>=x&&r<=y)return st[m];
    return operate(getsum(l,mid,x,y,L[m]),getsum(mid+1,r,x,y,R[m]));
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,l,r,m ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> c[i];
    for(i=1;i<=n;i++)qs[i]=qs[i-1]+i ;
    p[0]=1;
    for(i=1;i<=n;i++)p[i]=p[i-1]*pb;
    for(i=n;i>=1;i--)hashl[i]=1ll*c[i]*p[n-i]+hashl[i+1]; ///hashl
    for(i=1;i<=n;i++)hashr[i]=1ll*c[i]*p[i-1]+hashr[i-1];///hashr
    for(i=1;i<=n;i++)a[i]=lpdm1(i);
    for(i=1;i<=n;i++)b[i]=lpdm2(i);
    for(i=1;i<=n;i++)
    {
        qs2[i]=qs2[i-1];
        cnt[i]=cnt[i-1];
        if(b[i]>=0)qs2[i]+=i,cnt[i]++;
    }
    ///1
    root1[0]=id;
    construct(1,n,1);
    for(i=1;i<=n;i++)root1[i]=update(1,n,i-a[i],{a[i],i,1},root1[i-1]);
    ///2
    root2[n+1]=++id;
    construct(1,n,root2[n+1]);
    for(i=n;i>=1;i--)root2[i]=update(1,n,i+a[i],{a[i],i,1},root2[i+1]);
    ///3
    root3[0]=++id;
    construct(1,n,root3[0]);
    b[0]=-1 ;
    for(i=1;i<=n;i++)
    {
        root3[i]=root3[i-1];
        if(b[i-1]>=0)root3[i]=update(1,n,i-b[i-1]-1,{b[i-1]+1,i-1,1},root3[i]);
    }
    ///4
    root4[n+1]=++id ;
    construct(1,n,root4[n+1]);
    for(i=n;i>=1;i--)
    {
        root4[i]=root4[i+1];
        if(b[i]>=0)root4[i]=update(1,n,i+b[i]+1,{b[i]+1,i,1},root4[i]);
    }
    cin >> m ;
    while(m--)
    {
        cin >> l >> r;
        ll ans = r-l+1 ;
        ///1
        T tmp = getsum(1,n,l,mid,root1[mid]);
        int range= mid-l+1;
        ll add=tmp.sum-1ll*l*(range-tmp.num)+(qs[mid]-qs[l-1]-tmp.add);
        ans+=add;
        ///2
        range=r-mid;
        tmp =getsum(1,n,mid+1,r,root2[mid+1]);
        add=tmp.sum+1ll*r*(range-tmp.num)-(qs[r]-qs[mid]-tmp.add);
        ans+=add;
        ///3+4
        if(r-l)
        {
            ///3
            tmp = getsum(1,n,l,mid-1,root3[mid]);
            add = tmp.sum-1ll*(l-1)*(cnt[mid-1]-cnt[l-1]-tmp.num)
                +(qs2[mid-1]-qs2[l-1]-tmp.add);
            ans+=add;
            ///4
            tmp = getsum(1,n,mid,r,root4[mid]);
            add=tmp.sum+1ll*r*(cnt[r]-cnt[mid-1]-tmp.num)
                    -(qs2[r]-qs2[mid-1]-tmp.add);
            ans+=add;
        }
        cout << ans << '\n' ;
    }

}
