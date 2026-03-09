#include <bits/stdc++.h>
using namespace std;

/* -------------------- Basic types & short helpers -------------------- */
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

// Fast IO
struct FastIO {
    FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.setf(std::ios::fixed); cout.precision(12); }
} fastio;

/* -------------------- Debug (compile with -DLOCAL) -------------------- */
#ifdef LOCAL
    #define dbg(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
    template<typename T>
    void err_print(const T& x) { cerr << x; }
    void err_print(const string& s) { cerr << '"' << s << '"'; }
    template<typename A, typename B>
    void err_print(const pair<A,B>& p) { cerr << '{'; err_print(p.first); cerr << ','; err_print(p.second); cerr << '}'; }
    template<typename T>
    void err_print(const vector<T>& v) { cerr << '['; bool first=true; for(auto &x:v){ if(!first) cerr<<','; err_print(x); first=false;} cerr << ']'; }
    template<typename T>
    void err_print(const set<T>& s) { cerr << '{'; bool first=true; for(auto &x:s){ if(!first) cerr<<','; err_print(x); first=false;} cerr << '}'; }
    template<typename K, typename V>
    void err_print(const map<K,V>& m) { cerr << '{'; bool first=true; for(auto &kv:m){ if(!first) cerr<<','; err_print(kv); first=false;} cerr << '}'; }

    template<typename ...Args>
    void debug_out(const char *names, Args&&... args) {
        cerr << "[" << names << "] = ";
        (err_print(args), ..., cerr);
        cerr << '\n';
    }
#else
    #define dbg(...) (void)0
#endif

/* -------------------- MEDIUM Print Utilities -------------------- */
template<typename T>
void print_one(const T& x) { cout << x; }
void print_one(const string& s) { cout << s; }

template<typename A, typename B>
void print_one(const pair<A,B>& p) {
    print_one(p.first); cout << ' '; print_one(p.second);
}

template<typename T>
void print_one(const vector<T>& v) {
    if(v.empty()) return;
    print_one(v[0]);
    for (int i = 1; i < sz(v); ++i) { cout << ' '; print_one(v[i]); }
}

template<typename T>
void print_one(const set<T>& s) {
    bool first = true;
    for (auto &x : s) {
        if (!first) cout << ' ';
        print_one(x);
        first = false;
    }
}

template<typename K, typename V>
void print_one(const map<K,V>& m) {
    bool first = true;
    for (auto &kv : m) {
        if (!first) cout << ' ';
        print_one(kv);
        first = false;
    }
}

template<typename ...Args>
void out(Args&&... args) {
    ((print_one(forward<Args>(args)), cout << ' '), ...);
    cout << '\n';
}

