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

#define create2D(v, n, m) vector&lt;vector&lt;int&gt;&gt; v(n, vector&lt;int&gt;(m))


double avg_v(const vector&lt;int&gt; &amp;v){
	int n=v.size();
	double sum_v=accumulate(all(v),0LL);
	double ans=sum_v/n;
	return ans;
}

void solve() {
	int n,m;cin&gt;&gt;n&gt;&gt;m;
	unordered_map&lt;int,vector&lt;int&gt;&gt; mp;
	vector&lt;pair&lt;int,double&gt;&gt; o;
	vi  v;
	for (int i = 0; i &lt; n; i&#43;&#43;)
	{
		int a,b;cin&gt;&gt;a&gt;&gt;b;
		mp[a].push_back(b);
	}



	cout&lt;&lt;fixed&lt;&lt;setprecision(20);

	for(auto &amp;p:mp){
		double x=avg_v(p.second);
		o.push_back({p.first,x});
	}
	sort(all(o));
	for (auto &amp;i:o){
		cout&lt;&lt;i.second&lt;&lt;endl;
	}
		
	
	
 }

void solve_1(){
	int n,m;cin&gt;&gt;n&gt;&gt;m;
	create2D(v,2,n);
	set&lt;int&gt; s;
	for (int i = 0; i &lt; 2; i&#43;&#43;)
	{
		for (int j = 0; j &lt; n; j&#43;&#43;)
		{
			int a,b;cin&gt;&gt;a&gt;&gt;b;
			cin&gt;&gt;v[a][b];
			s.insert(a);
		}
	}
	for(auto i:s){
		cout&lt;&lt;i&lt;&lt;endl;
	}
	for (int i = 0; i &lt; 2; i&#43;&#43;)
	{
		for (int j = 0; j &lt; n; j&#43;&#43;)
		{
			cout&lt;&lt;v[i][j]&lt;&lt;&#34; &#34;;
		}
		cout&lt;&lt;endl;
	}
	
	
	
	
}

// void test() {
// 	int t;
// 	cin &gt;&gt; t;
// 	while (t--) solve();
// }

int32_t main() {
	fastio();
	// test();
	solve();
	return 0;
}