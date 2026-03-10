#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

int main() {
    int N, K;
    cin &gt;&gt; N &gt;&gt; K;
    
    vector&lt;int&gt; cards(N);
    for (int i = 0; i &lt; N; i&#43;&#43;) {
        cin &gt;&gt; cards[i];
    }
    
    vector&lt;int&gt; result;
    
    for (int i = N - K; i &lt; N; i&#43;&#43;) {
        result.push_back(cards[i]);
    }

    for (int i = 0; i &lt; N - K; i&#43;&#43;) {
        result.push_back(cards[i]);
    }
    
    for (int card : result) {
        cout &lt;&lt; card &lt;&lt; &#34; &#34;;
    }
    cout &lt;&lt; endl;
    
    return 0;
}