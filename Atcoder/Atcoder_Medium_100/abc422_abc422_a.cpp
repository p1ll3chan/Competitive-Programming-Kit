#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;



void solve(){
  string s;cin&gt;&gt;s;
  int first_s=s[0]-&#39;0&#39;;
  int next_s=s[2]-&#39;0&#39;;
  if(next_s&lt;8) next_s&#43;&#43;;
  else if(first_s&lt;8 &amp;&amp; next_s==8){
   first_s&#43;&#43;; 
   next_s=1; 
  }
   cout&lt;&lt;first_s&lt;&lt;&#34;-&#34;&lt;&lt;next_s&lt;&lt;endl;
} 


void test(){
  int t;cin&gt;&gt;t;
  while(t--){
    solve();
  }
}

int main(){
  solve();
  //test();

  return 0;
}