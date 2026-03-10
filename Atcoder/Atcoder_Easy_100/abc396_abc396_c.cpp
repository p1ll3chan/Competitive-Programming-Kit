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
    vi a(n);
    vi b(m);
    readVec(a,n);
    readVec(b,m);
    int pos_a=0;
    int pos_b=0;
    int sum=0;

    int min_size=min(m,n);
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        if(a[i]&gt;0) {
            pos_a&#43;&#43;; 
            sum&#43;=a[i];
        }

    }
    for (int i = 0; i &lt; m; i&#43;&#43;)
    {
        if(b[i]&gt;0) {
            pos_b&#43;&#43;;
            sum&#43;=b[i];
        }
    }
    if(pos_a&gt;=pos_b){
        cout&lt;&lt;sum&lt;&lt;endl;
    }else{
        sort(rall(a));
        sort(rall(b));
        int sum_1=0;
        int max_x=0;
        for (int i = 0; i &lt; min_size; i&#43;&#43;)
        {
            sum_1&#43;=a[i]&#43;b[i];
            max_x=max(sum_1,max_x);
            //cout&lt;&lt;sum_1&lt;&lt;endl;
        }
        cout&lt;&lt;max_x&lt;&lt;endl;
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
    solve();
    return 0;
}