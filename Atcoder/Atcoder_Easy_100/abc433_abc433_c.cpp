#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

// Macros
#define int long long
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

// Debugging
#define debug(x) cerr &lt;&lt; #x &lt;&lt; &#34; = &#34; &lt;&lt; (x) &lt;&lt; endl;
#define debugArr(arr) for (auto v : arr) cerr &lt;&lt; v &lt;&lt; &#34; &#34;; cerr &lt;&lt; endl;

// Input macros
#define readVec(v, n) for (int i = 0; i &lt; n; &#43;&#43;i) cin &gt;&gt; v[i];
#define readMatrix(mat, n, m) for (int i = 0; i &lt; n; &#43;&#43;i) for (int j = 0; j &lt; m; &#43;&#43;j) cin &gt;&gt; mat[i][j];

// Output macros
#define printVec(v) for (auto x : v) cout &lt;&lt; x &lt;&lt; &#34; &#34;; cout &lt;&lt; endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }

// Matrix Macros
#define create2D(v, n, m) vector&lt;vector&lt;int&gt;&gt; v(n, vector&lt;int&gt;(m))
#define create3D(v, n, m, k) vector&lt;vector&lt;vector&lt;int&gt;&gt;&gt; v(n, vector&lt;vector&lt;int&gt;&gt;(m, vector&lt;int&gt;(k)))



bool allEqual(const vector&lt;int&gt;&amp; v) {
    for (int i = 1; i &lt; v.size(); i&#43;&#43;) {
        if (v[i] != v[0]) return false;
    }
    return true;
}

int sum_all(vi &amp;v) {
    return accumulate(all(v), 0);
}

int max_val(const vector&lt;int&gt;&amp; v) {
    return *max_element(all(v));
}

int min_val(const vector&lt;int&gt;&amp; v) {
    return *min_element(all(v));
}

string oddEven(int i, const string &amp;s1, const string &amp;s2) {
    return (i &amp; 1) ? s1 : s2;
}

vector&lt;int&gt; getDigits(int n) {
    vector&lt;int&gt; digits;
    string s = to_string(n);
    for (char c : s)
        digits.pb(c - &#39;0&#39;);
    return digits;
}

// Solve function
void solve() {
    string s;cin&gt;&gt;s;
    int n=stoi(s);
    vi v=getDigits(n);
    int x=min_val(v);
    bool ok =true;
    int cnt=0;
    int y=max_val(v);
    for (int i = v.size(); i &gt;= 0; i--)
    {
        int first=0,last=n-1;
        while(first&lt;last){
            if(v[first]!=x){
                first&#43;&#43;;
                ok=false;
            }
            if(v[last]!=x&#43;1){
                last--;
                ok=false;
            }
            if(ok=true){
                break;
            }
        }
        cnt&#43;=(last-first);
        x&#43;&#43;;
        if(x==y){
            break;
        }
    }
    cout&lt;&lt;cnt&lt;&lt;endl;
}

void solve_1(){
    string v;cin&gt;&gt;v;
    int n=v.size();
    vector&lt;pair&lt;int,int&gt;&gt; blck;
    for (int i = 0; i &lt; sz(v);)
    {   
        int j=i;
        while(j&lt;n &amp;&amp; v[j]==v[i]){
            j&#43;&#43;;
        }
        int cnter=j-i;
        blck.pb({v[i]-&#39;0&#39;,cnter});
        i=j;
    }

    int ans=0;
    for (int i = 0; i&#43;1 &lt; blck.size(); i&#43;&#43;)
    {
        int fix=blck[i].first;
        int lust=blck[i&#43;1].first;
        if(lust==fix&#43;1){
            ans&#43;=min(blck[i].second,blck[i&#43;1].second);
        }
    }
    cout&lt;&lt;ans&lt;&lt;endl;
}
// Testcase function
void test() {
    int t;
    cin &gt;&gt; t;
    while (t--) solve();
}

// Main function
int32_t main() {
    fastio();
    // test();
    solve_1();
    return 0;
}