#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll prime = 123456789 ;
const int N = 1100;
map<ll,vector<int> > m;
vector<int>::iterator it;
ll dp[N+9][N+9];
int a[N];
main()
{
    int n,d,i,j,l,r,x,y,k ;
    ll hash=0;
    scanf("%d %d",&n,&k);
    dp[0][N]=1;
    for(i=1;i<=N;i++)
    {
        dp[i][1]=dp[i-1][N]*prime;
        for(j=2;j<=N;j++)dp[i][j]=dp[i][j-1]*prime;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[i]=x;
        hash=0;
        x--;
        while(x--)
        {
            scanf("%d %d",&l,&r);
            if(l>r)swap(l,r);
            hash+=dp[l][r];
        }
        m[hash].push_back(i);
    }
    while(k--)
    {
        scanf("%d",&x);
        int co=0;
        y=x;
        hash=0;
        for(i=1;i<x;i++)
        {
            scanf("%d %d",&l,&r);
            if(l>r)swap(l,r);
            hash+=dp[l][r];
        }
        for(it=m[hash].begin();it!=m[hash].end();it++)
        {
            if(a[*it]==y)co++;
        }
        printf("%d\n",co);
    }
}
