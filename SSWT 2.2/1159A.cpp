#include <bits/stdc++.h>
using namespace std;
string s ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    cin >> s ;
    int cnt = 0, mn = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '-')cnt--;
        else cnt++;
        mn = min(mn, cnt);
    }
    cout << cnt-mn ;
    return 0;
}
