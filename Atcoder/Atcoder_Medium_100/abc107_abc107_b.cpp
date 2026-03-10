#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl &#34;\n&#34;
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define vi vector&lt;string&gt;
#define rall(c) c.rbegin(),c.rend()
#define vii vector&lt;vector&lt;char&gt;&gt;
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
    int n,m;cin&gt;&gt;n&gt;&gt;m;
    // vii v(n,vi(m));
    vi v(n);
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        cin&gt;&gt;v[i];
    }
    vector&lt;bool&gt; row_cnt(n,false);
    vector&lt;bool&gt; col_cnt(m,false);
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        for (int j = 0; j &lt; m; j&#43;&#43;)
        {
            if(v[i][j]==&#39;#&#39;){
                row_cnt[i]=true;
                col_cnt[j]=true;
            }
        }
        
    }

    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        if(!row_cnt[i]) continue;
        for (int j = 0; j &lt; m; j&#43;&#43;)
        {
            if(!col_cnt[j]) continue;
            cout&lt;&lt;v[i][j];
        }
        cout&lt;&lt;endl;
    }
    
    
    
    // vector&lt;int&gt; row_ignore;
    // for (int i = 0; i &lt; n; i&#43;&#43;)
    // {
    //     int row_cnt=0;
    //     for (int j = 0; j &lt; m; j&#43;&#43;)
    //     {
    //         if(v[i][j]==&#39;.&#39;) row_cnt&#43;&#43;;
            
    //     }
    //     if(row_cnt==m){
    //         row_ignore.pb(i&#43;1);
    //     }
        
    // }
    // vector&lt;int&gt; col_ignore;
    // for (int j = 0; j &lt; m; j&#43;&#43;)
    // {
    //     int col_cnt=0;
    //     for (int i = 0; i &lt; n; i&#43;&#43;)
    //     {
    //         if(v[i][j]==&#39;.&#39;) col_cnt&#43;&#43;;
    //     }
    //     if(col_cnt==n){
    //         col_ignore.pb(j&#43;1);
    //     }
    // }
    
    // printVec(row_ignore);
    // printVec(col_ignore);

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