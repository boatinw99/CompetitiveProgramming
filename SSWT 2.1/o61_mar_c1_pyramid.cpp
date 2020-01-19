#include<bits/stdc++.h>
using namespace std ;
const int N = 15009 ,mid = 5005;
vector<int> f[N];
void update(int x,int y)
{
    for(;x<N;x+=x&-x)f[x].push_back(y);
}
int getsum(int x,int y)
{
    int sum=0;
    for(;x;x-=x&-x)
    {
        for(auto it:f[x])if(y<=it)sum++;
    }
    return sum ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,x,len ;
    cin >> n ;
    while(n--)
    {
        cin >> x >> len ;
        x+=mid;
        cout << getsum(x-len,x+len) <<'\n';
        update(x-len,x+len);
    }
}
