#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

#define ll long long
typedef vector&lt;int&gt; vi;
typedef vector&lt;vector&lt;int&gt;&gt; vii;
typedef pair&lt;int,int&gt; pi;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define fp(a,b) for (int i = a; i &lt; b; &#43;&#43;i)
#define fn(a,b) for (int i = a; i &lt; b; --i)

void solve() {
    int n;cin&gt;&gt;n;
    vi v(n);
    int cnt=0;
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        cin&gt;&gt;v[i];
    }
    for (int i = 0; i &lt; n-1; i&#43;&#43;)
    {
        if(v[i]&lt;v[i&#43;1]){
            cnt&#43;&#43;;
        }
    }
    if(cnt==n-1){
        cout&lt;&lt;&#34;Yes&#34;&lt;&lt;endl;
        return;
    }
    cout&lt;&lt;&#34;No&#34;&lt;&lt;endl;

    
}

void test() {
    int t;
    cin &gt;&gt; t;
    while (t--) {
        solve();
    }
}

int32_t main() {
    // test();
    solve();
    return 0;
}
