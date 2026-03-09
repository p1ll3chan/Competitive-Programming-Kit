#include <bits/stdc++.h>
using namespace std;

// -------------------- Macros --------------------
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define PRINT_FLUSH(x) print(x); flush()

// Loops
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define repr(i,a,b) for(int i = (a); i >= (b); i--)

// Fast IO
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

// YES/NO
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define YESNO(x) cout << ((x) ? "YES\n" : "NO\n")

// Buffered print
string __out_buf;
#define print(x) (__out_buf += to_string(x) + "\n")
#define flush() (cout << __out_buf, __out_buf.clear())

// Debug (Off by default)
#ifdef DEBUG
    #define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
    #define dbg(x)
#endif

// -------------------- Utility Functions --------------------

// Sum of 1..n
ll sumN(int n) { return 1LL * n * (n + 1) / 2; }

// Check power of 2
bool power_2(int n) { return n && !(n & (n - 1)); }

// GCD
int gcd(int a, int b) {
    while (b) { int r = a % b; a = b; b = r; }
    return a;
}

// Prefix sum
//vector<int> prefixSum(const vector<int>& v) {
//    int n = sz(v);
//    vector<int> ps(n);
//    ps[0] = v[0];
//    rep(i,1,n) ps[i] = ps[i - 1] + v[i];
//    return ps;
//}

// Count digit frequency of a number
void countDigits(int n, vector<int>& cnt) {
    while (n > 0) cnt[n % 10]++, n /= 10;
}

// Find MEX
int findMEX(const vector<int>& v) {
    unordered_set<int> st;
    for (int x : v) if (x >= 0) st.insert(x);
    int mex = 0;
    while (st.count(mex)) mex++;
    return mex;
}

// Most frequent element
int mostFrequentElement(vector<int>& v) {
    unordered_map<int,int> f;
    for (int x : v) f[x]++;
    int mx = 0, ans = v[0];
    for (auto &p : f) if (p.second > mx) mx = p.second, ans = p.first;
    return ans;
}

// Check if all elements equal
bool allEqual(const vector<int>& v) {
    rep(i,1,sz(v)) if (v[i] != v[0]) return false;
    return true;
}
// ------------------- UTILITY FUNCTIONS -----------

/* -------------------------- STL QUICK UTILS (ICPC M) ------------------------- */
/* Uses your macros: ll, all(), sz(), pb, vi, pii, fastio(), etc.             */
/* Paste below your macros & above solve() or wherever you keep helpers.       */

//
// VECTOR helpers (templates where appropriate)
//

