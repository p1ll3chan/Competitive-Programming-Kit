#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

#define ll long long
typedef vector&lt;int&gt; vi;
typedef vector&lt;vector&lt;int&gt;&gt; vii;
typedef pair&lt;int,int&gt; pi;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define fp(a,b) for (int i = a; i &lt; b; &#43;&#43;i)
#define fn(a,b) for (int i = a; i &lt; b; --i)

// Function to solve each test case
// test case

// 2D Cases
// vii v(n, vi(m)); // for n and m integers in 2D

void solve() {
    int n;cin&gt;&gt;n;
    if(n%2==0){
        cout&lt;&lt;n/2&lt;&lt;endl;
    }else{
        cout&lt;&lt;ceil(n/2)&#43;1&lt;&lt;endl;
    }
}

void test() {
 int t;
 cin &gt;&gt; t;
 while (t--) {
     solve();
 }
}

int32_t main()
{
    // test();
    solve();
    
    return 0;
}