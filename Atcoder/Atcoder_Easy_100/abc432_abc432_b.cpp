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


int vectorToInt(const vector&lt;int&gt;&amp; v) {
    int result = 0;
    for (size_t i = 0; i &lt; v.size(); i&#43;&#43;) {
        result = result * 10 &#43; v[i];
    }
    return result;
}


// Solve function
void solve() {
   string s;cin&gt;&gt;s;
   vi v;
   for (size_t i = 0; i &lt; s.size(); i&#43;&#43;)
   {
        int n=s[i]-&#39;0&#39;;
        v.pb(n);
   }
   //printVec(v);
   sort(all(v));
   //printVec(v);
   int cnt=0;

   for (size_t i = 0; i &lt; v.size()-1; i&#43;&#43;)
   {
    if(v[i]==0){
        cnt&#43;&#43;;
    }
   }
   


   for (size_t i = 0; i &lt; v.size()-1; i&#43;&#43;)
   {
    if(v[i]==0){
        swap(v[i],v[cnt]);
        break;
    }
    
   }
   int n=vectorToInt(v);
   cout&lt;&lt;n&lt;&lt;endl;
   
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