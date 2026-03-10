#include &lt;bits/stdc&#43;&#43;.h&gt;
#include &lt;cctype&gt;
using namespace std;
#define ll long long
typedef vector&lt;int&gt; vi;
typedef pair&lt;int, int&gt; pi;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define r(i, a, b) for (int i = a; i &lt; b; &#43;&#43;i)

void solve() {
    string s;
    cin &gt;&gt; s;
    int uc = 0, lc = 0;  // Initialize counters for uppercase and lowercase letters

    // Count the number of uppercase and lowercase characters
    r(i, 0, (int)s.size()) {
        if (isupper(s[i])) {
            uc&#43;&#43;;
        } else if (islower(s[i])) {
            lc&#43;&#43;;
        }
    }

    // Convert the string to uppercase if there are more or equal lowercase characters
    // Otherwise, convert it to lowercase
    if (uc &gt;= lc) {
        r(i, 0, (int)s.size()) {
            s[i] = toupper(s[i]);
        }
    } else {
        r(i, 0, (int)s.size()) {
            s[i] = tolower(s[i]);
        }
    }

    cout &lt;&lt; s &lt;&lt; endl;
}

int main() {
    solve();
    return 0;
}
