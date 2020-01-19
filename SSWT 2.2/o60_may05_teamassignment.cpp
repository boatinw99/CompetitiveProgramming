#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , inf = 1e9+7 ;
int a[N],dp[N];
deque<int> dq ; ///store pos
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v,l=-1,r=inf ;
    cin >> n >> u >> v ;
    for(i=1;i<=n;i++)cin >> a[i];
    while(l+1<r)
    {
        int mid=l+r>>1;
        dq.push_front(0);
        int mx=0 ;
        ///mid=20 ;
        for(i=1;i<=n;i++)
        {
            if(a[i]>=mid)mx=i;
            while(!dq.empty()&&dq.front()<i-v)dq.pop_front();
            dp[i]=0;
            if(!dq.empty()&&dq.front()<=i-u&&dq.front()<mx)dp[i]=1 ;
            if(dp[i])dq.push_back(i);
        }
        if(dp[n])l=mid;
        else r=mid;
        dq.clear();
        memset(dp,0,sizeof dp);
    }
    cout << l ;

}
