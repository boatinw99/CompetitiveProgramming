#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
typedef long long ll ;
vector<pair<int,bool> > v;
vector<pair<int,bool> > ::iterator it ;
main()
{
    int n,i,j,x,y,k=-1e9-7 ;
    scanf("%d",&n);
    int Lnum=0,Rnum=n;
    ll sumL=0,sumR=0,ans=LONG_LONG_MAX;
    k=-1e9-7;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        sumR+=1ll*x-k;
        v.push_back({x,0});
        v.push_back({y,1});
    }
    v.push_back({k,0});
    sort(v.begin(),v.end());
    for(it=v.begin()+1;it!=v.end();it++)
    {
        if(it->second==0)///L
        {
            sumR-=1ll*Rnum*(it->first-(it-1)->first);
            sumL+=1ll*Lnum*(it->first-(it-1)->first);
            Rnum--;
        }
        else ///R
        {
            sumR-=1ll*Rnum*(it->first-(it-1)->first);
            sumL+=1ll*Lnum*(it->first-(it-1)->first);
            Lnum++;
        }
        ans=min(ans,sumR+sumL);
    }
    printf("%lld",ans);
}
