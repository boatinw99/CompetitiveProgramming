#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 1509 , K = 50,inf = 1e9;
vector<int> cc ;
int cst[N][N];
int dp[N][N],a[N],pos[N];
int f1[N],f2[N],n,sz;///f1 num , f2 sum
void update(int *f,int x,int cst)
{
    for(int i=x;i;i-=i&-i)f[i]+=cst;
}
int getsum(int *f,int x)
{
    int sum = 0 ;
    for(int i=x;i<=n;i+=i&-i)sum+=f[i];
    return sum ;
}
void solve(int i,int l,int r,int optx,int opty)
{
    /*
    for(int d=l;d<=r;d++)
    {
        for(int j=i;j<=d;j++)
        dp[i][d]=min(dp[i][d],dp[i-1][j-1]+cst[j][d]);
    }*/
    if(l>r)return ;
    pii best = {inf,0};
    for(int j=optx;j<=min(opty,mid);j++)
    {
        best=min(best,{dp[i-1][j]+cst[j+1][mid],j});
    }
    dp[i][mid]=best.fi;
    int opt = best.se ;
    ///printf("wtff %d %d (%d %d) (%d %d)\n",i,mid,best.fi,best.se,optx,opty);
    solve(i,l,mid-1,optx,opt);
    solve(i,mid+1,r,opt,opty);
}
int getans(int x,int sum,int cnt)
{
    int sumr = getsum(f2,x);
    int cntr = getsum(f1,x);
    int tmpr = sumr-cntr*cc[x-1];
    int suml = sum-sumr;
    int cntl = cnt-cntr;
    int tmpl = cc[x-1]*cntl-suml;
    return tmpl+tmpr;
}
int query(int x,int y,int sum)
{
    int l=1,r=sz;
    int len = y-x+1;
    while(l<r)
    {
        int ret1 = getans(mid,sum,len);
        int ret2=getans(mid+1,sum,len);
        if(ret1<ret2)r=mid;
        else l=mid+1;
    }
    return getans(l,sum,len);
}
void pre_process()
{
    for(int i=1;i<=n;i++)
    {
        int sum = a[i];
        update(f1,pos[i],1);
        update(f2,pos[i],a[i]);
        for(int j=i+1;j<=n;j++)
        {
            sum+=a[j];
            update(f1,pos[j],1);
            update(f2,pos[j],a[j]);
            cst[i][j]=query(i,j,sum);
        }
        memset(f1,0,sizeof f1);
        memset(f2,0,sizeof f2);
        sum = 0 ;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int k ;
    cin >> n >> k ;
    for(int i=1;i<=n;i++)cin >> a[i] ;
    for(int i=1;i<=n;i++)cc.push_back(a[i]);
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    sz=cc.size();
    for(int i=1;i<=n;i++)
    {
        pos[i]=lower_bound(cc.begin(),cc.end(),a[i])-cc.begin()+1;
    }
    pre_process();
    for(int i=1;i<=n;i++)
    {
        //for(int j=1;j<=n;j++)
        dp[0][i]=inf ;
    }
    dp[0][0]=0;
    for(int i=1;i<=k;i++)solve(i,1,n,0,n-1);
    cout << dp[k][n];
}
