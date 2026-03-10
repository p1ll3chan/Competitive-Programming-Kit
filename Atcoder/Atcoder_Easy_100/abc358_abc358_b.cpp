#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;
#define ll long long
typedef vector&lt;int&gt; vi;
typedef pair&lt;int,int&gt; pi;
#define f first
#define s second
#define pb push_back
#define r(i, a, b) for (int i = a; i &lt; b; &#43;&#43;i)



int main()
{
    int n,a;
    cin&gt;&gt;n&gt;&gt;a;
    int pre=0;
    r(i,0,n){
        int t;
        cin&gt;&gt;t;;
        int man=max(pre,t)&#43;a;;
        cout&lt;&lt;man&lt;&lt;&#34;\n&#34;;
        pre=man;
    }

    

return 0;
}