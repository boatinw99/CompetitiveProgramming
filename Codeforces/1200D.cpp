#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<ll,ll> pll ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll INF = 1e18 ;
const int N = 2009 , inf = 1e9 , mod = 1e9+7 ;
int n,k,cntLR=0,cntUD=0;
int qsLR[N][N],qsUD[N][N],A[N][N],preLR[N],preUD[N];
int pref[N];
pii ud[N];///col
int check(int l,int x,int y)
{
    if(x>y)return 0 ;
    return qsLR[l][y]-qsLR[l][x-1];
}
int checkud(int l,int x,int y)
{
    if(x>y)return 0 ;
    return qsUD[y][l]-qsUD[x-1][l];
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> k ;
    for(int i=0;i<N;i++)ud[i]={inf,0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char c ;
            cin >> c ;
            if(c=='W')A[i][j]=1;
            qsLR[i][j]=A[i][j]+qsLR[i][j-1];
            qsUD[i][j]=A[i][j]+qsUD[i-1][j];
            if(c=='B')
            {
                ud[j].fi=min(ud[j].fi,i);
                ud[j].se=max(ud[j].se,i);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(check(i,1,n)==n)preLR[i]++,cntLR++;
        if(checkud(i,1,n)==n)cntUD++;
    }
    int ans = 0 ;
    for(int j=1;j+k-1<=n;j++)
    {
        int cnt=0,cntcol=0;
        memset(pref,0,sizeof pref);
        for(int d=j;d<=j+k-1;d++)
        {
            if(ud[d].fi<=ud[d].se)
            {
                if(ud[d].se-ud[d].fi+1<=k)
                {
                    pref[ud[d].fi+1]--;
                    pref[max(ud[d].se-k+1,1)]++;
                }
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(check(i,j+k,n)+k+check(i,1,j-1)==n&&preLR[i]!=1)
            {
                cnt++;
            }
        }
        cntcol+=pref[1];
        //printf("wtf %d %d %d %d\n",cnt,cntcol,cntLR,cntUD);
        ans=max(ans,cnt+cntcol+cntLR+cntUD);
        for(int i=k+1;i<=n;i++)
        {
            if(check(i,j+k,n)+k+check(i,1,j-1)==n&&preLR[i]!=1)
            {
                cnt++;
            }
            if(check(i-k,j+k,n)+k+check(i-k,1,j-1)==n&&preLR[i-k]!=1)
            {
                cnt--;
            }
            cntcol+=pref[i-k+1];
            ans=max(ans,cnt+cntcol+cntLR+cntUD);
           // printf("wtf %d %d %d %d\n",cnt,cntcol,cntLR,cntUD);
        }
        //printf("\n\n");
    }
    //printf("qweqwe %d %d \n",cntLR,cntUD);
    cout << ans << '\n' ; 
    return 0 ;
}