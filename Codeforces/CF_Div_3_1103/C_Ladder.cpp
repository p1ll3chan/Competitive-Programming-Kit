#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define rall(c) c.rbegin(),c.rend()
#define vii vector<vector<int>>
#define pii pair<int, int>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define YESNO(x) cout << ((x) ? "Yes" : "No") << endl
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

Approach 1: The Logic about [/\] and [\/], where on the right track, checking only if the [l,r] segemtn has [\/], has not enough for chekcing.

Why Failed:

Approach 2:

Example Process:

Final Learning:

------
*/

void solve() {
    int n,m;cin>>n>>m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    for (int i = 0; i < v.size()-1; i++){
        if(v[i]==v[i+1]) v.erase(v.begin()+i);
    }
    for (int i = 0; i < m; i++)
    {
        int cnt=0;

        int l,r;cin>>l>>r;l--;r--;
        for (int j = l; j <=r  && j+2 < v.size(); j++)
        {
            //if(v[j]<v[j+1] && v[j+1]>v[j+2]) cnt++;

            if(v[j]>v[j+1] && v[j+1]<v[j+2]) {
                cout<<"NO"<<endl;
                break;
            }
        }
        cout<<"YES"<<endl;
        // if(cnt_check(cnt)) cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;
    }
}

void solve1(){
    int n,m;cin>>n>>m;
    vi v(n);
    readVec(v,n);

    vi tor(n),tol(n);
    iota(tor.begin(),tor.end(),0);
    iota(tol.begin(),tol.end(),0);

    tol[0]=0;
    for (int i = 1; i < n; i++)
    {
        if(v[i-1]>=v[i]) tol[i]=tol[i-1];
    }

    tor[n-1]=n-1;
    for (int i = n-2; i >= 0; i--)
    {
        if(v[i]<=v[i+1]) tor[i]=tor[i+1];
    }
    
    while(m--){
        int l,r;cin>>l>>r;l--,r--;
        YESNO(tol[r]<=tor[l]);
    }
}

void test() {
    int t;
    cin >> t;
    while (t--) solve1();
}

int32_t main() {
    fastio();
    // test();
    solve1();
    return 0;
}