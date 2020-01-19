#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 10, INF = 1e9, M = 998244353;

int kol[MAXN];

int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1) {
        int res = (binpow (a, n - 1) * a);
        if (res > M) res %= M;
		return res;
	}
	else {
		int b = (binpow (a, n / 2)) % M;
		int res = b * b;
		if (res > M) res %= M;
		return res;
	}
}

signed main()
{
    // freopen ("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int sza = a.size(), szb = b.size();
    if (sza > szb) {
        for (int i = 0; i < (sza - szb); i++) {
            b = "0" + b;
        }
    }
    if (szb  > sza) {
        for (int i = 0; i < (szb - sza); i++) {
            a = "0" + a;
        }
    }
    sza = a.size();
    szb = b.size();
    for (int i = 0; i < b.size(); i++) {
        kol[i] += b[i] - '0';
        if (i) kol[i] += kol[i - 1];
    }
    int ans(0);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] - '0') {
            ans += (binpow(2, a.size() - (i + 1)) * kol[i]) % M;

            if (ans > M) ans %= M;
        }
    }
    cout << ans;
    return 0;
}
