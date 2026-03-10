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
//     string s;cin&gt;&gt;s;
//     int n=s.size();
//     unordered_map&lt;char,int&gt; mp;
//     for (int i = 0; i &lt; n; i&#43;&#43;)
//     {
//         mp[s[i]]&#43;&#43;;
//     }
//     bool ok=false;
//     for (int i = 0; i &lt; n; i&#43;&#43;)
//     {
        
//         int x=s.back();
//         s.pop_back();
//         for(auto &amp;j:mp){
//             if(j.first==x){
//                 j.second--;
//             }
           
//         }
//         int odd=0;
//         for(auto &amp;j:mp){
//              if(j.second%2!=0){
//                 odd&#43;&#43;;
//             }
//         }
//         if(odd&lt;=1) ok=true;    
//     }
//     if(ok){
//             cout&lt;&lt;s.size()&lt;&lt;endl;
//     }
//}

bool check(string s){
    int n=s.size();
    if(n%2==1) return false;
    for (int i = 0; i &lt; n/2; i&#43;&#43;)
    {
        if(s[i&#43;n/2]!=s[i]) return false;
    }
    return true;
}

void solve(){
    string s;cin&gt;&gt;s;
    int res=0;
    
    for (int i = 0; i &lt; s.size(); i&#43;&#43;)
    {
        string sub=s.substr(0,i);
        if(check(sub)){
            res=max(i,res);
        }
    }
    cout&lt;&lt;res&lt;&lt;endl;
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