#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<int,int> pii ;
#define fi first 
#define se second 
const int N = 1e5+9 , mod = 1e9+7 ; 
int main()
{
  ios::sync_with_stdio(false),cin.tie(0);
  int t ;
  cin >> t ;
  while(t--)
  {
    int good = 0 ,n ;
    queue<int> st ; 
    cin >> n ;
    for(int i=1;i<=n;i++){
      int x ; 
      cin >> x ;
      if((x&1)&&(good==0)){
        st.push(i);
        good = 2 ;
      } 
      else if((x&1)&&(good==2)){
        st.push(i);
        good = 1 ;
      }
      else if(good==0)
      {
        st.push(i);
        good = 1 ;
      }
      else if(good==2){
        st.pop();
        st.push(i);
        good = 1 ;
      }
    }
    if(good==1){
      cout << st.size() << '\n' ;
      while(!st.empty()){
        cout << st.front() << " " ;
        st.pop();
      }
    }
    else {
      cout << "-1" ;
    }
    cout << '\n' ; 
  }
  return 0 ;
}