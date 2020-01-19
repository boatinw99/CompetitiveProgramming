#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se seocnd
const int N = 1e5+9,inf = 2e9 ;
int n,A[N],freq[N];
multiset<int> S;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i = 1; i <= n; i++)cin >> A[i];
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(freq[A[i]])S.erase(S.find(freq[A[i]]));
        freq[A[i]]++;
        S.emplace(freq[A[i]]);
        if(S.size() == 1)ans = i;
        if(S.size() == 2)
        {
            if(*S.begin()==1)ans = i;
            if(*S.begin()+1==*S.rbegin()) ans = i;
        }
        if(*S.begin()== 1&&*next(S.begin()) == *S.rbegin())ans = i;
        if(*S.begin()+1==*S.rbegin()&&*S.begin()==*next(S.rbegin()))ans = i;
    }
    cout << ans ;
    return 0;
}
