#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
int md ;
map<ll,int> mp ;
ll h(ll a,ll b){return 1ll*a*1e9+b;}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T,n,sq,i,j ;
    ll hash,ans,x,y,z,a,b ;
    cin >> T ;
    while(T--){
        cin >> md >> a >> b ;
        mp.clear();
        sq=sqrt(6ll*md)+3;
        x=0,y=1;z=1;
        for(i=0;i<sq-1;i++)x=y,y=z,z=(x+y+md)%md;
        for(i=0;i<sq;i++){
            hash=h(a,b);
            if(!mp.count(hash))mp[hash]=i; ///care this
            tie(b,a)=make_pair(a,(b-a+md)%md);
        }
        ans=-1; a=0,b=1;
        for(i=0;i<sq;i++){
            hash=h(a,b);
            if(mp.count(hash)){
                ans=(1ll*i*sq+mp[hash]);
                break;
            }
            tie(b,a)=make_pair((z*b+y*a)%md,(y*b+x*a)%md);
        }
        cout << ans << '\n' ;
    }
}
