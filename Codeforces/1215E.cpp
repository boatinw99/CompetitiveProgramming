#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll INF = 1e18 ;
const int N = 4e5+9 , M = 20 ; 
ll dp[1<<M],add[N],cst[M][M];
bool color[M];
int n,A[N],val[N];
void precomp(int x)
{
    int cnt = 0 ;
    for(int i=1;i<=n;i++)
    {
        cnt+=(A[i]==x);
        cst[x][A[i]]+=cnt;
    }
    cnt = 0 ;
    for(int i=1;i<=n;i++)
    {
        if(A[i]==x)
        {
            add[x]+=i-1-cnt;
            cnt++;
        }
    }
}
ll getsum(int bits,int x) ///bits , val 
{
    ll inex = 0 ;
    for(int i=0;i<M;i++)
    {
        if(val[i]&bits)
        {
            inex+=cst[i][x];
        }
    }
    return add[x]-inex;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    int idx = 0 ;
    for(int i=1;i<=n;i++)
    {
        cin >> A[i] ;
        A[i]--;
        color[A[i]]++;
    }
    for(int i=0;i<M;i++)
    {
        val[i]=1<<i; 
        if(color[i])
        {
            idx+=val[i];
            precomp(i);
        }
    }
    int mask = 1<<M ; 
    for(int i=0;i<mask;i++)
    {
        dp[i]=INF ; 
    }
    dp[0]=0;
    for(int bits=0;bits<mask;bits++)
    {
        for(int i=0;i<M;i++)
        {
            if(color[i]&&(val[i]&bits)==0&&dp[bits]!=INF)
            {
                dp[bits+val[i]]=min(dp[bits+val[i]],dp[bits]+getsum(bits,i));
            }
        }
    }
    cout << dp[idx] << '\n' ;
    return 0 ;
}