// remove duplicates from sorted vector (in-place)
template<typename T>
void uniq_sorted(vector<T>& v) {
    if (v.empty()) return;
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// remove duplicates for unsorted vector (keeps no particular order)
template<typename T>
void uniq(vector<T>& v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// check existence in (sorted) vector using binary_search
template<typename T>
bool exists_sorted(const vector<T>& v, const T &x) {
    return binary_search(all(v), x);
}

// remove all occurrences of val (uses remove-erase idiom)
template<typename T>
void erase_value(vector<T>& v, const T &val) {
    v.erase(remove(all(v), val), v.end());
}

// merge two vectors (no sorting)
template<typename T>
vector<T> merge_append(const vector<T>& a, const vector<T>& b) {
    vector<T> c = a;
    c.insert(c.end(), all(b));
    return c;
}

// merge two sorted vectors into one sorted vector
template<typename T>
vector<T> merge_sorted(const vector<T>& a, const vector<T>& b) {
    vector<T> c; c.reserve(a.size()+b.size());
    std::merge(all(a), all(b), back_inserter(c));
    return c;
}

// get index of first element > x (upper_bound index)
template<typename T>
int upper_idx(const vector<T>& v, const T &x) {
    return (int)(upper_bound(all(v), x) - v.begin());
}

// get index of first element >= x (lower_bound index)
template<typename T>
int lower_idx(const vector<T>& v, const T &x) {
    return (int)(lower_bound(all(v), x) - v.begin());
}

// prefix sums (int version exists above; template variant)
template<typename T>
vector<T> prefix_sum_t(const vector<T>& v) {
    int n = v.size();
    vector<T> ps(n);
    if (n == 0) return ps;
    ps[0] = v[0];
    for (int i = 1; i < n; ++i) ps[i] = ps[i-1] + v[i];
    return ps;
}

//
// SET helpers
//

// check contains
template<typename T>
bool set_contains(const set<T>& s, const T &x) {
    return s.find(x) != s.end();
}

// get iterator to first >= x (lower_bound)
template<typename T>
typename set<T>::iterator set_lower(set<T>& s, const T &x) {
    return s.lower_bound(x);
}

// get previous element (if exists) from iterator
template<typename T>
bool set_prev_val(const set<T>& s, const T &x, T &out) {
    auto it = s.lower_bound(x);
    if (it == s.begin()) return false;
    --it;
    out = *it;
    return true;
}

// safe erase if exists
template<typename T>
void set_erase_if(set<T>& s, const T &x) {
    auto it = s.find(x);
    if (it != s.end()) s.erase(it);
}

//
// UNORDERED_SET helpers
//

template<typename T>
bool uset_contains(const unordered_set<T>& us, const T &x) {
    return us.find(x) != us.end();
}

// build unordered_set from vector
template<typename T>
unordered_set<T> make_uset(const vector<T>& v) {
    unordered_set<T> us;
    for (auto &x : v) us.insert(x);
    return us;
}

//
// MAP helpers (ordered)
//

// increment frequency (or add default)
template<typename K, typename V>
void map_inc(map<K,V> &m, const K &k, V delta = 1) {
    m[k] += delta;
}

// get value with default (does not insert)
template<typename K, typename V>
V map_get(const map<K,V> &m, const K &k, V def = 0) {
    auto it = m.find(k);
    if (it == m.end()) return def;
    return it->second;
}

// erase key if value becomes zero (useful for freq maps)
template<typename K, typename V>
void map_erase_if_zero(map<K,V> &m, const K &k) {
    auto it = m.find(k);
    if (it != m.end() && it->second == 0) m.erase(it);
}

//
// UNORDERED_MAP helpers (fast freq maps)
//

// build freq map from vector (unordered)
template<typename T>
unordered_map<T,int> freq_unordered(const vector<T>& v) {
    unordered_map<T,int> mp;
    for (auto &x : v) mp[x]++;
    return mp;
}

// most frequent element (returns pair<val,count>)
template<typename T>
pair<T,int> most_frequent_unordered(const vector<T>& v) {
    unordered_map<T,int> mp = freq_unordered(v);
    T best = T();
    int bestc = -1;
    for (auto &kv : mp) {
        if (kv.second > bestc) { bestc = kv.second; best = kv.first; }
    }
    return {best, bestc};
}

// safe get (does not create entry)
template<typename K, typename V>
V umap_get(const unordered_map<K,V> &m, const K &k, V def = 0) {
    auto it = m.find(k);
    if (it == m.end()) return def;
    return it->second;
}

// increment in unordered_map
template<typename K, typename V>
void umap_inc(unordered_map<K,V> &m, const K &k, V delta = 1) {
    m[k] += delta;
}

//
// STRING helpers (CP-focused)
//

// check prefix/suffix
bool starts_with(const string &s, const string &pref) {
    if (pref.size() > s.size()) return false;
    return s.compare(0, pref.size(), pref) == 0;
}
bool ends_with(const string &s, const string &suf) {
    if (suf.size() > s.size()) return false;
    return s.compare(s.size()-suf.size(), suf.size(), suf) == 0;
}

// split by single char (fast)
vector<string> split_char(const string &s, char delim) {
    vector<string> parts;
    string cur;
    for (char c : s) {
        if (c == delim) {
            parts.pb(cur);
            cur.clear();
        } else cur.pb(c);
    }
    parts.pb(cur);
    return parts;
}

// find all occurrences of pattern in text (returns starting indices)
vector<int> find_all(const string &text, const string &pat) {
    vector<int> res;
    if (pat.empty()) return res;
    size_t pos = text.find(pat, 0);
    while (pos != string::npos) {
        res.pb((int)pos);
        pos = text.find(pat, pos + 1);
    }
    return res;
}

// convert string to int safely (CP use)
int stoi_safe(const string &s) {
    if (s.empty()) return 0;
    return stoi(s);
}

// reverse string in-place
void reverse_inplace(string &s) { reverse(all(s)); }

// substring example (returns substring [l, len])
string substr_range(const string &s, int l, int len) {
    if (l < 0) l = 0;
    if (l >= (int)s.size()) return "";
    return s.substr(l, len);
}

//
// SMALL MISC HELPERS
//

// clamp index safe for vectors
template<typename T>
bool idx_valid(const vector<T>& v, int idx) {
    return idx >= 0 && idx < (int)v.size();
}

// fill vector with value (v.assign wrapper)
template<typename T>
void fill_vec(vector<T> &v, int n, const T &val) {
    v.assign(n, val);
}

// get frequency map (ordered)
template<typename T>
map<T,int> freq_map(const vector<T>& v) {
    map<T,int> mp;
    for (auto &x : v) mp[x]++;
    return mp;
}

// print first k elements of vector (uses your printVec macro maybe)
template<typename T>
void print_firstk(const vector<T>& v, int k) {
    for (int i = 0; i < k && i < (int)v.size(); ++i) cout << v[i] << ' ';
    cout << '\n';
}

/* -------------------------- END STL QUICK UTILS ------------------------------ */

// ----------------- Level 1 Algorithums -------------------------------

// ------------------- BFS -------------------
vector<int> BFS(int src, const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0; q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) if(dist[v]==-1) {
            dist[v] = dist[u]+1; q.push(v);
        }
    }
    return dist;
}

