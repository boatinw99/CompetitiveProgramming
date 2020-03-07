#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<int,int> pii ;
#define fi first 
#define se second 
const int N = 1e6+9 , mod = 1e9+7 ; 
stack<int> st ;
char s[N];
int main()
{
  ios::sync_with_stdio(false),cin.tie(0);
  int n,ans = 0 ;
  cin >> n ;
  for(int i=1;i<=n;i++){
    cin >> s[i] ;
    if(st.empty()){
      st.push(i);
    }
    else if(s[st.top()]==s[i]){
      st.push(i);
    }
    else {
      int x = st.top();
      st.pop();
      if(st.empty()&&s[x]==')'){
        ans+=i-x+1;
      }
    }
  }
  if(!st.empty()){
    cout << "-1" << '\n' ;
    return 0 ;
  }
  cout << ans << '\n' ;
  return 0 ;
}