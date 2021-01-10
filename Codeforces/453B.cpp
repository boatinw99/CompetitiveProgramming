/*
    Author : boatinw99
    Time complexity : O(N*MXVAL*2^PRIME)
    100*58*2^16
*/
#include<bits/stdc++.h>
using namespace std ;
const int N = 109 , M = 1<<16 , MXVAL = 58 , inf = 1e9 ; 
typedef pair<int,int> pii ;
#define fi first
#define se second
vector<int> V = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53}; 
int arr[N],divisor[MXVAL+9],ans[N];
struct items 
{
    int mn,track,assign ;

}dp[N][M];
items operate(items a,items b)
{
    if(a.mn<b.mn)return a ;
    else return b ;
}
void traceback(int idx,int mask)
{
    if(idx==0)return ; 
    ans[idx]=dp[idx][mask].assign;
    traceback(idx-1,dp[idx][mask].track);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    for(int i=1;i<=MXVAL;i++)
    {
        for(int j=0;j<V.size();j++)
        {
            if(i%V[j]==0)
            {
                divisor[i]+=1<<j;
            }
        }
    }
    //divisor[1]=M-1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<M;j++)dp[i][j]={inf,0,0};
    }
    dp[0][0]={0,0,0};
    for(int i=1;i<=n;i++)
    {
        for(int val=1;val<=MXVAL;val++)
        {
            for(int mask=0;mask<M;mask++)
            {
                if((divisor[val]&mask)==0)
                {
                    items tmp = {dp[i-1][mask].mn+abs(val-arr[i]),mask,val};
                    dp[i][mask|divisor[val]]=operate(dp[i][mask|divisor[val]],tmp);
                }
            }
        }
    }
    items tmp = {inf,0,0};
    for(int i=0;i<M;i++)
    {
        tmp = operate(tmp,dp[n][i]);
    }
    ans[n]=tmp.assign;
    traceback(n-1,tmp.track);
    for(int i=1;i<=n;i++)cout << ans[i] << " " ;
    return 0 ;
}