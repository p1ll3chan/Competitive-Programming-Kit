#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl &#34;\n&#34;
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define vi vector&lt;int&gt;
#define rall(c) c.rbegin(),c.rend()
#define vii vector&lt;vector&lt;int&gt;&gt;
#define pii pair&lt;int, int&gt;
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define YES cout &lt;&lt; &#34;Yes&#34; &lt;&lt; endl
#define NO cout &lt;&lt; &#34;No&#34; &lt;&lt; endl
#define YESNO(x) cout &lt;&lt; ((x) ? &#34;YES&#34; : &#34;NO&#34;) &lt;&lt; endl
#define debug(x) cerr &lt;&lt; #x &lt;&lt; &#34; = &#34; &lt;&lt; (x) &lt;&lt; endl;
#define debugArr(arr) for (auto v : arr) cerr &lt;&lt; v &lt;&lt; &#34; &#34;; cerr &lt;&lt; endl;
#define readVec(v, n) for (int i = 0; i &lt; n; &#43;&#43;i) cin &gt;&gt; v[i];
#define readMatrix(mat, n, m) for (int i = 0; i &lt; n; &#43;&#43;i) for (int j = 0; j &lt; m; &#43;&#43;j) cin &gt;&gt; mat[i][j];
#define printVec(v) for (auto x : v) cout &lt;&lt; x &lt;&lt; &#34; &#34;; cout &lt;&lt; endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }
#define fp(i, a, b) for (int i = (a); i &lt; (b); &#43;&#43;i)

void solve() {
    int n;
    cin &gt;&gt; n;
    set&lt;string&gt; s;
    int cnt=0;
    fp(i,0,n){
        int x;cin&gt;&gt;x;
        if (x&lt;=399) s.insert(&#34;grey&#34;);
        else if(x&gt;=400 &amp;&amp; x&lt;800) s.insert(&#34;brown&#34;);
        else if(x&gt;=800 &amp;&amp; x&lt;1200) s.insert(&#34;green&#34;);
        else if(x&gt;=1200 &amp;&amp; x&lt;1600) s.insert(&#34;cyan&#34;);
        else if(x&gt;=1600 &amp;&amp; x&lt;2000) s.insert(&#34;blue&#34;);
        else if(x&gt;=2000 &amp;&amp; x&lt;2400) s.insert(&#34;yellow&#34;);
        else if(x&gt;=2400 &amp;&amp; x&lt;2800) s.insert(&#34;orange&#34;);
        else if(x&gt;=2800 &amp;&amp; x&lt;3200) s.insert(&#34;red&#34;);    
        else cnt&#43;&#43;;    
    }
    //printVec(s);
    int max_cnt=0,min_cnt=0;
    if(s.size()==0){
        max_cnt=cnt;
        min_cnt=1;
        cout&lt;&lt;min_cnt&lt;&lt;&#34; &#34;&lt;&lt;max_cnt&lt;&lt;endl;
        return;
    }
    max_cnt=s.size()&#43;cnt;
    min_cnt=max((int)s.size(),1LL);
    cout&lt;&lt;min_cnt&lt;&lt;&#34; &#34;&lt;&lt;max_cnt&lt;&lt;endl;
    

    // Your logic here
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