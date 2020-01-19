#include<bits/stdc++.h>
using namespace std ;
const int N = 20 , inf = 1e9 ; 
int dp[1<<N],a[N][N],cntbit[1<<N],cst[1<<N][N],pref[N],lg[1<<N]; /// dp min 
int vst[N];
int m ; 
void init()
{
    for(int bit=0;bit<(1<<m);bit++)
    {
        cntbit[bit]=__builtin_popcount(bit);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i!=j)pref[i]+=a[i][j];
        }
    }
    for(int bit=1;bit<(1<<N);bit<<=1)
    {
        lg[bit]=log2(bit);
    }
    for(int i=0;i<m;i++)
    {
        cst[0][i]=-pref[i];
        for(int bit=1;bit<(1<<m);bit++)
        {
            if((1<<i)&bit)continue ;
            int nwbit = (bit-1)&bit ;
            int lastbit = bit^nwbit ;
            int town = lg[lastbit];
            cst[bit][i]=cst[nwbit][i]+2*a[i][town];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    string s ;
    cin >> n >> m ;
    cin >> s ;
    fill(dp,dp+(1<<N),inf);
    dp[0]=0;
    for(int i=0;i<s.size()-1;i++)
    {
        int x = s[i]-'a' , y = s[i+1]-'a';
        a[x][y]++;
        a[y][x]++;
    }
    init();
    for(int bit=0;bit<(1<<m);bit++)
    {
        for(int i=0;i<m;i++)
        {
            if((bit&(1<<i))==0)
            {
                int pos = cntbit[bit];
                dp[bit|(1<<i)]=min(dp[bit|(1<<i)],dp[bit]+pos*cst[bit][i]);
            }
        }
    }
    cout << dp[(1<<m)-1]<< '\n' ;
    return 0 ;
}