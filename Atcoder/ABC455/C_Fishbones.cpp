#include <bits/stdc++.h>
using namespace std;

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
#define YESNO(x) cout << ((x) ? "YES" : "NO") << endl
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debugArr(arr) for (auto v : arr) cerr << v << " "; cerr << endl;
#define readVec(v, n) for (int i = 0; i < n; ++i) cin >> v[i];
#define readMatrix(mat, n, m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mat[i][j];
#define printVec(v) for (auto x : v) cout << x << " "; cout << endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }
#define fp(i, a, b) for (int i = (a); i < (b); ++i)

bool rightone(string s,vector<int>& v){
    //map<char,int> mp;
    vector<int> make(26,0);
    //for(auto c : v) mp[c]++;
    // for(auto c : s){
    //     if(mp[c]==0) return false;
    //     mp[c]--;
    // }
    for(auto c : s)make[c-'a']++;
    for (int i = 0; i < 26; i++)
    {
        if(make[i] > v[i]) return false;
    }
    
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> freq;
    for (int i = 0; i < n; i++)
    {
        int a,b;cin>>a>>b;
        freq.pb({a,b});
    }
    int m;cin>>m;
    vector<string> v;
    for (int i = 0; i < m; i++)
    {
        string s;cin>>s;
        v.pb(s);
    }
    //vector<char> take;
    vector<int> take(26,0);
    for (int i = 0; i < freq.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if(v[j].size()==freq[i].first && freq[i].second - 1 < v[j].size()){
                //take.pb(v[j][freq[i].second-1]);
                char x=v[j][freq[i].second-1];
                take[x-'a']++;
            }
        }
    }
    //printVec(take);
    for (int i = 0; i < m; i++)
    {
        if(rightone(v[i],take))YES;
        else NO;
    }
    
    

}

void test() {
    int t;
    cin >> t;
    while (t--) solve();
}

int32_t main() {
    fastio();
    // test();
    solve();
    return 0;
}