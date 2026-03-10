#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

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
#define debug(x) cerr &lt;&lt; #x &lt;&lt; &#34; = &#34; &lt;&lt; (x) &lt;&lt; endl;
#define debugArr(arr) for (auto v : arr) cerr &lt;&lt; v &lt;&lt; &#34; &#34;; cerr &lt;&lt; endl;
#define readVec(v, n) for (int i = 0; i &lt; n; &#43;&#43;i) cin &gt;&gt; v[i];
#define readMatrix(mat, n, m) for (int i = 0; i &lt; n; &#43;&#43;i) for (int j = 0; j &lt; m; &#43;&#43;j) cin &gt;&gt; mat[i][j];
#define printVec(v) for (auto x : v) cout &lt;&lt; x &lt;&lt; &#34; &#34;; cout &lt;&lt; endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }
#define fp(i, a, b) for (int i = (a); i &lt; (b); &#43;&#43;i)

int mostFrequentElement(vector&lt;int&gt;&amp; v) {
    unordered_map&lt;int, int&gt; freq;
    for (int num : v) freq[num]&#43;&#43;;
    int maxCount = 0, mostFrequent = v[0];
    for (auto&amp; [num, cnt] : freq) {
        if (cnt &gt;= maxCount) {
            maxCount = cnt;
            mostFrequent = num;
        }
    }
    return mostFrequent;
}


void solve_1(){
    int n,x,y;cin&gt;&gt;n&gt;&gt;x&gt;&gt;y;
    vi v(n);
    readVec(v,n);
    int max_val=0;
    int max_limit=0;
    // int got=0;
    // int sum_up=0;
    vi listed;
    for (int j = 0; j &lt; n; j&#43;&#43;){
        for (int i = 0; i &lt;= v[j]; i&#43;&#43;){
        int ans = x*(v[j]-i)&#43;y*i;
        listed.pb(ans);
        }
    }
    sort(listed.rbegin(),listed.rend());
    //printVec(listed);
    //cout&lt;&lt;mostFrequentElement(listed)&lt;&lt;endl;
    int value=mostFrequentElement(listed);



    int got=0;
    int sum_up=0;
    vi res;
    for (int j = 0; j &lt; n; j&#43;&#43;){
        for (int i = 0; i &lt;= v[j]; i&#43;&#43;){
        int ans = x*(v[j]-i)&#43;y*i;
        if(ans==value) {
            res.pb(i);
        }
        
        }
        //sum_up&#43;=got;
    }
    // cout&lt;&lt;sum_up&lt;&lt;endl;
    //printVec(res);
    int sum_all=accumulate(all(res),0);
    cout&lt;&lt;sum_all&lt;&lt;endl;

}


void solve_2(){
    int n,x,y;cin&gt;&gt;n&gt;&gt;x&gt;&gt;y;
    vi v(n);
    readVec(v,n);
    int minx=*min_element(all(v));
    int sum=0;
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        int diff=(v[i]-minx)*y;
        int val=y-x;
        if(diff%val!=0){
            cout&lt;&lt;-1&lt;&lt;endl;
            return;
        }
        int val_is=diff/val;
        if(val_is&gt;v[i]){
            cout&lt;&lt;-1&lt;&lt;endl;
            return;
        }
        sum&#43;=(v[i]-val_is);
    }
    cout&lt;&lt;sum&lt;&lt;endl;
}
void test() {
    int t;
    cin &gt;&gt; t;
    // while (t--) solve_1();
    while (t--) solve_2();
}

int32_t main() {
    fastio();
    // test();
    solve_2();
    return 0;
}