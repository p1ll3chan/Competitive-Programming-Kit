#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;
#define ll long long
typedef vector&lt;int&gt; vi;
typedef pair&lt;int,int&gt; pi;
#define r(i, a, b) for (int i = a; i &lt; b; &#43;&#43;i)
#define f first
#define s second
#define pb push_back


int main()
{
    string s,t;
    cin&gt;&gt;s&gt;&gt;t;
    r(w,1,(int)s.size()){
        r(c,0,w){
            string now=&#34;&#34;;
            for(int i=c;i&lt;(int)s.size();i&#43;=w){
                now&#43;=s[i];
            }
            if(now==t){
                cout&lt;&lt;&#34;Yes&#34;;
                return 0;
            }
        }
    }
    cout&lt;&lt;&#34;No&#34;;
}