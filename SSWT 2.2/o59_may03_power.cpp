#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 8e4+9 ,mx = 1e6+9 , sq = sqrt(N)+1;
int cnt[mx],a[N],md,ans[N];
vector<int> cst[mx] ;
vector<pair<pii,int> > query;///l,r,pos
void pre()
{
    for(int i=1;i<mx;i++)
    {
        if(!cnt[i])continue ;
        cst[i].push_back(0);
        for(int j=1,p=1;j<=cnt[i];j++)
        {
            cst[i].push_back((1ll*cst[i].back()+p)*i%md);
            p=1ll*p*i%md ;
        }
    }
}
bool cmp(pair<pii,int> a,pair<pii,int> b)
{
    if(a.fi.fi/sq!=b.fi.fi/sq)return a.fi.fi/sq<b.fi.fi/sq ;
    return a.fi.se<b.fi.se ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,l,r ;
    cin >> n >> m >> md ;
    ///int root = sqrt(n);
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        cnt[a[i]]++ ;
    }
    pre();
    memset(cnt,0,sizeof cnt) ;
    for(i=1;i<=m;i++)
    {
       cin >> l >> r ;
       query.push_back({{l,r},i});
    }
    sort(query.begin(),query.end(),cmp);
    int cur=0;
    l=1,r=1 ; ///[l,r);
    for(auto it:query)
    {
        ///(l,r,pos);
        while(l<it.fi.fi)
        {
            int clr=a[l];
            cur=(cur-cst[clr][cnt[clr]]+cst[clr][cnt[clr]-1]+md)%md;
            cnt[clr]--;
            l++;
        }
        while(it.fi.fi<l)
        {
            l-- ;
            int clr=a[l];
            cur=(cur-cst[clr][cnt[clr]]+cst[clr][cnt[clr]+1]+md)%md;
            cnt[clr]++;
        }
        while(r<=it.fi.se)
        {
            int clr=a[r];
            cur=(cur-cst[clr][cnt[clr]]+cst[clr][cnt[clr]+1]+md)%md;
            cnt[clr]++;
            r++;
        }
        while(it.fi.se+1<r)
        {
            r--;
            int clr=a[r];
            cur=(cur-cst[clr][cnt[clr]]+cst[clr][cnt[clr]-1]+md)%md;
            cnt[clr]--;
        }
        ans[it.se]=cur ;
    }
    for(i=1;i<=m;i++)cout << ans[i] << '\n' ;

}
