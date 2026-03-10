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
    string s;
    getline(cin, s);
    vector&lt;string&gt; v;
    for (char i = 0; i &lt; s.size(); i&#43;&#43;)
    {
        if(s[i]==&#39;r&#39; &amp;&amp; s[i&#43;1]==&#39;e&#39; &amp;&amp; s[i&#43;2]==&#39;d&#39;){
            v.pb(&#34;SSS&#34;);
        }
        else if(s[i]==&#39;b&#39; &amp;&amp; s[i&#43;1]==&#39;l&#39; &amp;&amp; s[i&#43;2]==&#39;u&#39; &amp;&amp; s[i&#43;3]==&#39;e&#39;){
            v.pb(&#34;FFF&#34;);
        }
        else if(s[i]==&#39;g&#39; &amp;&amp; s[i&#43;1]==&#39;r&#39; &amp;&amp; s[i&#43;2]==&#39;e&#39; &amp;&amp; s[i&#43;3]==&#39;e&#39; &amp;&amp; s[i&#43;4]==&#39;n&#39;){
            v.pb(&#34;MMM&#34;);
        }else{
            cout&lt;&lt;&#34;Known&#34;&lt;&lt;endl;
            return;
        }
    }
    printVec(v);
    
}

void solve1(){
    string s;
    cin &gt;&gt; s;
    if(s==&#34;red&#34;){
        cout&lt;&lt;&#34;SSS&#34;&lt;&lt;endl;
    }else if(s==&#34;blue&#34;){
        cout&lt;&lt;&#34;FFF&#34;&lt;&lt;endl;
    }else if(s==&#34;green&#34;){
        cout&lt;&lt;&#34;MMM&#34;&lt;&lt;endl;
    }else{
        cout&lt;&lt;&#34;Unknown&#34;&lt;&lt;endl;  // fixed
    }
}


void test() {
    int t;
    cin &gt;&gt; t;
    while (t--) solve1();
}

int32_t main() {
    fastio();
    // test();
    solve1();
    return 0;
}