/* -------------------- Common Math Utilities -------------------- */
ll gcdll(ll a, ll b) { while (b) { ll r = a % b; a = b; b = r; } return a; }
ll lcmll(ll a, ll b) { if (a==0||b==0) return 0; return a / gcdll(a,b) * b; }
ll mod_pow(ll a, ll e, ll mod) {
    a %= mod;
    ll r = 1;
    while (e) {
        if (e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}

/* -------------------- modint (mod = 1e9+7) -------------------- */
static constexpr ll MOD = 1000000007LL;
struct Mint {
    ll v;
    Mint(ll _v = 0) { v = _v % MOD; if (v < 0) v += MOD; }
    Mint operator+(const Mint& o) const { return Mint(v + o.v); }
    Mint operator-(const Mint& o) const { return Mint(v - o.v); }
    Mint operator*(const Mint& o) const { return Mint(v * o.v % MOD); }
    Mint& operator+=(const Mint& o){ v+=o.v; if(v>=MOD) v-=MOD; return *this; }
    Mint& operator-=(const Mint& o){ v-=o.v; if(v<0) v+=MOD; return *this; }
    Mint& operator*=(const Mint& o){ v = v*o.v%MOD; return *this; }
    Mint pow(ll e) const { return Mint(mod_pow(v, e, MOD)); }
    Mint inv() const { return pow(MOD-2); }
    Mint operator/(const Mint& o) const { return *this * o.inv(); }
    friend ostream& operator<<(ostream& os, const Mint& m){ return os << m.v; }
};

/* -------------------- Disjoint Set Union (Union-Find) -------------------- */
struct DSU {
    int n;
    vector<int> p, r, sz;
    DSU() : n(0) {}
    DSU(int n_) { init(n_); }
    void init(int n_) {
        n = n_;
        p.resize(n); r.assign(n, 0); sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
        if (r[a] == r[b]) r[a]++;
        return true;
    }
    bool same(int a, int b) { return find(a) == find(b); }
    int size(int a) { return sz[find(a)]; }
};

/* -------------------- Graph: BFS, DFS, Dijkstra -------------------- */
struct WeightedEdge { int to; ll w; };
using WAdj = vector<vector<WeightedEdge>>;
using Adj = vector<vector<int>>;

vector<int> bfs(const Adj& g, int s) {
    int n = sz(g);
    vector<int> dist(n, -1);
    deque<int> dq;
    dq.push_back(s); dist[s]=0;
    while(!dq.empty()){
        int u = dq.front(); dq.pop_front();
        for (int v : g[u]) if (dist[v] == -1) { dist[v] = dist[u] + 1; dq.push_back(v); }
    }
    return dist;
}

void dfs_rec(const Adj& g, int u, vector<int>& vis, vector<int>& order) {
    vis[u] = 1;
    for (int v : g[u]) if (!vis[v]) dfs_rec(g, v, vis, order);
    order.pb(u);
}

// Dijkstra with 0-indexed vertices, returns dist vector (INF = LLONG_MAX/4)
vector<ll> dijkstra(int n, const vector<vector<pair<int,ll>>>& g, int src) {
    const ll INF = (ll)4e18;
    vector<ll> dist(n, INF);
    dist[src] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.emplace(0, src);
    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &e : g[u]) {
            int v = e.first; ll w = e.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

/* -------------------- KMP (prefix function) -------------------- */
vector<int> prefix_function(const string& s) {
    int n = sz(s);
    vector<int> pi(n,0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp_search(const string& pattern, const string& text) {
    string concat = pattern + '#' + text;
    auto pi = prefix_function(concat);
    vector<int> matches;
    int p = sz(pattern);
    for (int i = p+1; i < sz(concat); ++i) {
        if (pi[i] == p) matches.pb(i - 2*p);
    }
    return matches;
}

/* -------------------- Small helpers often used in contests -------------------- */
template<typename T>
T clamp_val(T x, T lo, T hi) { return x < lo ? lo : (x > hi ? hi : x); }

template<typename It>
vector<typename iterator_traits<It>::value_type> slice(It l, It r) {
    return vector<typename iterator_traits<It>::value_type>(l, r);
}

/* -------------------- Template control and solve skeleton -------------------- */
void prepare_for_tests() {
    // Any precomputation can go here (sieve, factorials, etc.)
    // Keep this minimal for ICPC prelim speed.
}

void solve_case() {
    // Example skeleton: read input and demonstrate utilities
    // Replace with problem-specific code in contest.
    int n;
    if (!(cin >> n)) return;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Example: use DSU quickly
    DSU dsu(n);
    // unify indexes example (not meaningful here)
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) dsu.unite(i, i-1);
    }
    // print sizes of each component representative
    map<int, vector<int>> comps;
    for (int i = 0; i < n; ++i) comps[dsu.find(i)].pb(i);
    for (auto &kv : comps) {
        cout << "comp rep " << kv.first << ": ";
        print_one(kv.second);
        cout << '\n';
    }
}

/* -------------------- Main: test runner -------------------- */
int main() {
    prepare_for_tests();
    int T = 1;
    if (!(cin >> ws)) return 0;
    // If the input starts with an integer test count, uncomment:
    // cin >> T;
    // Typical ICPC prelim: often single test file with multiple cases or custom judge.
    // We'll detect if there is more input and run solve_case until EOF if no T given.
    // Here we use a flexible approach: if first token parsed into T and next char is newline
    // you may use Test style; to keep it simple in team environment, we ask to run as:
    // First line either number of tests or start of first test.
    string first;
    if (!(cin >> first)) return 0;
    // if first is integer and more input, treat as T
    bool first_is_number = true;
    for (char c : first) if (!isdigit(c) && c!='-') first_is_number = false;
    if (first_is_number) {
        // it's T; parse and run that many cases
        T = stoi(first);
        for (int tc = 0; tc < T; ++tc) {
            solve_case();
            // separate outputs if needed
        }
    } else {
        // first token was part of first case: push it back into stream and run until EOF
        // easy approach: use stringstream to feed first token back
        // but simplest: handle this specific template by reading rest of file with first token processed manually
        // We'll implement a wrapper that uses a simple workflow: create a string that contains the first token and the rest of cin
        string rest;
        string t;
        vector<string> tokens;
        tokens.pb(first);
        while (cin >> t) tokens.pb(t);
        // Place tokens into a stringstream to simulate standard input for solve_case
        stringstream ss;
        for (auto &tok : tokens) ss << tok << ' ';
        // swap cin buffer
        auto backup = cin.rdbuf(ss.rdbuf());
        // run single solve loop until EOF
        while (!cin.eof()) {
            solve_case();
        }
        cin.rdbuf(backup);
    }
    return 0;
}
