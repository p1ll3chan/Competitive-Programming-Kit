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


/*intution - 1

 string s;cin&gt;&gt;s;
    int cnt_left=0,cnt_right=0;
    int n=s.size();
    fp(i,0,n){
        if(s[i]==&#39;&lt;&#39;) cnt_left&#43;&#43;;
        else cnt_right&#43;&#43;;
    }
    debug(cnt_left);
    debug(cnt_right);
    
*/

void solve() {
    string s;cin&gt;&gt;s;
    int n=s.size();
    vi L(n&#43;1,0),R(n&#43;1,0);
    for (int i = 0; i &lt;= n-1; i&#43;&#43;)
    {
        if(s[i]==&#39;&lt;&#39;){
            L[i&#43;1]=L[i]&#43;1;
        }
    }

    for (int i = n-1; i &gt;= 0; i--)
    {
        if(s[i]==&#39;&gt;&#39;){
            R[i]=R[i&#43;1]&#43;1;
        }
    }
    int ans=0;
    for (int i = 0; i &lt;= n; i&#43;&#43;)
    {
        ans&#43;=max(L[i],R[i]);
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