#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<int,int> pii ;
#define fi first 
#define se second 
const int N = 5e4+4 , mod = 1e9+7 ; 
int n,m,bita,bitb ;
int k ; 
int a[N],b[N];
ll conb[N],cona[N];
ll ans = 0 ;
int main()
{
  ios::sync_with_stdio(false),cin.tie(0);
  cin >> n >> m >> k ; 
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int i=1;i<=m;i++){
    cin >> b[i];
  }
  for(int i=1,cnt = 0;i<=m+1;i++){
    bitb = b[i];
    if(bitb==1){
      cnt++;
    }
    else {
      conb[cnt]++;
      cnt=0;
    }
  }
  for(int i=1,cnt=0;i<=n+1;i++){
    bita=a[i];
    if(bita==1){
      cnt++;
    }
    else {
      cona[cnt]++;
      cnt=0;
    }
  }
  ll val = 0 , num = 0 ; 
  for(int i=n;i>=1;i--){
    num+=cona[i];
    ll tmp = cona[i];
    cona[i]+=val ;
    val+=tmp+num ; 
  }
  val = 0 , num = 0 ;
  for(int i=m;i>=1;i--){
    num+=conb[i];
    ll tmp = conb[i];
    conb[i]+=val ;
    val+=tmp+num ; 
  }
  for(int i=1;i<=max(n,m);i++){
    if(k%i==0){
      int len = k/i ;
      if(len<=max(n,m)) ans+=1ll*cona[i]*conb[len];
    }
  }
  cout << ans << '\n' ;
  return 0 ;
}
