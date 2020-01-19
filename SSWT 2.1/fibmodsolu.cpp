#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define mp make_pair

typedef long long int ll;

const ll INF = 4e18;

int MOD;
int sub(int x, int y) {
    x -= y; if (x < 0) x += MOD;
    return x;
}

ll h(int x, int y) { return ll(x)*1e9 + y; }

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int a,b; cin >> MOD >> a >> b;
        int k = int(sqrt(6LL*MOD)+3);

        ll x = 0, y = 1, z = 1;
        forn(_,k-1) {
            x = y;
            y = z;
            z = x+y; if (z >= MOD) z -= MOD;
        }
        unordered_map<ll,int> small;
        forn(i,k) {
            auto hh = h(a,b);
            //printf("aa %d %d %lld |a=%d b=%d\n",i,k,hh,a,b);
            if (!small.count(hh)) small[hh] = i;
            tie(a,b) = mp(sub(b,a), a);
        }

        ll ans = INF;
        int c = 0, d = 1;
        forn(i,k) {
            auto hh = h(c,d);
            if (small.count(hh)) {
                ans = ll(k)*i + small[hh];
                printf("b %d %d %lld |a=%d b=%d %lld\n",i,k,hh,c,d,
                       small[hh]);
                break;
            }
            tie(c,d) = mp((x*c + y*d)%MOD, (y*c + z*d)%MOD);
        }
        if (ans == INF) ans = -1;
        cout << ans << endl;
    }

    return 0;
}

