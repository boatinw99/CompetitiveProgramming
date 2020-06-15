#include<bits/stdc++.h>
using namespace std ;
const int N = 1e7+9;
vector<int> V[N];
int arr[N];
void init() {
    for(int i=2;i<N;i++) {
        if(V[i].empty()) {
            for(int j=i+i;j<N;j+=i) {
                if(V[j].size()<2)V[j].push_back(i);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++) {
        cin >> arr[i] ;
    }
    for(int i=1;i<=n;i++) {
        int x = arr[i];
        if(V[x].size()==2) {
            cout << V[x][0] << " " ;
        }
        else cout << "-1" << " " ;
    }
    cout << '\n' ; 
    for(int i=1;i<=n;i++) {
        int x = arr[i]; 
        if(V[x].size()==2) {
            cout << V[x][1] << " " ;
        }
        else cout << "-1" << " " ;
    }
    cout << '\n' ; 
    return 0 ; 
}