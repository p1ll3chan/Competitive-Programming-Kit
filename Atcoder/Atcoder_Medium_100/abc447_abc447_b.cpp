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

int mostFrequentString(vector&lt;string&gt;&amp; v) {
    unordered_map&lt;string, int&gt; freq;
    for (string&amp; s : v) freq[s]&#43;&#43;;
    int maxCount = 0;
    string mostFrequent;
    for (auto&amp; [str, cnt] : freq) {
        if (cnt &gt; maxCount) {
            maxCount = cnt;
            mostFrequent = str;
        }
    }
    return maxCount;
}

vector&lt;string&gt; getStrings(const string&amp; v) {
    vector&lt;string&gt; result;
    for (int i = 0; i &lt; v.size(); &#43;&#43;i) {
        result.pb(string(1, v[i]));
    }
    return result;
}
void solve() {
    string s;cin&gt;&gt;s;
    vector&lt;string&gt;v=getStrings(s);
    int ans=mostFrequentString(v);
    //debug(ans)
    map&lt;char,int&gt; freq;
    for (int i = 0; i &lt; s.size(); i&#43;&#43;)
    {
        freq[s[i]]&#43;&#43;;
    }
    string ds=&#34;&#34;;
    for(auto x:freq){
        if(x.second!=ans){
            //cout&lt;&lt;x.first;
            ds&#43;=x.first;
        }
    }
    //debug(ds)
    for (int i = 0; i &lt; s.size(); i&#43;&#43;)
    {
        for (int j = 0; j &lt; ds.size(); j&#43;&#43;)
        {
            if(s[i]==ds[j]){
                cout&lt;&lt;s[i];
            }
        }
        
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