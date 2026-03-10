#include&lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;
#define int long long
#define debug(x) cout&lt;&lt;#x&lt;&lt;&#34; = &#34;&lt;&lt;(x)&lt;&lt;endl;
void solve(){
    int n;cin&gt;&gt;n;
    int min_x=LLONG_MAX;
    for (int i = 1; i*i &lt;= n; i&#43;&#43;)
    {
        if(n%i==0){
            int x=n/i;
            min_x=min(min_x,x);
            // debug(i)
            // debug(n/i)
            // debug(min_x)
            // debug(&#34;=&#34;)
        }
        
        
    }
    int did=n/min_x;
    int ans=(did-1)&#43;(min_x-1);
    cout&lt;&lt;ans&lt;&lt;endl;
    //debug(min_x)
    
}

void test(){
    int t;cin&gt;&gt;t;
    while(t--){
        solve();
    }
}


int32_t main(){
    //test();
    solve();
    return 0;
}