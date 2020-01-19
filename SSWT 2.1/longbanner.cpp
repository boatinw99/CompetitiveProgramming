#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int x[N],hi[N],f[N];
vector<int> cc;
void update(int i,int cst)
{
    for(;i<N;i+=i&-i)f[i]+=cst;
}
int getsum(int i)
{
    int ans=0;
    for(;i;i-=i&-i)ans+=f[i];
    return ans ;
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,h,K,y,i,j,L,k ;
    cin >> n >> h >> L ;
    for(i=1;i<=n;i++)
    {
        cin >> x[i] >> hi[i] ;
        cc.push_back(hi[i]);
    }
    sort(cc.begin(),cc.end());
    auto it=lower_bound(cc.begin(),cc.end(),hi[1])-cc.begin()+1;
    update(it,1);
    int ans=0;
    for(i=1,j=i;i<=n;i++)
    {
        while(x[j+1]-x[i]<=h&&j+1<=n)
        {
            j++;
            auto it=lower_bound(cc.begin(),cc.end(),hi[j])-cc.begin()+1;
            update(it,1);
        }
        for(k=0;k<=L;k++)
        {
            auto itl=lower_bound(cc.begin(),cc.end(),hi[i]-k)-cc.begin();
            auto itr=upper_bound(cc.begin(),cc.end(),hi[i]-k+L)-cc.begin();
            ans=max(ans,getsum(itr)-getsum(itl));
        }
        auto it=lower_bound(cc.begin(),cc.end(),hi[i])-cc.begin()+1;
        update(it,-1);
    }
    cout << ans ;

}

