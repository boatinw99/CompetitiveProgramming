#include<bits/stdc++.h>
using namespace std ;
const int N = 109 ,inf = 1e9+7 ;
int a[N],qs[N];
int dp1[N],dp2[N]; ///bound [l,r]
int n,k ;
deque<int> dq ;
void query(int l,int r,int mn,int mx)
{
    ///find min -> dp1
    dp1[l-1]=0;
    dp2[l-1]=0;
    dq.push_front(l-1);
    for(int i=l;i<=r;i++)
    {
        while(!dq.empty()&&qs[i]>qs[dq.front()]+mx)dq.pop_front();
        if(!dq.empty()&&qs[i]-qs[dq.front()]>=mn)
        {
            dp1[i]=dp1[dq.front()]+1;
            dq.push_back(i);
        }
    }
    dq.clear();
    dq.push_front(l-1);
    for(int i=l;i<=r;i++)
    {
        while(!dq.empty()&&qs[i]>qs[dq.front()]+mx)dq.pop_front();
        while(dq.size()>1&&qs[i]-qs[dq[1]]>=mn)dq.pop_front();
        if(!dq.empty()&&qs[i]-qs[dq.front()]>=mn)
        {
            dp2[i]=dp2[dq.front()]+1;
            dq.push_back(i);
        }
    }
    dq.clear();
}
int qans(int x,int y)
{
    int sum = qs[y]-qs[x-1];
    int l=0,r=sum+1;
    while(l+1<r)
    {
        int mid=l+r>>1;
        fill(dp1,dp1+N-1,inf);
        fill(dp2,dp2+N-1,inf);
        query(1,x-1,mid,sum); ///[1,n,min,max]
        query(y+1,n,mid,sum);
        if(dp1[x-1]+dp1[n]<=k-1&&k-1<=dp2[x-1]+dp2[n])l=mid ;
        else r=mid ;
    }
    return l ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,mx = 0 ,ans = inf ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        mx=max(mx,a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(qs[j]-qs[i-1]>=mx)
            {
                int tmp = qans(i,j);
                ///printf("aaa %d %d %d | %d\n",i,j,qs[j]-qs[i-1],tmp);
                ans=min(ans,qs[j]-qs[i-1]-qans(i,j));
            }
        }
    }
    cout << ans ;
}
