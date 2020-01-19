#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e4+9 ,mxbit=1<<5,MIN=-1e9;
vector<pii> query[N];
int dp[mxbit][mxbit],tmp[mxbit][mxbit];
void update(int nlike,int like)
{
    int mx=0,x,y ;
    for(int i=0;i<mxbit;i++)
    {
        for(int j=0;j<mxbit;j++)
        {
            if((j&nlike)!=nlike)dp[i][j]++;
            else if((j&like)!=0)dp[i][j]++;
            if(mx<dp[i][j])mx=dp[i][j],x=i,y=j ;
        }
    }
    //printf("aa %d %d %d\n",mx,x,y);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,i,j,u,v,F,L,x,k,tmp1 ;
    cin >> n >> m ;
    int cir=n-3;
    while(m--)
    {
        cin >> u >> F >> L ;
        int b1=0,b2=0 ;
        for(i=1;i<=F;i++)
        {
            cin >> x ;
            if(u>=cir&&x<=4)x+=n;
            if(x-u<=4&&x-u>=0)
            {
                b1+=1<<(4-(x-u));
            }
        }
        for(i=1;i<=L;i++)
        {
            cin >> x ;
            if(u>=cir&&x<=4)x+=n;
            if(x-u<=4&&x-u>=0)
            {
                b2+=1<<(4-(x-u));
            }
        }
        query[u].emplace_back(b1,b2);
    }
    for(i=0;i<mxbit;i++)
    {
        for(j=0;j<mxbit;j++)
        {
            dp[i][j]=MIN,tmp[i][j]=MIN ;
        }
        dp[i][i]=0;
    }
    for(i=1;i<cir-1;i++)
    {
        for(auto it:query[i])update(it.fi,it.se);
        for(j=0;j<mxbit;j++)
        {
            for(k=0;k<mxbit;k++)
            {
                int cpt=k;
                if(cpt>=16)cpt-=16;
                tmp[j][cpt<<1]=max(tmp[j][cpt<<1],dp[j][k]);
                tmp[j][cpt<<1|1]=max(tmp[j][cpt<<1|1],dp[j][k]);
            }
        }
        for(j=0;j<mxbit;j++)for(k=0;k<mxbit;k++)
            dp[j][k]=tmp[j][k],tmp[j][k]=MIN ;
    }
    for(auto it:query[cir-1])update(it.fi,it.se);
    for(i=cir,tmp1=16;i<=n;i++,tmp1>>=1)
    {
        for(j=0;j<mxbit;j++)
        {
            int same=0;
            if(tmp1&j)same=1;
            for(k=0;k<mxbit;k++)
            {
                int cpt=k;
                if(cpt>=16)cpt-=16;
                tmp[j][cpt*2+same]=max(tmp[j][cpt*2+same],dp[j][k]);
            }
        }
        for(j=0;j<mxbit;j++)for(k=0;k<mxbit;k++)
            dp[j][k]=tmp[j][k],tmp[j][k]=MIN ;
        for(auto it:query[i])update(it.fi,it.se);
    }
    int ans=0;
    for(i=0;i<mxbit;i++)for(j=0;j<mxbit;j++)ans=max(ans,dp[i][j]);
    cout << ans ;
}
