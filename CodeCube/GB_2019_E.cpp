#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se escond 
const int N = 1e5+9 , mod = 1e9+7 ; 
int qs[N][4],s[N],val[4];
void init()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<4;j++)qs[i][j]=0;
    }
}
bool check(int x,int y,int z,int zz)
{
    x=max(x,0);
    y=max(y,0);
    z=max(z,0);
    zz=max(zz,0);
    //printf("really %d %d %d %d | %d %d %d %d\n",val[0],val[1],val[2],val[3],x,y,z,zz);
    return val[0]<=x&&val[1]<=y&&val[2]<=z&&val[3]<=zz;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int Q ; 
    cin >> Q ; 
    while(Q--)
    {
        init();
        int a,b,c,d,e ; 
        cin >> val[0] >> val[1] >> val[2] >> val[3] >> e ;
        int n = e ;
        for(int i=1;i<=e;i++)
        {
            char cc ;
            cin >> cc ; 
            s[i]=cc-'1';
            qs[i][s[i]]++;
            for(int j=0;j<4;j++)qs[i][j]+=qs[i-1][j];
        }
        for(int i=1;i<=n;i++)
        {
            bool pr = 0 ;
            int space = n-i ;
            for(int j=0;j<4&&!pr;j++)
            {
                if(val[j]&&j!=s[i])
                {
                    val[j]--;
                   // printf("what the hell %d %d->qs[n][3]=%d\n",i,j,qs[n][3]-qs[i-1][3]);
                    if(check(space-(qs[n][0]-qs[i][0]),space-(qs[n][1]-qs[i][1]),space-(qs[n][2]-qs[i][2]),
                        space-(qs[n][3]-qs[i][3])))
                    {
                        char pp = j+'1' ;
                        cout << pp ;
                        pr++;
                    }
                    else val[j]++;
                }
            }
            assert(pr==1);
        }
        cout << '\n' ;
    }
    return 0 ;
}