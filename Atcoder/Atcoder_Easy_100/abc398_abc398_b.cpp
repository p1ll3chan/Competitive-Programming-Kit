#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

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
#define debug(x) cerr &lt;&lt; #x &lt;&lt; &#34; = &#34; &lt;&lt; (x) &lt;&lt; endl;
#define debugArr(arr) for (auto v : arr) cerr &lt;&lt; v &lt;&lt; &#34; &#34;; cerr &lt;&lt; endl;
#define readVec(v, n) for (int i = 0; i &lt; n; &#43;&#43;i) cin &gt;&gt; v[i];
#define readMatrix(mat, n, m) for (int i = 0; i &lt; n; &#43;&#43;i) for (int j = 0; j &lt; m; &#43;&#43;j) cin &gt;&gt; mat[i][j];
#define printVec(v) for (auto x : v) cout &lt;&lt; x &lt;&lt; &#34; &#34;; cout &lt;&lt; endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }
#define fp(i, a, b) for (int i = (a); i &lt; (b); &#43;&#43;i)

void solve() {
    int a,b,c,d,e,f,g;
    cin&gt;&gt;a&gt;&gt;b&gt;&gt;c&gt;&gt;d&gt;&gt;e&gt;&gt;f&gt;&gt;g;
    vi v={a,b,c,d,e,f,g};
    unordered_map&lt;int,int&gt; mp;
    for(int x:v) mp[x]&#43;&#43;;
    vi v1;
    for(auto &amp;[x,y]:mp){ v1.pb(y);}
    sort(all(v1));
    int sz_of_v1=sz(v1);
    if(sz_of_v1==1){
        cout&lt;&lt;&#34;No\n&#34;;
        return;
    }
    if(v1.back()&gt;=3 &amp;&amp; v1[sz_of_v1-2]&gt;=2){
        cout&lt;&lt;&#34;Yes\n&#34;;
        return;
    }
    cout&lt;&lt;&#34;No\n&#34;;

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