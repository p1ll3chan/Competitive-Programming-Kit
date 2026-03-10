#include &lt;bits/stdc&#43;&#43;.h&gt;
#include &lt;set&gt;
using namespace std;


//#define int long long
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

bool binarySearch1(vi &amp;v,int &amp;x){
    int n=v.size();
    int left=0;
    int right=n-1;
    while(left&lt;=right){
        int mid=left&#43;(right-left)/2;
        if(v[mid]==x){
            return true;
        }else if(v[mid]&lt;x){
            left=mid&#43;1;
        }else{
            right=mid-1;
        }
    }
    return false;
}



// bool binarySearch1(std::set&lt;long long int&gt;&amp; s, const long long x) { 
//     auto it = s.lower_bound(x);
//     if (it != s.end() &amp;&amp; *it == x) return true; 

//     while (s.find(x, std::prev(it)) == prev(s.end()) || 
//           (*std::prev(it) &gt; x != s.end())) {    
//         --it;                             
//     } 
    
//     return false; 
// }

void solve() {
    int sum;cin&gt;&gt;sum;
    int n;cin &gt;&gt; n;
    vi v(n);
    readVec(v, n);
    // Your logic here
    int q;cin&gt;&gt;q;
    vi v1;
    for (int i = 0; i &lt; q; i&#43;&#43;)
    {
        int n;cin&gt;&gt;n;
        if(binarySearch1(v1,v[n-1])){
            sum-=v[n-1];
            cout&lt;&lt;sum&lt;&lt;&#34; &#34;&lt;&lt;&#34;-&#34;&lt;&lt;&#34; &#34;&lt;&lt;v[n-1]&lt;&lt;endl;
        }else{
            sum&#43;=v[n-1];
            cout&lt;&lt;sum&lt;&lt;&#34; &#34;&lt;&lt;v[n-1]&lt;&lt;endl;
        }
        v1.pb(v[n-1]);
        
    }
}

void solve1(){

    int sum; cin &gt;&gt; sum;
    int n; cin &gt;&gt; n;
    vi w(n);
    readVec(w, n);

    int q; cin &gt;&gt; q;
    vector&lt;bool&gt; attached(n, false);

    while (q--) {
        int p; 
        cin &gt;&gt; p; 
        p--; // convert to 0-index

        if (attached[p]) {
            sum -= w[p];
            attached[p] = false;
        } else {
            sum &#43;= w[p];
            attached[p] = true;
        }

        cout &lt;&lt; sum &lt;&lt; &#34;\n&#34;;
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
    solve1();
    return 0;
}