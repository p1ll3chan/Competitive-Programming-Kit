/*
██████╗ ██╗██╗     ██╗     ██████╗  ███████╗ ██╗  ██  █████╗ ███╗   ██╗
██╔══██╗██║██║     ██║       ╔══██╗ ██═════╝ ██║  ██║██╔══██╗████╗  ██║
██████╔╝██║██║     ██║       ████╔╝ ██║      ███████║███████║██╔██╗ ██║
██╔═══╝ ██║██║     ██║       ╔══██╗ ██║      ██╔══██║██╔══██║██║╚██╗██║
██║     ██║███████╗███████╗██████╔╝ ███████╗ ██║  ██║██║  ██║██║ ╚████║
╚═╝     ╚═╝╚══════╝╚══════╝╚═════╝  ╚══════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝             
		🚀 GitHub: https://github.com/p1ll3chan

<----------------------------------------------------------------------->
		<...Ｔｈｉｎｋ　ｌｉｋｅ　ａ　ｐｏｅｔ．  
			Ｃｏｄｅ　ｌｉｋｅ　ａ　ｂｅａｓｔ...>
<----------------------------------------------------------------------->
*/

#include <bits/stdc++.h>
using namespace std;

// Macros
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Debugging
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debugArr(arr) for (auto v : arr) cerr << v << " "; cerr << endl;

// Input macros
#define readVec(v, n) for (int i = 0; i < n; ++i) cin >> v[i];
#define readMatrix(mat, n, m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mat[i][j];

// Output macros
#define printVec(v) for (auto x : v) cout << x << " "; cout << endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }

// 2D & 3D Matrix Macros
#define create2D(n, m) vector<vector<int>>(n, vector<int>(m))
#define create3D(n, m, k) vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(k)))

// Utility Functions

// Sum of first N natural numbers
ll sumN(int n) { return 1LL * n * (n + 1) / 2; }

// Maximum of two values
int getMax(int high, int sum) { return max(high, sum); }

// ASCII cyclic difference
int cyclicDiff(char a, char b) { return min(abs(a - b), 26 - abs(a - b)); }

// Simulation + Greedy (Bucket Pouring)
void simulate(vector<int>& v, int a1, int a2, int d[]) {
    int amt = min(v[a1], d[a2] - v[a2]);
    v[a1] -= amt;
    v[a2] += amt;
}

// GCD
int gcd(int a, int b) {
    while (b) { int r = a % b; a = b; b = r; }
    return a;
}

// Count digit frequency
void countDigits(int n, vector<int>& count) {
    while (n > 0) { count[n % 10]++; n /= 10; }
}

// Count frequency of unique values
int countUnique(vector<int>& v, int n) {
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++) freq[v[i]]++;
    int x = 0;
    for (int i = 0; i <= n; i++) x += freq[i] / 2;
    return x;
}

// Prefix Sum
vector<int> prefixSum(const vector<int>& v) {
    int n = v.size();
    vector<int> psum(n);
    psum[0] = v[0];
    for (int i = 1; i < n; i++) psum[i] = psum[i - 1] + v[i];
    return psum;
}

// Generate permutations
void permute(int index, string &s, vector<string> &ans) {
    if (index == s.size()) { ans.pb(s); return; }
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        permute(index + 1, s, ans);
        swap(s[index], s[i]);
    }
}

// Binary Search
int binarySearch(vector<int>& a, int b) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] <= b) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// Count of a number in an array
int countOccurrence(vector<int>& v, int x) {
    return upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x);
}

// Two-Pointer Algorithm
void twoPointers(vector<int>& v, int target) {
    int l = 0, r = v.size() - 1;
    while (l < r) {
        int sum = v[l] + v[r];
        if (sum == target) { cout << l << " " << r << endl; return; }
        if (sum < target) l++;
        else r--;
    }
}

// Permutation & Combination
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

// Integer to vector of digits
vector<int> intToVector(int num) {
    vector<int> v;
    while (num > 0) {
        v.push_back(num % 10);
        num /= 10;
    }
    reverse(v.begin(), v.end());
    return v;
}

// Vector of digits to integer
int vectorToInt(const vector<int>& v) {
    int result = 0;
    for (int i = 0; i < v.size(); i++) {
        result = result * 10 + v[i];
    }
    return result;
}

// Integer to digit vector using string
vector<int> getDigits(int n) {
    vector<int> digits;
    string s = to_string(n);
    for (char c : s) digits.push_back(c - '0');
    return digits;
}

// Convert string to array of single-character strings
vector<string> getStrings(const string& v) {
    vector<string> result;
    for (int i = 0; i < v.size(); ++i) {
        result.push_back(string(1, v[i]));
    }
    return result;
}

// Check if a number is a power of 2
bool power_2(int n) {
    return n && !(n & (n - 1));
}

// MEX Based Function
int findMEX(const vector<int>& v) {
    unordered_set<int> seen;
    for (int num : v) if (num >= 0) seen.insert(num);
    int mex = 0;
    while (seen.count(mex)) ++mex;
    return mex;
}

// Solve function
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    readVec(v, n);

    // your logic here
}

// Test function
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


