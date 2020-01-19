#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1000000000 + 7;
const int MAXN = 600 + 10;

int n, m;
int f[MAXN], g[MAXN], F[MAXN], r[MAXN];
int b[MAXN][MAXN], c[MAXN][MAXN];
long long a[MAXN];

int inverse (int k) {
    int cp = k, ret = 1;
    for(int i = 0; (1 << i) <= MOD - 2; i++) {
        if ((MOD - 2) & (1 << i)) {
            ret = ret * 1LL * cp % MOD;
        }
        cp = cp * 1LL * cp % MOD;
    }
    return ret;
}

int main(int argc, const char * argv[]) {

    int tn;
    cin >> tn;

    while (tn--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            cin >> F[i];
        for(int i = 1; i <= m; i++)
            cin >> a[i];

        g[0] = 1;
        g[1] = F[1];
        for(int i = 2; i <= n; i++) {
            g[i] = 0;
            for(int j = 1; j <= i; j++) {
                long long q = F[j] * 1LL * g[i - j] % MOD;
                if (j % 2 == 0)
                    q = MOD - q % MOD;
                g[i] = (g[i] + q) % MOD;
            }
            g[i] = g[i] * 1LL * inverse(i) % MOD;
        }

        for(int i = 1; i <= n; i++) {
            b[n + 1][i] = g[n - i + 1];
            if ((n - i) % 2 == 1)
                b[n + 1][i] = MOD - b[n + 1][i];
        }

        for(int i = n + 2; i <= n + n; i++) {
            int q = b[i - 1][n];
            for(int j = n; j > 1; j--)
                b[i][j] = (b[i - 1][j - 1] + b[n + 1][j] * 1LL * q) % MOD;
            b[i][1] = b[n + 1][1] * 1LL * q % MOD;
        }

        c[1][1] = 1;
        for(int i = 2; i <= n; i++)
            c[1][i] = 0;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if (j + 1 <= n)
                    c[i][j] = c[i - 1][j + 1];
                else
                    c[i][j] = 0;
                c[i][j] = (c[i][j] + c[i - 1][1] * 1LL * b[n + 1][n - j + 1]) % MOD;
            }
        }

        for(int ttn = 1; ttn <= m; ttn++) {
            long long ai = a[ttn];
            ai -= n;

            r[1] = 1;
            for(int i = 2; i <= n; i++)
                r[i] = 0;

            for(int i = 60; i >= 0; i--)
                if ((1LL << (long long)i) <= ai) {

                    for(int j = 1; j <= n + n; j++)
                        f[j] = 0;

                    for(int j = 1; j <= n; j++)
                        for(int k = 1; k <= n; k++)
                            f[j + k - 1] = (f[j + k - 1] + r[j] * 1LL * r[k]) % MOD;

                    for(int j = n + 1; j <= n + n; j++)
                        for(int k = 1; k <= n; k++)
                            f[k] = (f[k] + f[j] * 1LL * b[j][k]) % MOD;

                    for(int j = 1; j <= n; j++)
                        r[j] = f[j];

                    if (ai & (1LL << (long long)i)) {
                        int q = r[n];
                        for(int j = n; j >= 1; j--)
                            r[j] = (r[j - 1] + b[n + 1][j] * 1LL * q) % MOD;
                        r[1] = b[n + 1][1] * 1LL * q % MOD;
                    }

                }

            int ret = 0;
            for(int i = 1; i <= n; i++) {
                int sum = 0;
                for(int j = 1; j <= n; j++)
                    sum = (sum + c[j][i] * 1LL * r[j]) % MOD;
                ret = (ret + F[n - i + 1] * 1LL * sum) % MOD;
            }

            cout << ret << " ";

        }

        cout << endl;

    }

    return 0;
}
