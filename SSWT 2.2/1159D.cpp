#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ,inf = 1e9+7 ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k;
    cin >> n >> k ;
    int dif = (n-k)/2;
    int md = dif+1;
    int j = 0 ;
    while(n--)
    {
        if(j%md==dif)cout << "1";
        else cout << "0" ;
        j++;
    }
    return 0;
}
