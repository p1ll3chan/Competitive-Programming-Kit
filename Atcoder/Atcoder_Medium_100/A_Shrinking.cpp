#include <bits/stdc++.h>
using namespace std;

// Macros
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define YESNO(x) cout << ((x) ? "YES" : "NO") << endl

// Debugging
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debugArr(arr) for (auto v : arr) cerr << v << " "; cerr << endl;

// Input macros
#define readVec(v, n) for (int i = 0; i < n; ++i) cin >> v[i];
#define readMatrix(mat, n, m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mat[i][j];

// Output macros
#define printVec(v) for (auto x : v) cout << x << " "; cout << endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }

// Matrix Macros
#define create2D(v, n, m) vector<vector<int>> v(n, vector<int>(m))
#define create3D(v, n, m, k) vector<vector<vector<int>>> v(n, vector<vector<int>>(m, vector<int>(k)))

// Utility Functions
int sumN(int n) {
    return 1LL * n * (n + 1) / 2;
}

int getMax(int high, int sum) {
    return max(high, sum);
}

int cyclicDiff(char a, char b) {
    return min(abs(a - b), 26 - abs(a - b));
}

void simulate(vector<int>& v, int a1, int a2, int d[]) {
    int amt = min(v[a1], d[a2] - v[a2]);
    v[a1] -= amt;
    v[a2] += amt;
}

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void countDigits(int n, vector<int>& count) {
    while (n > 0) {
        count[n % 10]++;
        n /= 10;
    }
}

int countUnique(vector<int>& v, int n) {
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
        freq[v[i]]++;
    int x = 0;
    for (int i = 0; i <= n; i++)
        x += freq[i] / 2;
    return x;
}

vector<int> prefixSum(const vector<int>& v) {
    int n = v.size();
    vector<int> psum(n);
    psum[0] = v[0];
    for (int i = 1; i < n; i++)
        psum[i] = psum[i - 1] + v[i];
    return psum;
}

void permute(int index, string &s, vector<string> &ans) {
    if (index == (int)s.size()) {
        ans.pb(s);
        return;
    }
    for (int i = index; i < (int)s.size(); i++) {
        swap(s[index], s[i]);
        permute(index + 1, s, ans);
        swap(s[index], s[i]);
    }
}

void permute(int index, vector<int> &nums, vector<vector<int>> &ans) {
    if (index == (int)nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < (int)nums.size(); ++i) {
        bool shouldSwap = true;
        for (int j = index; j < i; ++j) {
            if (nums[j] == nums[i]) {
                shouldSwap = false;
                break;
            }
        }
        if (!shouldSwap) continue;
        swap(nums[index], nums[i]);
        permute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}

int binarySearch(vector<int>& a, int b) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] <= b)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

int countOccurrence(vector<int>& v, int x) {
    return upper_bound(all(v), x) - lower_bound(all(v), x);
}

int F(int x) {
    if (x == 0) return 1;
    return x * F(x - 1);
}

int P(int x, int y) {
    if (y > x) return 0;
    return F(x) / F(x - y);
}

int C(int x, int y) {
    if (y > x) return 0;
    return F(x) / (F(y) * F(x - y));
}

vector<int> intToVector(int num) {
    vector<int> v;
    while (num > 0) {
        v.pb(num % 10);
        num /= 10;
    }
    reverse(all(v));
    return v;
}

int vectorToInt(const vector<int>& v) {
    int result = 0;
    for (int i = 0; i < v.size(); i++) {
        result = result * 10 + v[i];
    }
    return result;
}

vector<int> getDigits(int n) {
    vector<int> digits;
    string s = to_string(n);
    for (char c : s)
        digits.pb(c - '0');
    return digits;
}

vector<string> getStrings(const string& v) {
    vector<string> result;
    for (int i = 0; i < v.size(); ++i) {
        result.pb(string(1, v[i]));
    }
    return result;
}

bool power_2(int n) {
    return n && !(n & (n - 1));
}

int findMEX(const vector<int>& v) {
    unordered_set<int> seen;
    for (int num : v)
        if (num >= 0) seen.insert(num);
    int mex = 0;
    while (seen.count(mex)) ++mex;
    return mex;
}

int mostFrequentElement(vector<int>& v) {
    unordered_map<int, int> freq;
    for (int num : v) freq[num]++;
    int maxCount = 0, mostFrequent = v[0];
    for (auto& [num, cnt] : freq) {
        if (cnt > maxCount) {
            maxCount = cnt;
            mostFrequent = num;
        }
    }
    return mostFrequent;
}

string mostFrequentString(vector<string>& v) {
    unordered_map<string, int> freq;
    for (string& s : v) freq[s]++;
    int maxCount = 0;
    string mostFrequent;
    for (auto& [str, cnt] : freq) {
        if (cnt > maxCount) {
            maxCount = cnt;
            mostFrequent = str;
        }
    }
    return mostFrequent;
}

bool allEqual(const vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] != v[0]) return false;
    }
    return true;
}

int sum_all(vi &v) {
    return accumulate(all(v), 0);
}

int max(const vector<int>& v) {
    return *max_element(all(v));
}

int min(const vector<int>& v) {
    return *min_element(all(v));
}

string oddEven(int i, const string &s1, const string &s2) {
    return (i & 1) ? s1 : s2;
}

vi merge_2(const vi &a, const vi &b) {
    vi v = a;
    v.insert(v.end(), all(b));
    return v;
}
/*
max_block = 0
current_block = 0

for char in s:
    if char != c:
        current_block++
    else:
        max_block = max(max_block, current_block)
        current_block = 0

max_block = max(max_block, current_block)
answer = min(answer, max_block)

*/
// Solve function
void solve() {
    string s;cin>>s;
    int ans=s.size();
    for (char i = 'a'; i <= 'z'; i++)
    {
        int max_b=0;
        int crr_b=0;
        for(char x:s){
            if(x!=i){
                crr_b++;
            }else{
                max_b=max(max_b,crr_b);
                crr_b=0;
            }
        }
        max_b=max(max_b,crr_b);
        ans=min(ans,max_b);
    }
    cout<<ans<<endl;
}

// Testcase function
void test() {
    int t;
    cin >> t;
    while (t--) solve();
}

// Main function
int32_t main() {
    fastio();
    // test();
    solve();
    return 0;
}