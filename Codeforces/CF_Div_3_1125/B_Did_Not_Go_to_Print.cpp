#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define sz(x) (int)((x).size())
#define pb push_back
#define vi vector<int>
#define rall(c) c.rbegin(),c.rend()
#define vii vector<vector<int>>
#define pii pair<int, int>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define YESNO(x) cout << ((x) ? "YES" : "NO") << endl
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debugArr(arr) for (auto v : arr) cerr << v << " "; cerr << endl;
#define readVec(v, n) for (int i = 0; i < n; ++i) cin >> v[i];
#define readMatrix(mat, n, m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mat[i][j];
#define printVec(v) for (auto x : v) cout << x << " "; cout << endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }
#define fp(i, a, b) for (int i = (a); i < (b); ++i)

/*
----
Problem:

My Intuition:

Approach 1:

Why Failed:

Approach 2:

Example Process:

Final Learning:

------
*/

void PrintStack(stack<int> s)
{
    // If stack is empty then return
    if (s.empty()) 
        return;
    

    int x = s.top();

    // Pop the top element of the stack
    s.pop();

    // Recursively call the function PrintStack
    PrintStack(s);

    // Print the stack element starting
    // from the bottom
    cout << x << " ";

    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

void solve() {
    int n;
    cin >> n;
    string strr;cin>>strr;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        v[i]=i+1;
    }
    vi res;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if(strr[i]=='1'){
            s.push(v[i]);
        }else if(strr[i]=='2'){
            if(!s.empty()){
            s.pop();
            res.push_back(v[i]);
            }
        }else{
            continue;
        }
    }
    
    
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    sort(all(res));
    //PrintStack(s);
    cout<<res.size()<<endl;
    printVec(res);
    //cout<<endl;
    // Your logic here
}

void test() {
    int t;
    cin >> t;
    while (t--) solve();
}

int32_t main() {
    fastio();
    test();
    //solve();
    return 0;
}