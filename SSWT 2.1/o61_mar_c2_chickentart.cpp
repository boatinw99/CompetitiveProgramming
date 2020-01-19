#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , MAX =  1e9+7  ;
int a[N],dp1[N],dp2[N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,k,l,r,L=-1,R=MAX,i,j ;
    cin >> n >> m >> k ;
    for(i=1;i<=n;i++)cin >> a[i] ;
    while(L+1<R)
    {
        int mid=L+R>>1;
        int sum = 0;
        for(i=1,l=1;i<=n;i++)
        {
            sum+=a[i];
            while(sum>mid&&l<i)sum-=a[l],l++;
            while(i-l+1>m&&l<i)sum-=a[l],l++;
            dp1[i]=dp1[l-1]+1;
            if(a[i]>mid)dp1[i]=MAX ;
        }
        sum=0;
        for(i=n,r=n;i>=1;i--)
        {
            sum+=a[i];
            while(sum>mid&&r>i)sum-=a[r],r--;
            while(r-i+1>m&&r>i)sum-=a[r],r--;
            dp2[i]=dp2[r+1]+1;
            if(a[i]>mid)dp2[i]=MAX;
        }
        int ans = MAX ;
        for(i=1;i+m-1<=n;i++)
        {
            ans=min(ans,dp1[i-1]+dp2[i+m]+1);
        }
        if(ans<=k)R=mid;
        else L=mid;
    }
    cout << R ;
}
