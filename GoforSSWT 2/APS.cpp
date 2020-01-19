#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll prime = 98765431 ;
const int N = 5e5+9;
ll dp[300];
string A,B;
main()
{
    ios_base::sync_with_stdio(false);
    int i,j,n,m ;
    int pr=0;
    ll hash1=0;
    ll hash2=0;
    dp[0]=1;
    for(i=1;i<250;i++)dp[i]=dp[i-1]*prime;
    while(cin >> A)
    {
        cin >> B ;
        pr=0; hash1=hash2=0;
        n=A.length();
        m=B.length();
        for(i=0;i<m;i++)
        {
            hash1+=dp[B[i]];
            hash2+=dp[A[i]];
        }
        if(hash1==hash2)pr++;
        for(i=m;i<n;i++)
        {
            hash2-=dp[A[i-m]];
            hash2+=dp[A[i]];
            if(hash1==hash2)pr++;
        }
        printf("%d\n",pr);
    }
    return 0 ;
}


