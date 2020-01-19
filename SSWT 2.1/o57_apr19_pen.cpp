#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 1e5+9 ;
struct P
{
    int x1,x2,y,idx ;
}line[N];
vector<int> cc ;
map<int,int> mp ;
set<int> st[N<<2];
int dp[N];
void update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return ;
    st[m].insert(cst);
    if(l==r)return ;
    update(l,mid,x,cst,m<<1);
    update(mid+1,r,x,cst,m<<1|1);
}
int findmax(int l,int r,int x,int y,int cst,int m)
{
    if(r<x||l>y)return -1;
    if(l>=x&&r<=y)
    {
        if(st[m].empty())return -1 ;
        auto it = st[m].lower_bound(cst);
        if(it==st[m].begin())return -1 ;
        it-- ;
        return *it;
    }
    return max(findmax(l,mid,x,y,cst,m<<1),findmax(mid+1,r,x,y,cst,m<<1|1));
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,sz;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> line[i].x1 >> line[i].x2 >> line[i].y ;
        cc.push_back(line[i].x2);
        line[i].idx=i ;
    }
    cc.push_back(INT_MAX);
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    sz=cc.size();
    sort(line+1,line+1+n,[&](P a,P b){return a.x2<b.x2;});
    mp[-1]=0;
    for(i=n;i>=1;)
    {
        j=i;
        while(line[i].x2==line[i-1].x2&&i>1)
        {
            auto it = lower_bound(cc.begin(),cc.end(),line[i].x2)-cc.begin()+1;
            dp[line[i].idx]=mp[findmax(1,sz,1,it,line[i].y,1)]+1;
            i--;
        }
        auto it = lower_bound(cc.begin(),cc.end(),line[i].x2)-cc.begin()+1;
        dp[line[i].idx]=mp[findmax(1,sz,1,it,line[i].y,1)]+1;
        i=j;
        while(line[i].x2==line[i-1].x2&&i>1)
        {
            auto it1 = upper_bound(cc.begin(),cc.end(),line[i].x1)-cc.begin()+1;
            update(1,sz,it1,line[i].y,1);
            mp[line[i].y]=dp[line[i].idx];
            i--;
        }
        auto it1 = upper_bound(cc.begin(),cc.end(),line[i].x1)-cc.begin()+1;
        //printf("aa %d \n",it1);
        update(1,sz,it1,line[i].y,1);
        mp[line[i].y]=dp[line[i].idx];
        i-- ;
    }
    for(i=1;i<=n;i++)cout << dp[i] << '\n' ;

}
