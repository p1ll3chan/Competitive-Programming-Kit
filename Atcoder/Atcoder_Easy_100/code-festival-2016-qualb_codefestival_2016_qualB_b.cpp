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

// void solve() {
//     int n,a,b;cin&gt;&gt;n&gt;&gt;a&gt;&gt;b;
//     string s;cin&gt;&gt;s;

//     int max_s=max(a,b);
//     int min_s=min(a,b);
//     int t=n;
//     int i=0;
//     while(t--){
//         if(s[i]==&#39;a&#39; &amp;&amp; max_s&gt;0){
//             max_s--;
//             cout&lt;&lt;&#34;Yes&#34;&lt;&lt;endl;
//         }else if(s[i]==&#39;b&#39; &amp;&amp; min_s&gt;0){
//             min_s--;
//             cout&lt;&lt;&#34;Yes&#34;&lt;&lt;endl;
//         }else{
//             cout&lt;&lt;&#34;No&#34;&lt;&lt;endl;
//         }
//         i&#43;&#43;;
//     }
//     // Your logic here
// }

void solve(){
    int n,a,b;cin&gt;&gt;n&gt;&gt;a&gt;&gt;b;
    string s;cin&gt;&gt;s;

    int pass=0;
    int cross_pass=0;
    int i=0;
    while(n--){
        if(s[i]==&#39;a&#39;){
            if(pass&lt;a&#43;b){
            cout&lt;&lt;&#34;Yes&#34;&lt;&lt;endl;
            pass&#43;&#43;;
            }else{
            cout&lt;&lt;&#34;No&#34;&lt;&lt;endl;
        }
        }
        else if(s[i]==&#39;b&#39;){
            if(pass&lt;a&#43;b &amp;&amp; cross_pass&lt;b){
                
                cout&lt;&lt;&#34;Yes&#34;&lt;&lt;endl;
                pass&#43;&#43;;
                cross_pass&#43;&#43;;
            }else{
            cout&lt;&lt;&#34;No&#34;&lt;&lt;endl;
        }
        }else{
            cout&lt;&lt;&#34;No&#34;&lt;&lt;endl;
        }
        i&#43;&#43;;
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