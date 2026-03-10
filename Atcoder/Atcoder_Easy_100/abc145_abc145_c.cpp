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




double dist(int a,int b,vector&lt;pair&lt;double,double&gt;&gt;&amp; ans){
    double dx=ans[a].first-ans[b].first;
    double dy=ans[a].second-ans[b].second;

    return sqrt(dx*dx&#43;dy*dy);
}


void solve() {
    int n;
    cin &gt;&gt; n;
    vector&lt;pair&lt;double,double&gt;&gt; town(n);

    // for(auto i:town){
    //     cout&lt;&lt;i.first&lt;&lt;i.second;
    // }

    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        cin&gt;&gt;town[i].first&gt;&gt;town[i].second;
    }
    

    vi order(n);
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        order[i]=i;
    }
    double ans=0;
    int cnt=0;
    
    do{
        double path=0;
        for (int i = 0; i &lt; n-1; i&#43;&#43;)
        {   
            path&#43;=dist(order[i],order[i&#43;1],town);
        }
        ans&#43;=path;
        cnt&#43;&#43;;
        

    }while(next_permutation(all(order)));


    double sum=ans/cnt;
    cout&lt;&lt;fixed&lt;&lt;setprecision(10)&lt;&lt;sum&lt;&lt;endl;
}


// void solve() {
//     int n;
//     cin &gt;&gt; n;
//     vector&lt;pair&lt;int,int&gt;&gt; v(n);
//     for(auto [a,b] : v){
//         int x,y;cin&gt;&gt;x&gt;&gt;y;
//         a=x;b=y;
//     }
//     int sum=0;
//     for(auto i:v){
//         for(auto j:v){
//             int ans=(v[i].first &#43; v[j].second)*(v[i].first &#43; v[j].second);
//             ans=sqrt(ans);
//             sum&#43;=ans;
//         }
//     }
//     cout&lt;&lt;sum/fact(n)&lt;&lt;endl;
    
// }

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