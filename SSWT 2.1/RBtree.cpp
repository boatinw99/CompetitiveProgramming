#include<bits/stdc++.h>
using namespace std ;
const int LOG = log2(1e9);
int st[LOG+1];
int findlca(int u,int v,int color)
{
    int sum=0,x,y ;
    while(u!=v)
    {
        if(v>u)
        {
            x=log2(v);
            sum+=(st[x]==color);
            v>>=1;
        }
        else
        {
            x=log2(u);
            sum+=(st[x]==color);
            u>>=1;
        }
    }
    x=log2(u);
    return sum+(st[x]==color) ;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s ;
    int T,i,j,x,y ;
    st[0]=1;
    for(i=1;i<=LOG;i++)st[i]=st[i-1]^1;
    cin >> T ;
    while(T--)
    {
        cin >> s ;
        if(s=="Qi")
        {
            for(i=0;i<=LOG;i++)st[i]=st[i]^1;
        }
        else
        {
            cin >> x >> y ;
            if(s=="Qb")cout << findlca(x,y,1)<< '\n';
            else cout << findlca(x,y,0)<<'\n' ;
        }
    }
}
