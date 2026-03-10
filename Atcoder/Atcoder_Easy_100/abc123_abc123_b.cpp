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

void solve_1() {
    int a,b,c,d,e;cin&gt;&gt;a&gt;&gt;b&gt;&gt;c&gt;&gt;d&gt;&gt;e;
    int A=0,B,C,D,E;
    int a_ord=a%10;
    a&#43;=(10-a_ord);
    //debug(29%10);
    b&#43;=a;
    int b_ord=b%10;
    b&#43;=(10-b_ord);
    c&#43;=b;
    int c_ord=c%10;
    c&#43;=(10-c_ord);
    d&#43;=c;
    int d_ord=d%10;
    d&#43;=(10-d_ord);
    e&#43;=d;
    int e_ord=e%10;
    e&#43;=(10-e_ord);
    // debug(a);
    // debug(b);
    // debug(c);
    // debug(d);
    // debug(e);
    //cout&lt;&lt;e&lt;&lt;endl;
    //debug(a%10);
}

void solve(){
    vi v(5);
    readVec(v,5);

    vi p({0,1,2,3,4});
    int minx=INT_MAX;
    do{
        int t=0;
        for (int i = 0; i &lt; 5; i&#43;&#43;)
        {
            if(t%10!=0){
                t&#43;=(10-(t%10));
            }
            t&#43;=v[p[i]];
        }

        minx=min(minx,t);
    }
    while(next_permutation(all(p)));

    cout&lt;&lt;minx&lt;&lt;endl;
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