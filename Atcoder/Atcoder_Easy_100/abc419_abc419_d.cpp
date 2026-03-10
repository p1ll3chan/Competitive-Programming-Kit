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

vector&lt;int&gt; prefixSum(const vector&lt;int&gt;&amp; v) {
    int n = v.size();
    vector&lt;int&gt; psum(n);
    psum[0] = v[0];
    for (int i = 1; i &lt; n; i&#43;&#43;)
        psum[i] = psum[i - 1] &#43; v[i];
    return psum;
}

void solve() {
    int n,m;cin&gt;&gt;n&gt;&gt;m;
    string s1;cin&gt;&gt;s1;
    string s2;cin&gt;&gt;s2;
    vector&lt;int&gt; v(n&#43;2,0);
    for (int i = 0; i &lt; m; i&#43;&#43;)
    {
        int a,b;cin&gt;&gt;a&gt;&gt;b;
        a--,b--; // convert to 0-index
        v[a]&#43;=1;
        v[b&#43;1]-=1;
    }
    //printVec(v);
    vector&lt;int&gt; v1=prefixSum(v);
    //printVec(v1);
    string v2=s1;
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        //v2[0]=s1[0];
        if(v1[i]%2==1){
            v2[i]=s2[i];
        }else{
            v2[i]=s1[i];
        }
    }
    cout&lt;&lt;v2&lt;&lt;endl;
    
    
}

void solve1() {
    int n, m;
    cin &gt;&gt; n &gt;&gt; m;
    string s1, s2;
    cin &gt;&gt; s1 &gt;&gt; s2;

    vector&lt;int&gt; v(n &#43; 2, 0); // difference array (n&#43;2 safe size)
    for (int i = 0; i &lt; m; i&#43;&#43;) {
        int a, b;
        cin &gt;&gt; a &gt;&gt; b;
        a--, b--; // convert to 0-index
        v[a] &#43;= 1;
        v[b &#43; 1] -= 1;
    }

    // prefix sum
    vector&lt;int&gt; v1(n);
    v1[0] = v[0];
    for (int i = 1; i &lt; n; i&#43;&#43;) v1[i] = v1[i - 1] &#43; v[i];

    // build answer
    string ans = s1;
    for (int i = 0; i &lt; n; i&#43;&#43;) {
        if (v1[i] % 2 == 1) ans[i] = s2[i]; // odd flips → s2
        else ans[i] = s1[i];                // even flips → s1
    }

    cout &lt;&lt; ans &lt;&lt; &#34;\n&#34;;
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