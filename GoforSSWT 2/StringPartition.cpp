#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
char s[N];
bool b[N/2];
int dp[26];
main()
{
    int n,x,i,j,k ;
    scanf("%s",&s);
    n=strlen(s);
    x=n;
    int pr=INT_MAX;
    for(i=2;x>1;i++)
    {
        while(x%i==0)
        {
            x/=i;
            b[i]++;
        }
    }
    int max1=0,maxall;
    for(i=2;i<=n/2;i++)
    {
        if(b[i])
        {
            maxall=0;
            x=n/i;
            for(k=0;k<x;k++)
            {
               max1=0;
               for(j=0;j<i;j++)
               {
                   dp[s[j*x+k]-'a']++;
               }
               for(j=0;j<26;j++)
               {
                   max1=max(max1,dp[j]);
                   dp[j]=0;
               }
               maxall+=max1;
            }
            pr=min(pr,n-maxall);
        }
    }
    for(i=0;i<n;i++)dp[s[i]-'a']++;
    for(i=0;i<26;i++)pr=min(pr,n-dp[i]);
    printf("%d",pr);
}
