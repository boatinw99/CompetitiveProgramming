///unsuccessful because not sure that path between prince,princess
/// and minions in 1 step no need to contain minion
#include<bits/stdc++.h>
using namespace std ;
const int N = 109 , T = 24;
int B ;
int F[N][N][T];
bool a[N][N][T];
main()
{
    int n,m,r1,r2,q,t,x,y,x1,y1,len,d,ti,i,j ;
    cin >> n >> m >> r1 >> r2 >> q >> t ;
    B=n*m;
    while(q--)
    {
        cin >> x >> y >> x1 >> y1 ;
        len=abs(x-x1)+abs(y-y1);
        if(x==x1)for(d=0;d<=len;d++)for(ti=d;ti<T;ti+=len+1)a[x][y+d][ti]++;
        else for(d=0;d<=len;d++)for(ti=d;ti<T;ti+=len+1)a[x+d][y][ti]++;
    }
    for(ti=0;ti<T;ti++)for(x=0;x<n;x++)for(y=0;y<m;y++)
        for(x1=0;x1<n;x1++)for(y1=0;y1<m;y1++)
        {

        }
}
