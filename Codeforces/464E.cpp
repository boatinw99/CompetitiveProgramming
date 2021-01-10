#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
typedef long long ll;
#define mid (l+r>>1)
#define fi first
#define se second
const ll pb = 98765431 ;
const int N = 1e5+9 , LOG=log2(N)+1 , mx = 2e5+9 ,md=1e9+7 ;
vector<pii> g[N];
vector<int> path ;
int n,root[N],L[N*LOG*30],R[N*LOG*30],town[N],id=1;
int now ;
ll pi[mx],qs[mx],pow2[mx],ans=0;
ll st[N*LOG*6];
bool vst[N];
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int find1(int l,int r,int x,int m)
{
    if(r<x||l>x)return 0;
    if(l==r)return st[m];
    return find1(l,mid,x,L[m])+find1(mid+1,r,x,R[m]);
}
int update(int l,int r,int x,int m)
{
    if(r<x||l>x)return m;
    int tmp=++id;
    if(l==r)
    {
        st[tmp]=st[m]^1;
        return tmp ;
    }
    L[tmp]=update(l,mid,x,L[m]);
    R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]]*pi[mid-l+1];
    return tmp ;
}
bool cmp(int l,int r,int m1,int m2) ///m1<m2
{
    if(l==r)return st[m1]<st[m2];
    if(st[R[m1]]!=st[R[m2]])return cmp(mid+1,r,R[m1],R[m2]);
    else return cmp(l,mid,L[m1],L[m2]);
}
struct qu
{
    int num ;
    bool operator<(const qu &tmp)const
    {
        ///if(num<tmp.num)return 1
        return !cmp(0,mx,root[num],root[tmp.num]);
    }
};
void preprocess()
{
    pi[0]=qs[0]=1,pow2[0]=1;
    for(int i=1;i<mx;i++)
    {
        pi[i]=pi[i-1]*pb;
        qs[i]=qs[i-1]+pi[i];
        pow2[i]=(pow2[i-1]*2)%md;
    }
}
void result(int l,int r,int m)
{
    if(l==r)
    {
        ans=(ans+1ll*(pow2[l])*st[m])%md;
        return ;
    }
    result(l,mid,L[m]);
    result(mid+1,r,R[m]);
}
void backtrack(int i,int s)
{
    if(i!=s)backtrack(town[i],s);
    path.push_back(i);
}
priority_queue<qu> pq ;
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int u,v,i,j,x,s,t,m ;
    cin >> n >> m ;
    preprocess();
    while(m--)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    cin >> s >> t ;
    root[s]=1;
    construct(0,mx,1);
    for(pq.push({s});!pq.empty();)
    {
        x = pq.top().num ;
        pq.pop();
        if(vst[x]==1)continue ;
        vst[x]++;
        if(x==t)
        {
            result(0,mx,root[x]);
            cout << ans << '\n' ;
            backtrack(t,s);
            cout << path.size() << '\n' ;
            for(auto it:path)cout << it << " " ;
            return 0 ;
        }
        for(auto it:g[x])
        {
            if(vst[it.fi]==0)
            {
                int bits=it.se;
                now=root[x];
                while(find1(0,mx,bits,now))
                {
                    now=update(0,mx,bits,now);
                    bits++;
                }
                now=update(0,mx,bits,now);
                ///printf("aaa %d %d\n",it.fi,bits);
                if(root[it.fi]==0)
                {
                    town[it.fi]=x;
                    root[it.fi]=now;
                    pq.push({it.fi});
                }
                else if(cmp(0,mx,now,root[it.fi]))
                {
                    town[it.fi]=x;
                    root[it.fi]=now;
                    pq.push({it.fi});
                }
            }
        }
    }
    cout << "-1" ;
}
