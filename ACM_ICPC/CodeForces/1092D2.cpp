#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ; 
vector<int> V ;
int a[N];
int dp[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,mx=0; 
    cin >> n ; 
    for(int i=1;i<=n;i++)
    {
        int ai ; 
        cin >> ai ;
        a[i]=ai ; 
        dp[i]=ai;
        mx = max(mx,ai) ; 
        if(V.empty())V.emplace_back(i);
        else if(a[V.back()]==ai&&dp[V.back()]<=ai)
        {
            int tmp =  dp[V.back()];
            V.pop_back();
            if(!V.empty())
            {
                dp[V.back()]=max(dp[V.back()],tmp);
            }
        }
        else V.push_back(i);
    }
    cout << (V.empty()||(V.size()==1&&a[V[0]]==mx)?"YES":"NO") << '\n' ;
    return 0 ;
}