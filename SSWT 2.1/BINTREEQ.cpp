#include<bits/stdc++.h>
using namespace std ;
stack<int> st1,st2 ;///u,v
void findlca(int u,int v)
{
    while(u!=v)
    {
        if(u>v)st1.push(u%2),u>>=1;
        else st2.push(v%2),v>>=1;
    }
}
int qans(int n,int u,int v)
{
    findlca(u,v) ;
    int szu=st1.size(),szv=st2.size(),x=0,y=0,z,sz=max(szu,szv) ;
    for(;!st1.empty();x=x*2+st1.top(),st1.pop());
    for(;!st2.empty();y=y*2+st2.top(),st2.pop());
    if(szu>szv)z=x;
    else if(szu<szv)z=y;
    else z=max(x,y);
    int bits=1<<sz,l=1,r=n+1;
    while(l+1<r)
    {
        int mid=l+r>>1;
        if(1ll*mid*bits+z<=n)l=mid;
        else r=mid;
    }
    return l ;
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T,n,u,v ;
    cin >> T ;
    while(T--)
    {
        cin >> n >> u >> v ;
        cout << qans(n,u,v) << '\n' ;
    }
}