vector<int> MultiBFS(const vector<int>& sources, const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> dist(n,-1);
    queue<int> q;
    for(int s : sources) dist[s]=0, q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) if(dist[v]==-1) {
            dist[v]=dist[u]+1; q.push(v);
        }
    }
    return dist;
}

// ------------------- DFS -------------------
void DFS(int u, const vector<vector<int>>& g, vector<int>& vis) {
    vis[u] = 1;
    for(int v : g[u]) if(!vis[v]) DFS(v,g,vis);
}

void DFS_collect(int u, const vector<vector<int>>& g, vector<int>& vis, vector<int>& comp) {
    vis[u]=1; comp.push_back(u);
    for(int v : g[u]) if(!vis[v]) DFS_collect(v,g,vis,comp);
}

// ------------------- DSU -------------------
struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n,1){ iota(p.begin(), p.end(),0); }
    int find(int x){ return (p[x]==x? x: p[x]=find(p[x])); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b]; return true;
    }
    int size(int x){ return sz[find(x)]; }
};

// ------------------- HASH / FREQUENCY / COMPRESSION -------------------
unordered_map<int,int> freq(const vector<int>& a){
    unordered_map<int,int> m; m.reserve(a.size()*2);
    for(int x : a) m[x]++;
    return m;
}

int mostFreq(const vector<int>& a){
    auto m = freq(a);
    int best=a[0], bestc=0;
    for(auto &kv : m) if(kv.second>bestc) best=kv.first,bestc=kv.second;
    return best;
}

//---- Compression Comparision --------

vector<int> compress(vector<int> a){
    vector<int> b = a;                     // Make a copy
    sort(b.begin(),b.end());               // Sort the copy
    b.erase(unique(b.begin(),b.end()),b.end()); // Remove duplicates → now b contains unique sorted values

    for(auto &x : a)
        x = lower_bound(b.begin(),b.end(),x)-b.begin();
        // For each x in a, find its index in b (0-based) and assign it
    return a;                              // Return compressed array
}


// ------------------- USAGE EXAMPLES -------------------
// int main(){
//     vector<vector<int>> g(n); // graph
//     vector<int> a = { ... };  // array
//     auto d = BFS(0,g);        // single-source BFS
//     auto d2 = MultiBFS({0,1}, g); // multi-source BFS
//     vector<int> vis(n,0); DFS(0,g,vis); // DFS
//     DSU dsu(n); dsu.unite(1,2); // DSU
//     auto m = freq(a); int mf = mostFreq(a); auto comp = compress(a); // Hashing
// }


// -------------------- Solve --------------------
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,0,n) cin >> v[i];

    // Your logic here

}

void test() {
    int t;
    cin >> t;
    while (t--) solve();
    //flush();)
}

// -------------------- Main --------------------
int32_t main() {
    fastio();
    solve();
    flush();
    // For multiple testcases:
    // int t; cin >> t; while (t--) solve();
    return 0;
}
