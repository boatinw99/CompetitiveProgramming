/**
 * Lets define a different function G:
 *   G(0) = 1
 *   G(1) = A1 + A2 + ... + An
 *   G(2) = (A1 * A2 + A1 * A3 + ... + A1 * An) +
 *        + (A2 * A3 + A2 * A4 + ... + A2 * An) +
 *        + ... +
 *        + A(n - 1) * An
 * In general case, G(k) = sum of products over all subsets of size k
 *
 * Obviously, G(k) = 0 for k > n. So, the only interesting values of G
 * are G(1), G(2), ..., G(n). The interesting thing is that we can calculate
 * all these values without knowing (A1, A2, ..., An), but just given
 * F(1), F(2), ..., F(n) values:
 *   G(1) = F(1)
 *   G(2) = (G(1) * F(1) - F(2)) / 2
 *   G(3) = (G(2) * F(1) - G(1) * F(2) + F(3)) / 3
 * In general, the following identity can be proved:
 *   G(k) = (G(k - 1) * F(1) - G(k - 2) * F(2) + G(k - 3) * F(3) - ... +- F(k)) / k
 *
 * So, all the values of G() can be computed in O(n^2) time, which is fast enough.
 *
 * Now, lets see how G() is related to F(). In a similar way we have used F()
 * to compute values of G(), lets try to use G() to compute the values of F():
 *   F(x) * G(1) = F(x + 1) + sum(Ai^x * Aj with i != j)
 *               = F(x + 1) + F(x - 1) * G(2) - sum(Ai^(x - 1) * Aj * Ak with {i, j, k} being pairwise different)
 * Proceeding this way we will receive:
 *   F(x) * G(1) = F(x + 1) + F(x - 1) * G(2) - F(x - 2) * G(3) + ... +- F(x - n + 1) * G(n)
 * Or rewriting the above identity:
 *   F(x) = F(x - 1) * G(1) - F(x - 2) * G(2) + F(x - 3) * G(3) - ... +- F(x - n) * G(n)
 *
 * So, we have a reccurence of degree n and we can calculate F(x) using matrix exponentiation.
 *
 * Straightforward matrix exponentiation would result in O(q * n^3 * log X)
 * complexity, but that is too much for last two subrasks.
 *
 * For subtask #4 we can notice that multiplication of vector and matrix
 * costs just O(n^2) instead of O(n^3), so, instead of calculating M^X directly
 * we can just multiple all the M^(2^p) to our vector resulting in O(q * n^2 * log X)
 * for answering queries and O(n^3 * log X) for precomputiong all M^(2^p)
 *
 * For the last subtask we should get rid of the O(n^3 * log X) precomputation
 * We can use an idea based on a Cayley-Hamilton theorem that is nicely explained here:
 *   https://discuss.codechef.com/questions/49614
 **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 300, md = 1000000007;

// p[i] = F(i)
// e[i] = G(i)
// inv[i] = i^-1 mod (10^9 + 7)
int p[MX + 1], e[MX + 1], inv[MX + 1], a[MX], f[2 * MX];
int r[MX][MX], c[2 * MX][MX];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, q;
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; i++) scanf("%d", p + i);

		// calculation values of G(k)
		e[0] = 1;
		e[1] = p[1];
		inv[1] = 1;
		for (int i = 2; i <= n; i++) {
			inv[i] = md - (md / i) * 1ll * inv[md % i] % md;
			e[i] = 0;
			for (int j = 1, sgn = 1; j <= i; j++, sgn *= -1) {
				e[i] = (e[i] + sgn * p[j] * 1ll * e[i - j]) % md;
				if (e[i] < 0) e[i] += md;
			}

			e[i] = e[i] * 1ll * inv[i] % md;
		}

		// For M^n, M^(n + 1), ..., M^(2 * n - 2) we compute their
		// representations as linear combinations of I, M, M^2, ..., M^(n - 1)
		// M^p = I * c[p][0] + M * c[p][1] + M^2 * c[p][2] + ...
		for (int i = 0; i < n; i++) {
			if ((n - i) % 2 == 1) c[n][i] = e[n - i];
			else c[n][i] = md - e[n - i];
		}

		for (int k = n + 1; k < 2 * n; k++) {
			int g = c[k - 1][n - 1];
			for (int i = n - 1; i > 0; i--)
				c[k][i] = (c[k - 1][i - 1] + c[n][i] * 1ll * g) % md;

			c[k][0] = c[n][0] * 1ll * g % md;
		}

		// Calculating first rows of I, M, M^2, ..., M^(n - 1)
		// r[0] is a first row of I
		// r[1] is a first row of M and so on...
		r[0][0] = 1;
		for (int i = 1; i < n; i++) r[0][i] = 0;
		for (int i = 1; i < n; i++)
			for (int k = 0; k < n; k++) {
				r[i][k] = (k + 1 < n ? r[i - 1][k + 1] : 0);
				r[i][k] = (r[i][k] + r[i - 1][0] * 1ll * c[n][n - k - 1]) % md;
			}
       // for(int i=0;i<=n;i++)printf("%d ",p[i]); cout << '\n' ;
		while (q--) {
			long long X;
			scanf("%lld", &X);

			X -= n;

			// to implement binary exponentiation without a recursion
			// we need binary repsresentation of X in order from the
			// highest bit, so, store it in B
			vector<int> B;
			while (X) {
				B.push_back(X % 2);
				X /= 2;
			}

			reverse(B.begin(), B.end());

			// current power of M is represented as a linear combination
			// of I, M, M^2, ..., M^(n - 1)
			// I * a[0] + M * a[1] + M^2 * a[2] + ... + M^(n - 1) * a[n - 1]
			// as M^0 = I, the only a[i] != 0 is a[0] = 1, initially
			a[0] = 1;
			for (int i = 1; i < n; i++) a[i] = 0;

			for (int b : B) {
				// compute the square of current power
				// we just expand the (I * a[0] + M * a[1] + ...)^2
				for (int i = 0; i < 2 * n; i++) f[i] = 0;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						f[i + j] = (f[i + j] + a[i] * 1ll * a[j]) % md;

				// replace M^n, M^(n + 1), ..., M^(n - 2) by their
				// representations in the resulting expression
				for (int i = n; i < 2 * n; i++)
					for (int j = 0; j < n; j++)
						f[j] = (f[j] + f[i] * 1ll * c[i][j]) % md;

				// save the result back to a
				for (int i = 0; i < n; i++) a[i] = f[i];

				// if current bit in X is one, we should multiply current power by M
				// so, we shift all the a[i]s left and replace the M^n by its representation
				if (b) {
					int g = a[n - 1];
					for (int i = n - 1; i > 0; i--)
						a[i] = (a[i - 1] + c[n][i] * 1ll * g) % md;

					a[0] = c[n][0] * 1ll * g % md;
				}
			}

			int ans = 0;
			for (int i = 0; i < n; i++) {
				// compute M^X[0, i] using its representation
				// and precomputed first rows of I, M, ..., M^(n - 1)
				int sum = 0;
				for (int j = 0; j < n; j++)
					sum = (sum + r[j][i] * 1ll * a[j]) % md;
				// multiply initial vector by the first row of M^X
				// we receive the first element of the resulting vector
				// and it is our answer
				ans = (ans + p[n - i] * 1ll * sum) % md;
				//printf("aaaaaa %d %d\n",n-i,p[n-i]);
			}

			printf("%d ", ans);
		}

		printf("\n");
	}

	return 0;
}
