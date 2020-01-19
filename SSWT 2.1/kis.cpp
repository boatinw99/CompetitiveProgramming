#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 109 ;
ll dp[N][N],K ;
ll qs[N][N];
int n,L,a[N],pos[N];
void comp(int x,int rmn)
{
    cout << x << " " ;
    if(K==1)return ;
    K--;
    for(int i=0;i<n;i++)
    {
        if(pos[x]<pos[i])
        {
            if(x>i)
            {
                if(qs[rmn-1][pos[i]]>=K)
                {
                    comp(i,rmn-1);
                    return ;
                }
                K-=qs[rmn-1][pos[i]];
            }
            else
            {
                if(qs[rmn][pos[i]]>=K)
                {
                    comp(i,rmn);
                    return ;
                }
                K-=qs[rmn][pos[i]];
            }
        }
    }
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,k ;
    ll all=0 ;
    cin >> n >> L >> K ;
    K++;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        pos[a[i]]=i ;
    }
    for(i=n-1;i>=0;i--)
    {
        dp[0][i]=1;
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])for(k=0;k<=L;k++)dp[k][i]+=dp[k][j];
            else for(k=1;k<=L;k++)dp[k][i]+=dp[k-1][j];
        }
    }
    for(j=0;j<n;j++)
    {
        qs[0][j]=dp[0][j];
        for(i=1;i<=L;i++)qs[i][j]=qs[i-1][j]+dp[i][j];
    }
    for(i=0;i<n;i++)
    {
        if(qs[L][pos[i]]>=K)
        {
            comp(i,L);
            return 0 ;
        }
        K-=qs[L][pos[i]];
    }
    cout << "-1" ;
}
