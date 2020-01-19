#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const int N = 1e3+5;
int n;
vector<pii> p;
set<pair<double, double> > S;
map<double, int> mp;
int bad(pii a, pii b, pii c) {
	pii vec1(b.x - a.x, b.y - a.y), vec2(c.x- a.x, c.y - a.y);
	if(vec1.x * vec2.y - vec1.y * vec2.x < 0) return 1;
	else if(vec1.x * vec2.y - vec1.y * vec2.x == 0) return 0;
	return 2;
}
double d(pii a, pii b) {
	long p2 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return sqrt(p2);
}
int main()
{
    scanf("%d", &n);
    for(int i = 1, a, b; i <= n; i++) {
        scanf("%d %d", &a, &b);
        p.emplace_back(a, b);
    }
    for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) {
        pii x = p[i], y = p[j];
        double m = x.x != y.x ? (double)(x.y - y.y) / (double)(x.x - y.x) : 1e9;
        double c = m != 1e9 ? (double)x.y - m * x.x : x.x;
        S.emplace(m, c);
    }
    bad({1,2},{2,3},{4,6});
    long ans = 1ll * (int)S.size() * ((int)S.size() - 1) / 2;
    for(auto it : S) ++mp[it.x];
    bad({1,2},{2,3},{4,6});
    for(auto it : mp) ans -= 1ll * it.y * (it.y - 1) / 2;
    printf("%lld\n", ans);
    bad({1,5},{7,3},{0,6});
    return 0;
}
