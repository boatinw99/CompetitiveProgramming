#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5+9 ; 
ll dp[N],tmp[4];
vector<ll> V[4];
int amt ; //amount
void precomp()
{
    //tmp[1] , tmp[2] , tmp[3]
    memset(tmp,0,sizeof tmp);
    if(V[1].size()>=3)tmp[3]=V[1][0]+V[1][1]+V[1][2];
    if(V[1].size()>=2)tmp[2]=V[1][0]+V[1][1];
    if(!V[1].empty()&&!V[2].empty())tmp[2]=max(tmp[2],V[1][0]+V[2][0]);
    tmp[1]=0;
    for(int i=1;i<=3;i++)
    {
        if(!V[i].empty())tmp[1]=max(tmp[1],V[i][0]);
    }
}
void upd1(int x)
{
    dp[x+1]=max(dp[x+1],dp[x]+2*tmp[1]);
}
void upd2(int x,int mx)
{
    if(mx<2)return ;
    vector<ll> U ; 
    if(!V[2].empty())U.push_back(V[2][0]);
    for(int i=1;i<=2&&i<=V[1].size();i++)
    {
        U.push_back(V[1][i-1]);
    }
    sort(U.begin(),U.end(),greater<ll>());
    if(U.size()>=2)
    {
        dp[x+2]=max(dp[x+2],dp[x]+2*U[0]+U[1]);
    }
}
void upd3(int x,int mx)
{
    if(V[1].size()>=3)dp[x+3]=max(dp[x+3],dp[x]+tmp[3]+V[1][0]);
}
void upd(int l,int r,int mx)
{
    for(int i=r;i>=l&&i>=0;i--)
    {
        if(i-10>=0)dp[i]=max(dp[i],dp[i-10]);
        if(i%10==9)
        {
            upd1(i);
            upd2(i,mx);
            upd3(i,mx);
        }
        else if(i%10==8)
        {
            upd2(i,mx);
            upd3(i,mx);
        }
        else if(i%10==7)
        {
            upd3(i,mx);
        }
        for(int j=mx;j>0;j--)     
        {
            dp[i+j]=max(dp[i+j],dp[i]+tmp[j]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m ;
    cin >> m ;
    while(m--)
    {
        int n ;
        cin >> n ;
        for(int i=1,ci,di;i<=n;i++)
        {
            cin >> ci >> di ;
            V[ci].push_back(di);
        }
        for(int i=1;i<=3;i++)sort(V[i].begin(),V[i].end(),greater<ll>());
        precomp();
        upd(amt-9,amt,min(n,3));
        amt+=min(3,n);
        for(int i=1;i<=3;i++)V[i].clear();
    }
    ll ans = 0 ;
    for(int i=max(amt-10,0);i<=amt;i++)ans=max(ans,dp[i]);
    cout << ans << '\n' ;
    return 0 ;
}