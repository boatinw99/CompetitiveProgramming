#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ; 
int arr1[N],arr2[N];
vector<int> V1,V2 ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)cin >> arr1[i];
    for(int i=1;i<=n;i++)cin >> arr2[i];
    for(int i=1;i<n;i++)V1.push_back(arr1[i+1]-arr1[i]);
    for(int i=1;i<n;i++)V2.push_back(arr2[i+1]-arr2[i]);
    if(arr1[1]!=arr2[1])
    {
        cout << "No" << '\n' ;
        return 0 ;
    }
    sort(V1.begin(),V1.end());
    sort(V2.begin(),V2.end());
    for(int i=0;i<(int)V1.size();i++)
    {
        if(V1[i]!=V2[i])
        {
            cout << "No" << '\n' ;
            return 0 ;
        }
    }
    cout << "Yes" << '\n' ;
    return 0 ;
}