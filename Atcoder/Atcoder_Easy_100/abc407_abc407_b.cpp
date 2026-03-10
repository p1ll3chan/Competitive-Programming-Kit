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

int fact=6*5*4*3*2*1;


void solve() {
    int n,m;cin&gt;&gt;n&gt;&gt;m;
    int x=n/m;
    if(x&lt;=0){
        cout&lt;&lt;1&lt;&lt;endl;
        return;
    }
    // if(n==m){
    //     cout&lt;&lt;1&lt;&lt;endl;
    //     return;
    // }
    cout&lt;&lt;x&lt;&lt;endl;
}



void solve1(){
    vector&lt;int&gt; v {1,2,3,4,5,6};
    int x,y;cin&gt;&gt;x&gt;&gt;y;
    //int cnt=0;
    int cnt1=0;
    for (int i = 0; i &lt; 6; i&#43;&#43;)
    {
        for (int j = 0; j &lt; 6; j&#43;&#43;)
        {
            // if(v[i]&#43;v[j]&gt;=x){
            //     cnt&#43;&#43;;
            // }
            // if(abs(v[i]-v[j])&gt;=y){
            //     cnt1&#43;&#43;;
            // }
            if(v[i]&#43;v[j]&gt;=x  || abs(v[i]-v[j])&gt;=y){
                cnt1&#43;&#43;;
            }
        }
        
    }
    cout&lt;&lt; fixed &lt;&lt; setprecision(30) &lt;&lt;(double)cnt1/36&lt;&lt;endl;
    
}

void solve2(){
    
}

void test() {
    int t;
    cin &gt;&gt; t;
    while (t--) solve();
}

int32_t main() {
    fastio();
    //test();
    //solve();
    solve1();
    return 0;
}