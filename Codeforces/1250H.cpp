#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int inf = 1e9 ; 
int arr[10];
pii comp(pii mn,pii now)
{
    if(mn.fi!=now.fi)return min(mn,now) ;
    else if(mn.se==0)return now;
    else return mn ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        pii mn = {inf,-1};
        for(int j=0;j<=9;j++)
        {
            cin >> arr[j];
            mn = comp(mn,{arr[j],j});
        }
        if(arr[1]==0)
        {
            cout << "1" << '\n' ;
            continue ;
        }
        else if(mn.se==0)
        {
            cout << "1" ;
        }
        for(int j=1;j<=mn.fi+1;j++)cout << mn.se ;
        cout << '\n' ;
    }
    return 0 ;
}