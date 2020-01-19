#include<bits/stdc++.h>
using namespace std ;
typedef vector<int> vi ;
const int N = 109 , M = 1<<15 , mxlow = M-1 , mxhi = ((1<<30)-1)-mxlow; 
map<vi,int> mp; 
int a[N],n,ans=-1; 
int getX(vi V,int sum)
{
    vi nw ; 
    for(auto it:V)
    {
        if(sum<it)return -1 ; 
        nw.emplace_back(sum-it);
    }
    if(mp.find(nw)!=mp.end())return mp[nw];
    else return -1 ; 
}
void process_lowbit()
{
    for(int x=0;x<M;x++)
    {
        vi V ; 
        for(int i=1;i<=n;i++)
        {
            V.emplace_back(__builtin_popcount((a[i]&mxlow)^x));
        }
        mp[V]=x;
    }   
}
void process_highbit()
{
    for(int x=0;x<M;x++)
    {
        vi V ;
        int use = x<<15 ; 
        for(int i=1;i<=n;i++)
        {
            V.emplace_back(__builtin_popcount((a[i]&mxhi)^use));
        }
        for(int sum=0;sum<=30;sum++)
        {
            int ret = getX(V,sum);
            if(ret>-1) 
            {
                ans=use+ret ; 
                return ;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] ;
    }
    process_lowbit();
    process_highbit();
    cout << ans << '\n' ; 
    return 0 ;
}