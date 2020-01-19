#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll dp[20][10][3];
ll query(ll x)
{
    ll y = x,cnt=0,pw=1 ;
    int dig = 0,pre1=-1,pre2=-1 ;
    while(y>=10)
    {
        y/=10;
        dig++;
        pw*=10;
    }
    for(;dig>0;dig--,pw/=10)
    {
        ll tmp = x/pw;
        ll nxt = x/(pw/10)-tmp*10;
        //printf("bbb %lld %lld\n",tmp,nxt);
        if(tmp>0)cnt+=dp[dig][tmp-1][1];///099
        if(tmp>=0)
        {
            if(nxt>=tmp)
            {
                cnt+=dp[dig-1][tmp][0];
                //printf("another %lld ",dp[dig-1][tmp][0]);
                if(tmp-1>=0)cnt-=dp[dig-1][tmp-1][0];///11...
            }
            if(nxt>=pre2&&pre2!=-1)
            {
                ll sum=tmp;
                if(pre1<=tmp&&pre1!=-1)sum--;
                cnt+=dp[dig-1][pre2][0]*(sum);
                if(tmp-1>=0)-dp[dig-1][pre2-1][0]*(sum);
            }
            else if(nxt<pre2&&pre2!=-1)
            {
                ll sum = tmp-1 ;
                if(pre1<=tmp&&pre1!=-1)sum--;
                cnt+=dp[dig-1][pre2][0]*(sum);
                if(tmp-1>=0)-dp[dig-1][pre2-1][0]*(sum);
            }
        }
        //printf("cntnow = %lld \n",cnt);
        //printf("%lld %d | %lld\n",tmp,dig,dp[dig][tmp-1][1]);
        if(pre1==tmp||pre2==tmp)
        {
            cnt+=pw ;
            break;
        }
        pre1=pre2;
        pre2=tmp;
        x-=tmp*pw;

    }
    //cout << cnt ;
    return cnt;
}
main()
{
    ll L,R ;
    int i,j,k ;
    cin >> L >> R ;
    ///digit0
    for(i=0;i<10;i++)dp[0][i][0]=i;
    ///digit1
    dp[1][0][0]=dp[0][9][0];
    for(i=1;i<10;i++)
    {
        dp[1][i][0]=dp[1][i-1][0]+9;
        dp[1][i][1]=dp[1][i-1][1]+1;
    }
    ///digit2
    for(i=0;i<3;i++)dp[2][0][i]=dp[1][9][i];
    for(i=1;i<10;i++)
    {
        ll tmp=dp[1][9][1]+9;
        dp[2][i][0]=dp[2][i-1][0]+(100-tmp-9);
        dp[2][i][1]=dp[2][i-1][1]+tmp+9;
    }
    ll rmn=1000;
    for(k=3;k<19;k++,rmn*=10)
    {
        for(j=0;j<2;j++)dp[k][0][j]=dp[k-1][9][j];
        for(i=1;i<10;i++)
        {
            ll tmp=dp[k-1][9][1]+dp[k-1][i][0]-dp[k-1][i-1][0]
            for(j=0;j<10;j++)
            {
                if(j!=i)
                {
                    tmp+=dp[k-3][j][0];
                }
            }
            dp[k][i][1]=dp[k][i-1][1]+tmp;
            dp[k][i][0]=-dp[k][i][1];
            for(j=0;j<i;j++)dp[k][i][0]+=rmn;
            //printf("%lld %lld \n",dp[k][i][1],dp[k][i][0]);
        }
    }
    //query(123);
    //cout << query(100);
    cout << (R-L+1)-query(R)+query(L-1) ;
}
