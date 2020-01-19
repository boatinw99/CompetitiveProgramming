#include<bits/stdc++.h>
using namespace std ;
const int M = 1<<24 , bit = 24 ;
int F[M]; 
void update(int mask)
{
    ///xyz...cba
    vector<int> V ;
    for(int i=0;i<bit;i++)
    {
        if(mask&(1<<i))V.emplace_back(1<<i);
    }
    for(auto it:V)F[it]++;
    for(int i=0;i<V.size();i++)
    {
        for(int j=i+1;j<V.size();j++)F[V[i]+V[j]]--;
    }
    if(V.size()==3)F[mask]++;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        string s ;
        cin >> s ;
        int mask = 0 ;
        for(int i=0;i<3;i++)
        {
            mask|=1<<(s[i]-'a');
        }
        update(mask);
    }
    for(int i=0;i<bit;i++)
    {
        for(int mask=0;mask<M;mask++)
        {
            if(mask&(1<<i))F[mask]+=F[mask^(1<<i)];
        }
    }
    int ans = 0 ;
    for(int i=0;i<M;i++)
    {
        ans^=F[i]*F[i];
    }
    cout << ans << '\n' ;
    return 0 ;
}