#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , M = 253 , APHA = 26 ;
int nxt[26][N],last[26];
int dp[M][M][M],A[M],B[M],C[M],s[N],sz[4];
int n ; 
void pre_process()
{
    fill(last,last+APHA,n+1);
    for(int i=0;i<M;i++)for(int j=0;j<M;j++)for(int k=0;k<M;k++)dp[i][j][k]=n+1;
    dp[0][0][0]=0;
    for(int i=0;i<APHA;i++)nxt[i][n+1]=n+1;
    for(int j=n;j>=0;j--)
    {
        for(int i=0;i<APHA;i++)
        {
            nxt[i][j]=last[i];
        }
        last[s[j]]=j;
        //printf("last (%d) -> s[j] = %d \n ",s[j],j);
    }
}
int rec(int i,int j,int k,int val)
{
    //printf("rec %d | %d -> %d\n",val,dp[i][j][k],nxt[val][dp[i][j][k]]);
    return nxt[val][dp[i][j][k]];
}
void add(int rel,int val)
{
    sz[rel]++;
    int i = 0 , j = 0 , k = 0 ;
    if(rel==1)i=sz[1],A[i]=val;
    else if(rel==2)j=sz[2],B[j]=val; 
    else k=sz[3],C[k]=val;
    for(int x=i;x<=sz[1];x++)
    {
        for(int y=j;y<=sz[2];y++)
        {
            for(int z=k;z<=sz[3];z++)
            {
                dp[x][y][z]=n+1;
                if(x>0)dp[x][y][z]=min(dp[x][y][z],rec(x-1,y,z,A[x]));
                if(y>0)dp[x][y][z]=min(dp[x][y][z],rec(x,y-1,z,B[y]));
                if(z>0)dp[x][y][z]=min(dp[x][y][z],rec(x,y,z-1,C[z]));
               // printf("check x,y,z =%d %d %d || %d \n",x,y,z,dp[x][y][z]);
            }
        }
    }
    //printf("\n");
}
void clear(int rel)
{
    sz[rel]--;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m ;
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        char c ;
        cin >> c ;
        s[i] = c-'a' ;
    }
    pre_process();
    while(m--)
    {
        char c ;
        int rel ; 
        cin >> c >> rel ;
        if(c=='+')
        {
            cin >> c ; 
            add(rel,c-'a');
        }
        else 
        {
            clear(rel);
        }
        cout << (dp[sz[1]][sz[2]][sz[3]]<=n?"YES":"NO") << '\n' ;
    }
    return 0 ;
}