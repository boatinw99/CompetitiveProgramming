#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 50009,MOD=30011;
ll a[N];
ll b[N];
ll ans=0;
struct P
{
    int pos,boat,mul;
};
bool sortpos(P p1,P p2)
{
    return p1.pos<p2.pos;
}
vector<int> mada[N],madb[N];
vector<int>::iterator it  ;
vector<pair<int,int>  >overa,overb;
vector<pair<int,int> > ::iterator itover;
vector<P> porta,portb;
vector<P>::iterator itpo;
void travelleft(int n,int m)
{
    ll pr=0;
    int i,j;
    for(i=1;i<=m;i++)b[i]=0;
    for(itover=overa.begin();itover!=overa.end();itover++)
    {
        b[itover->second]-=a[itover->first];
    }
    for(i=1,itpo=porta.begin();i<=m&&itpo!=porta.end();i++)
    {
        while(itpo->pos==i&&itpo!=porta.end())
        {
            pr+=a[itpo->boat]*itpo->mul;
            itpo++;
        }
        b[i]+=pr;
        b[i]%=MOD;
        ans+=b[i];
        ans%=MOD;
    }
}
void travelright(int n,int m)
{
    ll pr=0;
    int i,j;
    for(i=1;i<=n;i++)a[i]=0;
    for(itover=overb.begin();itover!=overb.end();itover++)
    {
        a[itover->second]-=b[itover->first];
    }
    for(i=1,itpo=portb.begin();i<=n&&itpo!=portb.end();i++)
    {
        while(itpo->pos==i&&itpo!=portb.end())
        {
            pr+=b[itpo->boat]*itpo->mul;
            itpo++;
        }
        a[i]+=pr;
        a[i]%=MOD;
    }
}
main()
{
    int n,m,K,L,u,v,l,r,i,j,A,B ;
    scanf("%d %d %d %d",&n,&m,&K,&L);
    for(i=1;i<=L;i++)
    {
        scanf("%d %d",&l,&r);
        mada[l].push_back(r);
        madb[r].push_back(l);
    }
    for(i=1;i<=n;i++)sort(mada[i].begin(),mada[i].end());
    for(j=1;j<=m;j++)sort(madb[j].begin(),madb[j].end());
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&A,&B);
        l=B; r=B+A-1;
        for(it=mada[i].begin();it!=mada[i].end()&&*it<=r;it++)
        {
            if(l<*it)
            {
                overa.push_back({i,*it});
                r++;
            }
        }
        porta.push_back({l,i,1});
        porta.push_back({r+1,i,-1});
        a[i]=1;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&A,&B);
        l=B; r=B+A-1;
        for(it=madb[i].begin();it!=madb[i].end()&&*it<=r;it++)
        {
            if(l<=*it)
            {
                overb.push_back({i,*it});
                r++;
            }
        }
        portb.push_back({l,i,1});
        portb.push_back({r+1,i,-1});
    }
    sort(porta.begin(),porta.end(),sortpos);
    sort(portb.begin(),portb.end(),sortpos);
    for(i=1;i<=K;i+=2)
    {
        travelleft(n,m);
        travelright(n,m);
    }
    printf("%lld",ans);
}
