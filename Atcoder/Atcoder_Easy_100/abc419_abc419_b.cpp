#include &lt;bits/stdc&#43;&#43;.h&gt;
using namespace std;

// Macros
#define ll long long
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

// Debugging
#define debug(x) cerr &lt;&lt; #x &lt;&lt; &#34; = &#34; &lt;&lt; (x) &lt;&lt; endl;
#define debugArr(arr) for (auto v : arr) cerr &lt;&lt; v &lt;&lt; &#34; &#34;; cerr &lt;&lt; endl;

// Input macros
#define readVec(v, n) for (int i = 0; i &lt; n; &#43;&#43;i) cin &gt;&gt; v[i];
#define readMatrix(mat, n, m) for (int i = 0; i &lt; n; &#43;&#43;i) for (int j = 0; j &lt; m; &#43;&#43;j) cin &gt;&gt; mat[i][j];

// Output macros
#define printVec(v) for (auto x : v) cout &lt;&lt; x &lt;&lt; &#34; &#34;; cout &lt;&lt; endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }

// Matrix Macros
#define create2D(v, n, m) vector&lt;vector&lt;int&gt;&gt; v(n, vector&lt;int&gt;(m))
#define create3D(v, n, m, k) vector&lt;vector&lt;vector&lt;int&gt;&gt;&gt; v(n, vector&lt;vector&lt;int&gt;&gt;(m, vector&lt;int&gt;(k)))

