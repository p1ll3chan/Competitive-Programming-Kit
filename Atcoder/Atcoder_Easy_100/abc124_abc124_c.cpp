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

// void solve_1() {
//     string s;cin&gt;&gt;s;
//     int n=s.size();
//     string s1,s2;
//     for (int i = 0; i &lt; n; i&#43;&#43;)
//     {
//         if(i%2==0) s1.pb(&#39;0&#39;);
//         else s1.pb(&#39;1&#39;);
//     }
//     //cout&lt;&lt;s1&lt;&lt;endl;
//     for (int i = 0; i &lt; n; i&#43;&#43;)
//     {
//         if(i%2==0) s2.pb(&#39;1&#39;);
//         else s2.pb(&#39;0&#39;);
//     }
//     int cnt1=0;
//     int cnt2=0;
//     for (int i = 0; i &lt; s.size(); i&#43;&#43;)
//     {
//         if(s[i]!=s1[i]) cnt1&#43;&#43;;
//         if(s[i]!=s2[i]) cnt2&#43;&#43;;
//     }
//     cout&lt;&lt;min(cnt1,cnt2)&lt;&lt;endl;
// }

void solve(){
    string s;cin&gt;&gt;s;
    int n=s.size();
    int idx=1;
    int cnt1=0,cnt2=0;
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        if(i%2==0){
            idx--;
            if(s[i]-&#39;0&#39;!=idx)
            cnt1&#43;&#43;;
        }else{
            idx&#43;&#43;;
            if(s[i]-&#39;0&#39;!=idx)
            cnt1&#43;&#43;;
        }
    }
    int udx=0;
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        if(i%2==0){
            udx&#43;&#43;;
            if(s[i]-&#39;0&#39;!=udx){
                cnt2&#43;&#43;;
            }
        }
        else{
            udx--;
            if(s[i]-&#39;0&#39;!=udx){
                cnt2&#43;&#43;;
            }
        }
    }
    //cout&lt;&lt;cnt1&lt;&lt;&#34; &#34;&lt;&lt;cnt2&lt;&lt;endl;
    cout&lt;&lt;min(cnt1,cnt2)&lt;&lt;endl;
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