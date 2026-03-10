#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

// Macros
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


// Solve function
void solve() {
    int n;
    cin &gt;&gt; n;
    create2D(v,n,n);
    // int add=1;
    // for (int i = 0; i &lt; n; i&#43;&#43;)
    // {
    //     for (int j = 0; j &lt; n; j&#43;&#43;)
    //     {
    //         v[i][j]=0;
    //     }
        
    // }
    //v[0,(n-1)/2]=add;
    int r=0;
    int c=n/2;
    for (int i = 1; i &lt;= n*n; i&#43;&#43;)
    {
        v[r][c]=i;
            if(v[(r-1&#43;n)%n][(c&#43;1)%n]!=0){
                r = (r &#43; 1) % n;
            }else{
                r=(r-1&#43;n)%n;
                c=(c&#43;1)%n;
            }
        
    }



    //Printer
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        for (int j = 0; j &lt; n; j&#43;&#43;)
        {
           cout&lt;&lt;v[i][j]&lt;&lt;&#34; &#34;;
        }
        cout&lt;&lt;endl;
    }
    
    
        
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
    solve();
    return 0;
}