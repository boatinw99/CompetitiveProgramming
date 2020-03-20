/* 
    DATE 20-03-20 
    START 17:44 
    END 19:14 
    DURTION : 1.5 hour 
    (practicing VIM)
*/
#include<bits/stdc++.h>
using namespace std ;
const int N = 5e3+9 , mod = 1e9+7 ;
int val[N][N],s[N],mx[N],cnta[N],cntb[N],sum[N][N];
int n,m ; 
int comp() {
    int ret = 0 ; 
    for(int i=1;i<=n;i++) {
        int numa = sum[i][cnta[i]],numb = sum[i][cntb[i]];
        if((numa>1&&numb>0)||(numb>1&&numa>0)) {
            ret+=2;
        }
        else if(numa>0||numb>0)ret++;
    }
    return ret ;  
}
int getposs(int x) {
    long long ret = 1 ;
    for(int i=1;i<=n;i++) {
        int numa = sum[i][cnta[i]],numb = sum[i][cntb[i]];
        if(i!=x) {
            if((numa>1&&numb>0)||(numb>1&&numa>0)) {
                ret *= (max(numa,1)*max(numb,1)-min(numa,numb)) ; 
                ret%=mod ;
            }
            else if(numa>0||numb>0) {
                ret *= numa+numb ;
                ret%=mod ;
            }
        }
        else {
            if(cnta[i]<=cntb[i]) {
                ret *= (val[i][cnta[i]])*max((numb-1),1);
                ret%=mod ;
            }
            else {
                ret *= (val[i][cnta[i]])*(max(numb,1)); 
                ret%=mod ;
            }
        }
        // printf("checkret %lld \n",ret);
    }
    return ret ; 
}
int main() { 
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=n;i++) {
        cin >> s[i] ; 
    }
    for(int i=1,f,h ;i<=m;i++) {
        cin >> f >> h ; 
        val[f][h]++ ;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            sum[i][j]=sum[i][j-1]+val[i][j];
        }
    }
    int ans = 0 ;
    for(int i=0;i<=n;i++) {
        cnta[s[i]]++;
        for(int j=i+1;j<=n;j++) {
            cntb[s[j]]++;
        }
        mx[i] = comp();
        ans = max(ans,mx[i]);
        memset(cntb,0,sizeof cntb);
    }
    memset(cnta,0,sizeof cnta);
    memset(cntb,0,sizeof cntb);
    int poss = 0 ; 
    bool fst = 0 ; 
    for(int i=0;i<=n;i++) {
        cnta[s[i]]++;
        for(int j=i+1;j<=n;j++) {
            cntb[s[j]]++;
        }
        if(mx[i]==ans&&!fst) {
            fst++;
            poss += getposs(0);
            poss%=mod ;
            // printf("what %d i =%d\n",poss,i);
        }
        else if(mx[i]==ans&&fst) {
            poss += getposs(s[i]);
            // printf("what %d\n",getposs(s[i]));
            poss%=mod ; 
        }
        memset(cntb,0,sizeof cntb);
    }
    cout << ans << " " << poss << '\n' ;
    return 0 ;
}
