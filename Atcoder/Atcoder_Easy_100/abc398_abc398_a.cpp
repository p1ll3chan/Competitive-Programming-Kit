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
#define fn(a,b) for (int i = a; i &gt; b; --i)
#define sum_all(x) accumulate((x).begin(), (x).end(), 0LL)
 
 int paln(int n,vector&lt;string&gt; &amp;v){
    
    for (int i = 0; i &lt; n; i&#43;&#43;)
    {
        v.push_back(&#34;-&#34;);
    }
    return 0;
    
 }
 
void solve() {
    int n;cin&gt;&gt;n;
    vector&lt;string&gt; v;
    int mid=n/2;
    if(n%2==0){
        paln(n,v);
        v[mid]=&#34;=&#34;;
        v[mid-1]=&#34;=&#34;;
    }else{
        paln(n,v);
        v[mid]=&#34;=&#34;;
    }
    for(string i:v){
        cout&lt;&lt;i;
    }
    
    
}
 
 
 
int32_t main() {
    solve();
    return 0;
}
