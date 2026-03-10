#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

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
#define debug(x) cerr &lt;&lt; #x &lt;&lt; &#34; = &#34; &lt;&lt; (x) &lt;&lt; endl;
#define debugArr(arr) for (auto v : arr) cerr &lt;&lt; v &lt;&lt; &#34; &#34;; cerr &lt;&lt; endl;
#define readVec(v, n) for (int i = 0; i &lt; n; &#43;&#43;i) cin &gt;&gt; v[i];
#define readMatrix(mat, n, m) for (int i = 0; i &lt; n; &#43;&#43;i) for (int j = 0; j &lt; m; &#43;&#43;j) cin &gt;&gt; mat[i][j];
#define printVec(v) for (auto x : v) cout &lt;&lt; x &lt;&lt; &#34; &#34;; cout &lt;&lt; endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }
#define fp(i, a, b) for (int i = (a); i &lt; (b); &#43;&#43;i)

void solve() {
    int n,m;cin&gt;&gt;n&gt;&gt;m;
    vi v(4,0);
    v={2,3,3,4};
    int cnt=0;
    for (int i = 1; i &lt;= m; i&#43;&#43;)
    {
        int x,y;cin&gt;&gt;x&gt;&gt;y;
        
        for (int i = 0; i &lt; 4; i&#43;&#43;)
        {
            if(v[0]!=x&#43;y-1 &amp;&amp; v[1]!=x&#43;1&#43;y-1 &amp;&amp; v[2]!=x&#43;y&#43;1-1 &amp;&amp; v[3]!=x&#43;1&#43;y&#43;1-1) cnt&#43;&#43;;
            v.pb(x&#43;y);
            v.pb(x&#43;1&#43;y);
            v.pb(x&#43;y&#43;1);
            v.pb(x&#43;1&#43;y&#43;1);
        }
    }
    printVec(v);
    cout&lt;&lt;cnt&lt;&lt;endl;
}

using P=pair&lt;int,int&gt;;

void solve_1(){
    int n,m;cin&gt;&gt;n&gt;&gt;m;
    set&lt;P&gt; st;
    int ans=0;
    for (int i = 0; i &lt; m; i&#43;&#43;)
    {
        int a,b;cin&gt;&gt;a&gt;&gt;b;
        if(st.count(P(a,b))) continue;
        
        for (int x = 0; x &lt; 3; x&#43;&#43;)
        {
            for (int j = 0; j &lt; 3; j&#43;&#43;)
            {
                st.emplace(P(a&#43;x-1,b&#43;j-1));
            } 
        }
        ans&#43;&#43;;
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
    solve_1();
    return 0;
}