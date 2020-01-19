#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef vector<int> vi ;
#define fi first
#define se second 
int n ;
vi sort_point(vi point)
{
    vector<int> ans ; 
    vector<pair<ll,int>> V ;
    if(point.size()<=1)return point ;
    for(auto it:point)
    {
        ll ret ; 
        printf("1 1 2 %d\n",it);
        fflush(stdout);
        cin >> ret ; 
        V.emplace_back(ret,it);
    } 
    sort(V.begin(),V.end(),greater<pair<ll,int>>());
    int mid = V[0].se ; 
    vi L,R ; 
    for(int i=1;i<V.size();i++)
    {
        int x = V[i].se ; 
        int ret ; 
        printf("2 1 %d %d\n",mid,x);
        fflush(stdout);
        scanf("%d",&ret);
        if(ret<0)L.insert(L.begin(),x);
        else R.push_back(x);
    }
    for(auto it:L)ans.emplace_back(it);
    ans.emplace_back(mid);
    for(auto it:R)ans.emplace_back(it);
    return ans ;      
}
int main()
{
    vi L,R ; 
    scanf("%d",&n);
    for(int i=3;i<=n;i++)
    {
        int ret ;
        printf("2 1 2 %d\n",i);
        fflush(stdout);
        scanf("%d",&ret);
        if(ret<0)L.emplace_back(i);
        else R.emplace_back(i);
    }
    vi ans ; 
    ans.push_back(0);
    ans.push_back(1);
    vi tmp ;
    tmp=sort_point(L);
    for(auto it:tmp)ans.push_back(it);
    ans.push_back(2);
    tmp=sort_point(R);
    for(auto it:tmp)ans.push_back(it);
    for(auto it:ans)
    {
        printf("%d ",it);
    }
    return 0 ;
}