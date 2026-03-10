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


int max_x(const vector&lt;int&gt;&amp; v) {
    return *max_element(all(v));
}

int min(const vector&lt;int&gt;&amp; v) {
    return *min_element(all(v));
}

string oddEven(int i, const string &amp;s1, const string &amp;s2) {
    return (i &amp; 1) ? s1 : s2;
}

vi merge_2(const vi &amp;a, const vi &amp;b) {
    vi v = a;
    v.insert(v.end(), all(b));
    return v;
}

// Solve function
void solve() {
    int n,m;cin&gt;&gt;n&gt;&gt;m;
    vector&lt;string&gt; s(n);
    for(auto &amp;i:s){
        cin&gt;&gt;i;
    }
    //y=1 &amp; x=0
    vi v(n,0);
    for (int i = 0; i &lt; m; i&#43;&#43;)
    {
        int y=0;
        for (int j = 0; j &lt; n; j&#43;&#43;)
        {
            if(s[j][i]==&#39;1&#39;) y&#43;&#43;;
        }
        int x=n-y;

        for (int j = 0; j &lt; n; j&#43;&#43;)
        {
            if(s[j][i]==&#39;1&#39;){
                if(x&gt;y) v[j]&#43;&#43;;
            }else{
                if(y&gt;x) v[j]&#43;&#43;;
            }
        }
        
    }
    int maxx=max_x(v);
    bool pot=false;
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        if(v[i]==maxx){
        if(pot) cout&lt;&lt;&#34; &#34;;
        cout&lt;&lt;i&#43;1;
        pot=true;
        }
    }
    cout&lt;&lt;&#34;\n&#34;;
    
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