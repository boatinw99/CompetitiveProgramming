#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 1e5+9 , md = 1e4+7 , mx = 1e7+7 ,sq=sqrt(N)+1;
int a[N],ans[N];
map<int,int> mp ;
vector<pii> f[N];
vector<pair<pii,int> > query[sq];
void factor(int i,int val)
{
    for(int j=2;j*j<mx;j++)
    {
        int cnt=0;
        while(val%j==0)
        {
            val/=j;
            cnt++;
        }
        if(cnt)f[i].emplace_back(j,cnt);
    }
    if(val>1)f[i].emplace_back(val,1);
}
bool cmp(pair<pii,int> lhs,pair<pii,int> rhs)
{
    return lhs.fi.se<rhs.fi.se ;
}
int pow2(int a,int p)
{
    if(p==0)return 1 ;
    if(p==1)return a ;
    int tmp=pow2(a,p>>1);
    tmp=tmp*tmp%md ;
    if(p&1)tmp=tmp*a%md ;
    return tmp ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,u,v,x,pos=1 ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        factor(i,x);
    }
    for(i=1;i<=m;i++)
    {
        cin >> u >> v ;
        //u--; v-- ;
        query[u/sq].push_back({{u,v},i});
    }
    for(i=0;i<sq;i++)
    {
        if(query[i].empty())continue ;
        pos=1;
        sort(query[i].begin(),query[i].end(),cmp);
        int l=query[i].begin()->fi.fi;
        int r=query[i].begin()->fi.fi;
        for(auto it:query[i])
        {
            while(r<=it.fi.se)
            {
                for(auto d:f[r])
                {
                    pos=pos*pow2(mp[d.fi]+1,md-2)%md;
                    mp[d.fi]+=d.se;
                    pos=pos*(mp[d.fi]+1)%md;
                }
                r++;
            }
            while(l<it.fi.fi)
            {
                for(auto d:f[l])
                {
                    pos=pos*pow2(mp[d.fi]+1,md-2)%md;
                    mp[d.fi]-=d.se;
                    pos=pos*(mp[d.fi]+1)%md;
                }
                l++;
            }
            while(l>it.fi.fi)
            {
                l--;
                for(auto d:f[l])
                {
                    pos=pos*pow2(mp[d.fi]+1,md-2)%md;
                    mp[d.fi]+=d.se;
                    pos=pos*(mp[d.fi]+1)%md;
                }
            }
            ans[it.se]=pos;
        }
        mp.clear();
    }
    for(i=1;i<=m;i++)cout << ans[i] << '\n' ;
}
