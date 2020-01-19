#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 , sq = 320 ,inf = 1e9+7 ;
pii a[N],q[N];
int n,m,sum[N],cnt[N],nowsum[N],lpos[N],rpos[N];
ll ans[N],dp[sq][sq];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].fi;
        a[i].se=i;
    }
    for(int i=1;i<=m;i++)cin >> q[i].fi >> q[i].se ;
    sort(a+1,a+1+n);
    for(int block=1;block<=(n-1)/sq+1;block++)
    {
        vector<pii> V ;
        int l=(block-1)*sq+1,r=min(block*sq,n);
        memset(nowsum,0,sizeof nowsum);
        for(int i=l;i<=r;i++)nowsum[a[i].se]+=a[i].fi;
        for(int i=1;i<=n;i++)nowsum[i]+=nowsum[i-1];
        for(int i=1;i<=m;i++)
        {
            int tmp = cnt[q[i].se]-cnt[q[i].fi-1];
            ans[i]+=2ll*tmp*(nowsum[q[i].se]-nowsum[q[i].fi-1]);
        }
        for(int i=l;i<=r;i++)V.push_back(a[i]);
        sort(V.begin(),V.end(),[&](pii a,pii b){return a.se<b.se;});
        int sz = V.size();
        for(int i=sz-1;i>=0;i--)
        {
            dp[i][i]=V[i].fi;
            ll s = 0 ;
            int tmp = 0 ;
            for(int j=i+1;j<sz;j++)
            {
                ///printf("hello %d %d \n",i,j);
                if(V[i].fi>=V[j].fi)tmp++;
                else s+=2*V[j].fi;
                dp[i][j]=dp[i+1][j]+s+1ll*V[i].fi*(2*tmp+1);
            }
        }
        for(int i=0;i<=n+1;i++)lpos[i]=inf,rpos[i]=-1;
        for(int i=0;i<sz;i++)lpos[V[i].se]=rpos[V[i].se]=i;
        for(int i=n;i>=1;i--)lpos[i]=min(lpos[i],lpos[i+1]);
        for(int i=1;i<=n;i++)rpos[i]=max(rpos[i],rpos[i-1]);
        for(int i=1;i<=m;i++)
        {
            int L = q[i].fi , R = q[i].se ;
            if(lpos[L]<=rpos[R])ans[i]+=dp[lpos[L]][rpos[R]];
        }
        for(auto it:V)sum[it.se]++;
        for(int i=1;i<=n;i++)cnt[i]=cnt[i-1]+sum[i];
    }
    cout << setprecision(10);
    for(int i=1;i<=m;i++)
    {
        double d = 1.0*ans[i]/(q[i].se-q[i].fi+1)/(q[i].se-q[i].fi+1);
        cout << d << '\n' ;
    }
    return 0 ;
}
