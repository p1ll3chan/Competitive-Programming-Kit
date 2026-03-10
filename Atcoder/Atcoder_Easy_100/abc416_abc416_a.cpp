#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define printVec(v) for (auto x : v) cout &lt;&lt; x &lt;&lt; &#34; &#34;; cout &lt;&lt; endl;


vector&lt;string&gt; getStrings(const string&amp; v) { vector&lt;string&gt; result; for (int i = 0; i &lt; (int)v.size(); &#43;&#43;i) { result.push_back(string(1, v[i])); } return result; }


void solve() {
    int n,l,r;cin &gt;&gt; n &gt;&gt; l &gt;&gt; r;
    string s;cin&gt;&gt; s;
    //int cnt=0;
    //vector&lt;string&gt; v=getStrings(s);
    for (int i = l-1; i &lt; r; i&#43;&#43;)
    {
        if (s[i] == &#39;x&#39;) {
            cout &lt;&lt; &#34;No&#34; &lt;&lt; endl;
            return;
        }
    }
    cout &lt;&lt; &#34;Yes&#34; &lt;&lt; endl;
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