#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

//#define int long long
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
#define debug(x) cerr &lt;&lt; #x &lt;&lt; &#34; = &#34; &lt;&lt; (x) &lt;&lt; endl;
#define debugArr(arr) for (auto v : arr) cerr &lt;&lt; v &lt;&lt; &#34; &#34;; cerr &lt;&lt; endl;
#define readVec(v, n) for (int i = 0; i &lt; n; &#43;&#43;i) cin &gt;&gt; v[i];
#define readMatrix(mat, n, m) for (int i = 0; i &lt; n; &#43;&#43;i) for (int j = 0; j &lt; m; &#43;&#43;j) cin &gt;&gt; mat[i][j];
#define printVec(v) for (auto x : v) cout &lt;&lt; x &lt;&lt; &#34; &#34;; cout &lt;&lt; endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }
#define fp(i, a, b) for (int i = (a); i &lt; (b); &#43;&#43;i)

void solve() {
    int N,m;cin&gt;&gt;N&gt;&gt;m;
    vi setmark(m,0);
    
    for (int i = 0; i &lt; m; i&#43;&#43;)
    {
        int n;cin&gt;&gt;n;
        for (int j = 0; j &lt; n; j&#43;&#43;)
        {
            int k;cin&gt;&gt;k;
            setmark[i]|=(1&lt;&lt;(k-1));
       } 
    }
    int target=(1&lt;&lt;N)-1;
    int ans=0;
    for (int mark = 1; mark &lt; (1&lt;&lt;m); mark&#43;&#43;)
    {
        int counter=0;
        for (int i = 0; i &lt; m; i&#43;&#43;)
        {
            if(mark&amp;(1&lt;&lt;i)){
                counter|=setmark[i];
            }
        }
        if(counter==target)ans&#43;&#43;;
        //cout &lt;&lt; bitset&lt;10&gt;(counter) &lt;&lt; endl;
       }
    
    cout&lt;&lt;ans&lt;&lt;endl;
}

void test() {
    int t;
    cin &gt;&gt; t;
    while (t--) solve();
}

int32_t main() {
    fastio();
    // test();
    solve();
    return 0;
}