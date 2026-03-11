# define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;

typedef long long ll;

// Defines
#define ss second
#define ff first
#define all(X) X.begin(), X.end()
#define rall(X) X.rbegin(), X.rend()
#define cinall(X) for (auto &i : X) cin >> i
#define printall(X) for (auto &i : X) cout << i << " "
#define printFromTo(cont, i, j, ch) for (int _ = i; _ <= j; _++) cout << cont[_] << ch
#define cinFromTo(cont, i, j) for (int _ = i; _ <= j; _++) cin >> cont[_]
#define fillFromTo(cont, i, j, x) for (int _ = i; _ <= j; _++) cont[_] = x;
#define pb push_back

#define MAKE_UNIQUE_KEEP_ORDER(vec) do { \
	unordered_set<decltype((vec).front())> seen; \
	(vec).erase(remove_if((vec).begin(), (vec).end(), [&](auto &val) { \
		if (seen.count(val)) return true; \
		seen.insert(val); \
		return false; \
	}), (vec).end()); \
} while(0)

#define UNIQUE_SORT(vec) do { \
	sort((vec).begin(), (vec).end()); \
	(vec).erase(unique((vec).begin(), (vec).end()), (vec).end()); \
} while(0)

#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) (lower_bound((c).begin(), (c).end(), (x)) &mdash; (c).begin())
#define UB(c, x) (upper_bound((c).begin(), (c).end(), (x)) &mdash; (c).begin())

// Constants
const int N = 1e6 + 5;
const int LOG = 30;
const long long INFLL = 1e18;
const int INF = 1e9;
const long double epsilon = 0.000001;
const long long mod = 1e9 + 7;

constexpr ll TEN[] = {
	1LL,10LL,100LL,1000LL,10000LL,100000LL,1000000LL,10000000LL,
	100000000LL,1000000000LL,10000000000LL,100000000000LL,1000000000000LL,
	10000000000000LL,100000000000000LL,1000000000000000LL,10000000000000000LL,
	100000000000000000LL,1000000000000000000LL,
};

// Modular Arithmetics
long long binPowByMod(long long x, long long power, long long modx) {
	long long res = 1;
	long long base = x % modx;
	while (power > 0) {
		if (power & 1) res = (res * base) % modx;
		base = (base * base) % modx;
		power >>= 1;
	}
	return res;
}

inline long long add(long long a, long long b)
{
	if (a + b > mod)
		return a + b - mod;
	else
		return a + b;
}

inline long long sub(long long a, long long b)
{
	if (a - b < 0)
		return a - b + mod;
	else
		return a - b;
}

inline long long mult(long long a, long long b)
{
	return (a * b) % mod;
}

inline long long divid(long long p, long long q)
{
	long long ans = p;
	ans %= mod;
	ans = mult(ans, binPowByMod(q, mod - 2, mod));
	return ans;
}

// Math Helpers
ll gcdll(ll a, ll b) { return b == 0 ? a : gcdll(b, a % b); }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }
ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }

bool isPrime(ll x) {
	if (x < 2) return false;
	for (ll i = 2; i * i <= x; ++i)
		if (x % i == 0) return false;
	return true;
}

// Set IO for Usaco
void set_IO(string str = "")
{
	if (!str.empty()) {
		freopen((str + ".in").c_str(), "r", stdin);
		freopen((str + ".out").c_str(), "w", stdout);
	}
}

// Base type printers
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << '"' << t << '"'; }
void _print(char t) { cerr << '\'' << t << '\''; }
void _print(double t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(bool t) { cerr << (t ? "true" : "false"); }

// STL containers
template<class T> void _print(vector<T> v) { cerr << "["; for (auto& i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, size_t N> void _print(array<T, N> a) { cerr << "["; for (auto& i : a) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(set<T> v) { cerr << "{"; for (auto& i : v) { _print(i); cerr << " "; } cerr << "}"; }
template<class T> void _print(multiset<T> v) { cerr << "{"; for (auto& i : v) { _print(i); cerr << " "; } cerr << "}"; }
template<class T> void _print(unordered_set<T> v) { cerr << "{"; for (auto& i : v) { _print(i); cerr << " "; } cerr << "}"; }
template<class T, class V> void _print(map<T, V> v) { cerr << "{"; for (auto& i : v) { _print(i.first); cerr << ":"; _print(i.second); cerr << " "; } cerr << "}"; }
template<class T, class V> void _print(unordered_map<T, V> v) { cerr << "{"; for (auto& i : v) { _print(i.first); cerr << ":"; _print(i.second); cerr << " "; } cerr << "}"; }
template<class T, class V> void _print(pair<T, V> p) { cerr << "("; _print(p.first); cerr << ", "; _print(p.second); cerr << ")"; }

void solve()
{

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
		cout << endl;
	}
	return 0;
}
