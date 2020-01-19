#include<bits/stdc++.h>
using namespace std;
const int N = 2009; 
int a[N][N];
bool vst[N];
vector<int> Vf[N],Vs[N];
int bfs1(int st)
{
    memset(vst,0,sizeof vst);
    queue<int> q ;
    q.push(st);
    vst[st]++;
    int cnt = 0 ;
    while(!q.empty())
    {
        int u = q.front();
        cnt++;
        for(auto it:Vf[u])
        {
            if(!vst[it]++)
            {
                q.push(it);
            }
        }
        q.pop();
    }
    return cnt ;
}
int bfs2(int st)
{
    memset(vst,0,sizeof vst);
    queue<int> q ;
    q.push(st);
    vst[st]++;
    int cnt = 0 ;
    while(!q.empty())
    {
        int u = q.front();
        cnt++;
        for(auto it:Vs[u])
        {
            if(!vst[it]++)
            {
                q.push(it);
            }
        }
        q.pop();
    }
    return cnt ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            if(a[i][j])Vf[i].emplace_back(j),Vs[j].emplace_back(i);
        }
    }
    if(bfs1(1)==n&&bfs2(1)==n)
    {
        cout << "YES" << '\n' ;
    }
    else cout << "NO" << '\n' ; 
    return 0 ;
}