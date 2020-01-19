#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9 ;
int n,md,ans=0,bit=0,mid=2 ;
int dp[2][3][3][5];///flip bit, max , min , sum
char s[N];
void update()
{
    for(int i=1;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<5;k++)
        dp[bit^1][i][j][k]=0;
    for(int i=1;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<5;k++)
            {
                int x=i,y=-j,sum=k-mid,tmp=dp[bit][i][j][k];
                if(abs(sum-x+1)<=2&&abs(sum-y+1)<=2)
                    dp[bit^1][max(sum+1,x)][j][k+1]=
                    (dp[bit^1][max(sum+1,x)][j][k+1]+tmp)%md;
                if(abs(sum-x-1)<=2&&abs(sum-y-1)<=2)
                    dp[bit^1][i][-min(sum-1,y)][k-1]=
                    (dp[bit^1][i][-min(sum-1,y)][k-1]+tmp)%md;
            }
        }
    }
    bit^=1;
}
void qans(int x,int mx,int mn,int sum)
{
    if(x>n)return ;
    int tmp1=sum ;
    if(s[x]=='P')tmp1--;
    else tmp1++;
    qans(x+1,max(mx,tmp1),min(mn,tmp1),tmp1);
    if(s[x]=='P')
    for(int i=1;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<5;k++)
    {
        int dx=i+sum,dy=-j+sum,sum=k-mid,tmp=dp[bit][i][j][k];
        if(abs(dx-mx)<=2&&abs(dx-mn)<=2&&abs(dy-mx)<=2&&abs(dy-mn)<=2)
            ans=(ans+tmp)%md;
    }
    update();
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j ;
    cin >> n >> md ;
    for(i=1;i<=n;i++)cin >> s[i] ;
    dp[0][1][0][mid+1]=1;
    qans(1,0,0,0);
    cout << (ans+1)%md ;
}
