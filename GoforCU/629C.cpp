#include<bits/stdc++.h>
using namespace std ;
char s[100009];
long long dp[2009][2009];
stack<char>st;
main()
{
    int n,m,l=0,r=0,i,j ;
    scanf("%d %d ",&n,&m);
    gets(s);
    for(i=0;i<m;i++)
    {
        if(st.empty())st.push(s[i]);
        else if(s[i]==')'&&st.top()=='(')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        l+=st.top()=='(';
        r+=st.top()==')';
        st.pop();
    }
    if(l+r>n-m||n%2!=0)
    {
        printf("0");
        return 0;
    }
    dp[0][0]=1;
    const int MOD=1e9+7;
    for(i=0;i<=2000;i++)
    {
        dp[i+1][1]=dp[i][0];
        for(j=1;j<=2000;j++)
        {
            dp[i+1][j-1]+=dp[i][j];
            dp[i+1][j-1]%=MOD;
            dp[i+1][j+1]+=dp[i][j];
            dp[i+1][j+1]%=MOD;
        }
    }
    long long pr=0 ;
    for(j=r;j-r+l<=n-m-j;j++)
    {
        for(i=j;j-r+l<=n-m-i;i++)
        {
            pr+=dp[i][j]*dp[n-m-i][j-r+l];
            pr=pr%MOD;
        }
    }
    printf("%I64d",pr);
}
