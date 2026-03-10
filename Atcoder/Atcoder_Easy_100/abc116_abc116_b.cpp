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

// void solve_1() {
//     int s;cin&gt;&gt;s;
//     vi v;
//     v.pb(s);
//     int x=s;
//     if(x==1 || x==2){
//         cout&lt;&lt;4&lt;&lt;endl;
//         return;
//     }
//     for (int i = 0; i &lt; 1e6&#43;1; i&#43;&#43;)
//     {
//         int ans;
//         if(x%2==0){
//              ans=x/2;
//         }else{
//              ans=3*x&#43;1;
//         }
//         v.pb(ans);
//         x=ans;
//         if(v[i]==1){
//             break;
//         }
//     }
//     cout&lt;&lt;v.size()&lt;&lt;endl;
// }

void solve(){
    int s;cin&gt;&gt;s;
    set&lt;int&gt; v;
    int x=s;
    v.insert(s);
    for (int i = 0; i &lt; 1e6&#43;1; i&#43;&#43;)
    {
        int ans;
        if(x%2==0){
             ans=x/2;
        }else{
             ans=3*x&#43;1;
        }
        if(v.count(ans)){
            cout&lt;&lt;i&#43;2&lt;&lt;endl;
            return;
        }
        v.insert(ans);
        x=ans;

        
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