#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;
#define rep(i,n) for (int i = 0; i &lt; (n); &#43;&#43;i)

void judge(vector&lt;int&gt; a, int l) {
    while (a.size() &amp;&amp; a.back() == l) a.pop_back();
    int n = a.size();
    if (n%2 == 1) return;
    rep(i,n/2) if (a[i]&#43;a[n-1-i] != l) return;
    cout &lt;&lt; l &lt;&lt; &#34; &#34;;
}

int main() {
    int n;
    cin &gt;&gt; n;
    vector&lt;int&gt; a(n);
    rep(i,n) cin &gt;&gt; a[i];
    sort(a.begin(), a.end());

    judge(a, a.back());
    judge(a, a[0]&#43;a.back());
    return 0;
}