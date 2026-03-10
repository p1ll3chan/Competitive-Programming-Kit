#include&lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;
#define int long long
#define debug(x) cout&lt;&lt;#x&lt;&lt;&#34; = &#34;&lt;&lt;(x)&lt;&lt;endl;
void solve(){
    int n,a,b;cin&gt;&gt;n&gt;&gt;a&gt;&gt;b;
    if((a%2) == (b%2)){
        cout&lt;&lt;(b-a)/2&lt;&lt;endl;
    }else{
        int min_x=min(a-1,n-b);
        cout&lt;&lt;min_x&#43;1&#43;((b-a-1)/2)&lt;&lt;endl;
    }
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