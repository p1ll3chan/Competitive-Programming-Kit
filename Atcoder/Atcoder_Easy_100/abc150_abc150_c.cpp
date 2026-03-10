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


void permute(int index, vector&lt;int&gt; &amp;nums, vector&lt;vector&lt;int&gt;&gt; &amp;ans) {
	if (index == (int)nums.size()) {
		ans.push_back(nums);
		return;
	}
	for (int i = index; i &lt; (int)nums.size(); &#43;&#43;i) {
		bool shouldSwap = true;
		for (int j = index; j &lt; i; &#43;&#43;j) {
			if (nums[j] == nums[i]) {
				shouldSwap = false;
				break;
			}
		}
		if (!shouldSwap) continue;
		swap(nums[index], nums[i]);
		permute(index &#43; 1, nums, ans);
		swap(nums[index], nums[i]);
	}
}


void solve() {
    int n;cin&gt;&gt;n;
    vi a(n);
    readVec(a,n);
    vi b(n);
    readVec(b,n);
    vi counter;
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        counter.pb(i&#43;1);
    }
    
    int i=0,a_c=-1,b_c=-1;
    do{
        bool ok=true;
        fp(i,0,n)
            if(a[i]!=counter[i]) ok=false;
        if(ok) a_c=i;
        ok =true;
        fp(i,0,n)
            if(b[i]!=counter[i]) ok=false;
        if(ok) b_c=i;
        i&#43;&#43;;
    }while (next_permutation(all(counter)));
    cout&lt;&lt;abs(a_c-b_c)&lt;&lt;endl;
    //printVec(a);
    
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