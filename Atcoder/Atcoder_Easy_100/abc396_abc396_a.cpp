#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

// Macros  
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define vi vector&lt;int&gt;
#define vii vector&lt;vector&lt;int&gt;&gt;
#define pii pair&lt;int, int&gt;
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Debugging  
#define debug(x) cerr &lt;&lt; #x &lt;&lt; &#34; = &#34; &lt;&lt; (x) &lt;&lt; endl;
#define debugArr(arr) for (auto v : arr) cerr &lt;&lt; v &lt;&lt; &#34; &#34;; cerr &lt;&lt; endl;

// Input macros  
#define readVec(v, n) for (int i = 0; i &lt; n; &#43;&#43;i) cin &gt;&gt; v[i];
#define readMatrix(mat, n, m) for (int i = 0; i &lt; n; &#43;&#43;i) for (int j = 0; j &lt; m; &#43;&#43;j) cin &gt;&gt; mat[i][j];

// Output macros  
#define printVec(v) for (auto x : v) cout &lt;&lt; x &lt;&lt; &#34; &#34;; cout &lt;&lt; endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }

// Function to calculate sum of first N natural numbers  
ll sumN(int n) { return 1LL * n * (n &#43; 1) / 2; }

// Maximum value finder  
int getMax(int high, int sum) { return max(high, sum); }

// ASCII cyclic difference  
int cyclicDiff(char a, char b) { return min(abs(a - b), 26 - abs(a - b)); }

// Simulation &#43; Greedy (Bucket Pouring Algorithm)  
void simulate(vector&lt;int&gt;&amp; v, int a1, int a2, int d[]) {
    int amt = min(v[a1], d[a2] - v[a2]);
    v[a1] -= amt;
    v[a2] &#43;= amt;
}

// GCD  
int gcd(int a, int b) {
    while (b) { int r = a % b; a = b; b = r; }
    return a;
}

// Count digit frequency  
void countDigits(int n, vector&lt;int&gt;&amp; count) {
    while (n &gt; 0) { count[n % 10]&#43;&#43;; n /= 10; }
}

// Count frequency of unique values  
int countUnique(vector&lt;int&gt;&amp; v, int n) {
    vector&lt;int&gt; freq(n &#43; 1, 0);
    for (int i = 0; i &lt; n; i&#43;&#43;) freq[v[i]]&#43;&#43;;
    int x = 0;
    for (int i = 0; i &lt;= n; i&#43;&#43;) x &#43;= freq[i] / 2;
    return x;
}

// Prefix Sum  
vector&lt;int&gt; prefixSum(const vector&lt;int&gt;&amp; v) {
    int n = v.size();
    vector&lt;int&gt; psum(n);
    psum[0] = v[0];
    for (int i = 1; i &lt; n; i&#43;&#43;) psum[i] = psum[i - 1] &#43; v[i];
    return psum;
}

// Generate permutations  
void permute(int index, string &amp;s, vector&lt;string&gt; &amp;ans) {
    if (index == s.size()) { ans.pb(s); return; }
    for (int i = index; i &lt; s.size(); i&#43;&#43;) {
        swap(s[index], s[i]);
        permute(index &#43; 1, s, ans);
        swap(s[index], s[i]);
    }
}

// Binary Search  
int binarySearch(vector&lt;int&gt;&amp; a, int b) {
    int lo = 0, hi = a.size();
    while (lo &lt; hi) {
        int mid = lo &#43; (hi - lo) / 2;
        if (a[mid] &lt;= b) lo = mid &#43; 1;
        else hi = mid;
    }
    return lo;
}

// Two-Pointer Algorithm  
void twoPointers(vector&lt;int&gt;&amp; v, int target) {
    int l = 0, r = v.size() - 1;
    while (l &lt; r) {
        int sum = v[l] &#43; v[r];
        if (sum == target) { cout &lt;&lt; l &lt;&lt; &#34; &#34; &lt;&lt; r &lt;&lt; endl; return; }
        if (sum &lt; target) l&#43;&#43;;
        else r--;
    }
}

// 2D &amp; 3D Matrix Macros  
#define create2D(n, m) vector&lt;vector&lt;int&gt;&gt;(n, vector&lt;int&gt;(m))
#define create3D(n, m, k) vector&lt;vector&lt;vector&lt;int&gt;&gt;&gt;(n, vector&lt;vector&lt;int&gt;&gt;(m, vector&lt;int&gt;(k)))

// Error Handling  


// Solve function (modify per problem)  
void solve() {
    int n;
    cin &gt;&gt; n;
    vector&lt;int&gt; v(n);
    readVec(v, n);
    for(int i=0;i&lt;n;i&#43;&#43;){
    	if(v[i]==v[i&#43;1] &amp;&amp; v[i]==v[i&#43;2]){
    		cout&lt;&lt;&#34;Yes&#34;&lt;&lt;endl;
    		return;
    	}
    }
    cout&lt;&lt;&#34;No&#34;&lt;&lt;&#34;\n&#34;;
}

// Test function  
void test() {
    int t;
    cin &gt;&gt; t;
    while (t--) solve();
}

// Main function  
int32_t main() {
    fastio();
    // test();
    solve();
    return 0;
}