// Utility Functions
ll sumN(int n) {
    return 1LL * n * (n &#43; 1) / 2;
}

int getMax(int high, int sum) {
    return max(high, sum);
}

int cyclicDiff(char a, char b) {
    return min(abs(a - b), 26 - abs(a - b));
}

void simulate(vector&lt;int&gt;&amp; v, int a1, int a2, int d[]) {
    int amt = min(v[a1], d[a2] - v[a2]);
    v[a1] -= amt;
    v[a2] &#43;= amt;
}

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void countDigits(int n, vector&lt;int&gt;&amp; count) {
    while (n &gt; 0) {
        count[n % 10]&#43;&#43;;
        n /= 10;
    }
}

int countUnique(vector&lt;int&gt;&amp; v, int n) {
    vector&lt;int&gt; freq(n &#43; 1, 0);
    for (int i = 0; i &lt; n; i&#43;&#43;)
        freq[v[i]]&#43;&#43;;
    int x = 0;
    for (int i = 0; i &lt;= n; i&#43;&#43;)
        x &#43;= freq[i] / 2;
    return x;
}

vector&lt;int&gt; prefixSum(const vector&lt;int&gt;&amp; v) {
    int n = v.size();
    vector&lt;int&gt; psum(n);
    psum[0] = v[0];
    for (int i = 1; i &lt; n; i&#43;&#43;)
        psum[i] = psum[i - 1] &#43; v[i];
    return psum;
}

void permute(int index, string &amp;s, vector&lt;string&gt; &amp;ans) {
    if (index == s.size()) {
        ans.pb(s);
        return;
    }
    for (int i = index; i &lt; s.size(); i&#43;&#43;) {
        swap(s[index], s[i]);
        permute(index &#43; 1, s, ans);
        swap(s[index], s[i]);
    }
}

void permute(int index, vector&lt;int&gt; &amp;nums, vector&lt;vector&lt;int&gt;&gt; &amp;ans) {
    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i &lt; nums.size(); &#43;&#43;i) {
        bool shouldSwap = true;
        for (int j = index; j &lt; i; &#43;&#43;j) {
            if (nums[j] == nums[i]) {
                shouldSwap = false;
                break;
            }
        }
        if (!shouldSwap) continue;
        swap(nums[index], nums[i]);
        permute(index &#43; 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}

int binarySearch(vector&lt;int&gt;&amp; a, int b) {
    int lo = 0, hi = a.size();
    while (lo &lt; hi) {
        int mid = lo &#43; (hi - lo) / 2;
        if (a[mid] &lt;= b)
            lo = mid &#43; 1;
        else
            hi = mid;
    }
    return lo;
}

int countOccurrence(vector&lt;int&gt;&amp; v, int x) {
    return upper_bound(all(v), x) - lower_bound(all(v), x);
}

int F(int x) {
    if (x == 0) return 1;
    return x * F(x - 1);
}

int P(int x, int y) {
    if (y &gt; x) return 0;
    return F(x) / F(x - y);
}

int C(int x, int y) {
    if (y &gt; x) return 0;
    return F(x) / (F(y) * F(x - y));
}

vector&lt;int&gt; intToVector(int num) {
    vector&lt;int&gt; v;
    while (num &gt; 0) {
        v.pb(num % 10);
        num /= 10;
    }
    reverse(all(v));
    return v;
}

int vectorToInt(const vector&lt;int&gt;&amp; v) {
    int result = 0;
    for (int i = 0; i &lt; v.size(); i&#43;&#43;) {
        result = result * 10 &#43; v[i];
    }
    return result;
}

vector&lt;int&gt; getDigits(int n) {
    vector&lt;int&gt; digits;
    string s = to_string(n);
    for (char c : s)
        digits.pb(c - &#39;0&#39;);
    return digits;
}

vector&lt;string&gt; getStrings(const string&amp; v) {
    vector&lt;string&gt; result;
    for (int i = 0; i &lt; v.size(); &#43;&#43;i) {
        result.pb(string(1, v[i]));
    }
    return result;
}

bool power_2(int n) {
    return n &amp;&amp; !(n &amp; (n - 1));
}

int findMEX(const vector&lt;int&gt;&amp; v) {
    unordered_set&lt;int&gt; seen;
    for (int num : v)
        if (num &gt;= 0) seen.insert(num);
    int mex = 0;
    while (seen.count(mex)) &#43;&#43;mex;
    return mex;
}

int mostFrequentElement(vector&lt;int&gt;&amp; v) {
    unordered_map&lt;int, int&gt; freq;
    for (int num : v) freq[num]&#43;&#43;;
    int maxCount = 0, mostFrequent = v[0];
    for (auto&amp; [num, cnt] : freq) {
        if (cnt &gt; maxCount) {
            maxCount = cnt;
            mostFrequent = num;
        }
    }
    return mostFrequent;
}

string mostFrequentString(vector&lt;string&gt;&amp; v) {
    unordered_map&lt;string, int&gt; freq;
    for (string&amp; s : v) freq[s]&#43;&#43;;
    int maxCount = 0;
    string mostFrequent;
    for (auto&amp; [str, cnt] : freq) {
        if (cnt &gt; maxCount) {
            maxCount = cnt;
            mostFrequent = str;
        }
    }
    return mostFrequent;
}

bool allEqual(const vector&lt;int&gt;&amp; v) {
    for (int i = 1; i &lt; v.size(); i&#43;&#43;) {
        if (v[i] != v[0]) return false;
    }
    return true;
}

int sum_all(vi &amp;v) {
    return accumulate(all(v), 0);
}

int max(const vector&lt;int&gt;&amp; v) {
    return *max_element(all(v));
}

int min(const vector&lt;int&gt;&amp; v) {
    return *min_element(all(v));
}

string oddEven(int i, const string &amp;s1, const string &amp;s2) {
    return (i &amp; 1) ? s1 : s2;
}

vi merge_2(const vi &amp;a, const vi &amp;b) {
    vi v = a;
    v.insert(v.end(), all(b));
    return v;
}
vector&lt;int&gt; v;
// Solve function
void solve() {
    int n;cin&gt;&gt;n;
    
    if(n==1){
        int x;cin&gt;&gt;x;
        v.pb(x);
        sort(all(v));
    }
    else if(n==2){
        cout&lt;&lt;v[0]&lt;&lt;endl;
        v.erase(v.begin());
    }
}

// Testcase function
void test() {
    int t;
    cin &gt;&gt; t;
    while (t--) solve();
}

// Main function
int32_t main() {
    fastio();
    test();
    //solve();
    return 0;
}