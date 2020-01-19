#include<bits/stdc++.h>
using namespace std ;
typedef vector<int> vi ;
const int N = 3e5+9 ; 
vi edge ; 
bool clr[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ;
    while(T--)
    {
        int n,m ;
        cin >> n >> m ;
        for(int i=1;i<=3*n;i++)clr[i]=0;
        edge.clear();
        for(int i=1,u,v ;i<=m;i++)
        {
            cin >> u >> v ;
            if(!clr[u]&&!clr[v])
            {
                clr[u]++;
                clr[v]++;
                if(edge.size()<n)edge.push_back(i);
            }
        }
        if(edge.size()==n)
        {
            cout << "Matching" << '\n' ;
            for(auto it:edge)cout << it << " " ; 
        }
        else 
        {
            cout << "IndSet" << '\n' ;
            int cnt = 0 ;
            for(int i=1;i<=3*n&&cnt<n;i++)
            {
                if(!clr[i])
                {
                    cnt++;
                    cout << i << " " ;
                }
            }
        }
        cout << '\n' ;

    }
}