#include<bits/stdc++.h>
using namespace std ;
const int N = 4e4+9 ,K = 650 ;
int a[N],mxval[N<<1],bucket[N/K+1][N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,l,r,k ;
    cin >> n >> m ;
    for(int i=0;i<n;i++)cin >> a[i] ;
    for(int i=0;i<n;i+=K)
    {
        memset(mxval,0,sizeof mxval);
        for(int j=i;j<n&&j<i+K;j++)mxval[a[j]]=a[j];
        for(int j=1;j<2*N;j++)mxval[j]=max(mxval[j],mxval[j-1]);
        for(int p=1;p<N;p++)
        {
            for(int j=p;;j+=p)
            {
                bucket[i/K][p]=max(bucket[i/K][p],mxval[j-1]%p);
                if(j>N)break;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin >> l >> r >> k ;
        l--,r--;
        int ans = 0 ;
        while(l<=r&&l%K)ans=max(ans,a[l++]%k);
        while(l+K-1<=r)ans=max(ans,bucket[l/K][k]),l+=K;
        while(l<=r)ans=max(ans,a[l++]%k);
        cout << ans << '\n' ;
    }
    return 0 ;
}
