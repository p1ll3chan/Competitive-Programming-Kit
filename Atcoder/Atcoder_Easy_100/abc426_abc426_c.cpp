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
    vi v;
    for (int i = 0; i &lt; m; i&#43;&#43;)
    {
        v.pb(i&#43;1);
    }
    //printVec(v);
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        int cnt=0;
        int x,y;cin&gt;&gt;x&gt;&gt;y;
        while(m--){
        if(v[i]&lt;=x){
            cnt&#43;&#43;;
            v.insert(v.begin()&#43;i&#43;1,y);
        }
        
        }
        cout&lt;&lt;cnt&lt;&lt;endl;
    }
    
}

void solve1() {
    int n, m;
    cin &gt;&gt; n &gt;&gt; m;
    //vi v;
    // for (int i = 0; i &lt; n; i&#43;&#43;)
    // {
    //     v.pb(i&#43;1);
    // }
    vector&lt;int&gt; v(n&#43;1,1);

    int o=1;
    for (int i = 0; i &lt; m; i&#43;&#43;) {
        int x, y;
        cin &gt;&gt; x &gt;&gt; y;
        int cnt = 0;
        while(o&lt;=x){
            cnt&#43;=v[o];
            v[y]&#43;=v[o];
            o&#43;&#43;;
        }
        cout &lt;&lt; cnt &lt;&lt; endl;
    }
}


void test() {
    int t;
    cin &gt;&gt; t;
    while (t--) solve();
}

int32_t main() {
    fastio();
    // test();
    solve1();
    return 0;
}