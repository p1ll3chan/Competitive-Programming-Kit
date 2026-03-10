#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

// Macros
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define vi vector&lt;int&gt;
#define vii vector&lt;vector&lt;int&gt;&gt;
#define pii pair&lt;int, int&gt;
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define YES cout &lt;&lt; &#34;YES&#34; &lt;&lt; endl
#define NO cout &lt;&lt; &#34;NO&#34; &lt;&lt; endl
#define YESNO(x) cout &lt;&lt; ((x) ? &#34;YES&#34; : &#34;NO&#34;) &lt;&lt; endl

// Debugging
#define debug(x) cerr &lt;&lt; #x &lt;&lt; &#34; = &#34; &lt;&lt; (x) &lt;&lt; endl;
#define debugArr(arr) for (auto v : arr) cerr &lt;&lt; v &lt;&lt; &#34; &#34;; cerr &lt;&lt; endl;

// Input macros
#define readVec(v, n) for (int i = 0; i &lt; n; &#43;&#43;i) cin &gt;&gt; v[i];
#define readMatrix(mat, n, m) for (int i = 0; i &lt; n; &#43;&#43;i) for (int j = 0; j &lt; m; &#43;&#43;j) cin &gt;&gt; mat[i][j];

// Output macros
#define printVec(v) for (auto x : v) cout &lt;&lt; x &lt;&lt; &#34; &#34;; cout &lt;&lt; endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }

// Matrix Macros
#define create2D(v, n, m) vector&lt;vector&lt;int&gt;&gt; v(n, vector&lt;int&gt;(m))
#define create3D(v, n, m, k) vector&lt;vector&lt;vector&lt;int&gt;&gt;&gt; v(n, vector&lt;vector&lt;int&gt;&gt;(m, vector&lt;int&gt;(k)))

int mostFrequentElement(vector&lt;int&gt;&amp; v) {
    unordered_map&lt;int, int&gt; freq;
    for (int num : v) freq[num]&#43;&#43;;
    int maxCount = 0, mostFrequent = v[0];
    for (auto&amp; [num, cnt] : freq) {
        if (cnt &gt; maxCount) {
            maxCount = cnt;
            mostFrequent = num;
        }
    }
    return mostFrequent;
}

string mostFrequentString(vector&lt;string&gt;&amp; v) {
    unordered_map&lt;string, int&gt; freq;
    for (string&amp; s : v) freq[s]&#43;&#43;;
    int maxCount = 0;
    string mostFrequent;
    for (auto&amp; [str, cnt] : freq) {
        if (cnt &gt; maxCount) {
            maxCount = cnt;
            mostFrequent = str;
        }
    }
    return mostFrequent;
}

string leastFrequentString(vector&lt;string&gt;&amp; v) {
    unordered_map&lt;string, int&gt; freq;
    for (string&amp; s : v) freq[s]&#43;&#43;;

    int minCount = INT_MAX;
    string leastFrequent;
    for (auto&amp; [str, cnt] : freq) {
        if (cnt &lt; minCount) {
            minCount = cnt;
            leastFrequent = str;
        }
    }
    return leastFrequent;
}


vector&lt;string&gt; getStrings(const string&amp; v) {
    vector&lt;string&gt; result;
    for (int i = 0; i &lt; v.size(); &#43;&#43;i) {
        result.pb(string(1, v[i]));
    }
    return result;
}

// Solve function
void solve() {
    string s;cin&gt;&gt;s;
    vector&lt;string&gt;v=getStrings(s);
    cout&lt;&lt;leastFrequentString(v)&lt;&lt;endl;
}

// Testcase function
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