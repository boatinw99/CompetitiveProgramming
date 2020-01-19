#include<bits/stdc++.h>
using namespace std ;
const int N = 2e3+9 ;
typedef pair<int,int> pii ;
#define fi first
#define se second
struct P
{
    int x,in,out,cst ;
};
int n;
int py[N*2];
vector<P> point;
vector<pair<int,pii> > cc; ///coordinate compression ;
///cst , pos | fi or se
bool cmp(P p1,P p2)
{
    return p1.x<p2.x ;
}
int findlen()
{
    int i,j,cnt=0,ans=0;
    for(j=0;j<4*n-1;j++)
    {
        cnt+=py[j];
        if(cnt>0)
        {
            ans+=cc[j+1].fi-cc[j].fi;
        }
    }
    return ans ;
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,x1,y1,x2,y2 ;
    long long ans=0 ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2 ;
        point.push_back({x1,y2,y1,1});
        point.push_back({x2,y2,y1,-1});
    }
    sort(point.begin(),point.end(),cmp);
    for(i=0;i<2*n;i++)
    {
        cc.push_back({point[i].in,{i,0}});
        cc.push_back({point[i].out,{i,1}});
    }
    sort(cc.begin(),cc.end());
    for(j=0;j<4*n;j++)
    {
        if(cc[j].se.se==0)point[cc[j].se.fi].in=j;
        else point[cc[j].se.fi].out=j;
    }
    for(i=0;i<2*n;)
    {
        for(j=i;j<2*n&&point[j].x==point[i].x;j++)
        {
            py[point[j].in]+=point[j].cst;
            py[point[j].out]-=point[j].cst;
        }
        if(j==2*n)break;
        //printf("aa %d %d\n",i,j);
        int tmp = findlen();
        ans+=1ll*tmp*(point[j].x-point[i].x);
        i=j;
        //return 0 ;
    }
    cout << ans ;
}
