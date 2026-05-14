#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define ssz(x) (int)((x).size())
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

/*
----
Problem:

My Intuition:

There are N members in a group and we need to assign each member need to be in a team.
inital there are no teams.
In M operation,
We take 2 members, Ui and Vi then merge them one by one with their previous team and each team formation count 
respective flag count.

Find the distinct number of flag after M operation.

Approach 1:

    DFS was my first thought then found there is no queries about the components or connection nodes.
    Using set/vector upon each numbers and team will be very costly

Why Failed:
    Too complexity mess under my idea.

Approach 2:
    DSU [Union - Find] + Flag count 

    

Example Process:

Final Learning:

------
*/
// DSU Templete
vector<int> parent_, sz, color;
map<int,int> freq;

int find(int x){
    if(parent_[x] == x)
        return x;

    return parent_[x] = find(parent_[x]);
}

void add_color(int c){
    freq[c]++;
}

void remove_color(int c){
    freq[c]--;

    if(freq[c] == 0)
        freq.erase(c);
}

void solve() {
     int n,m;
    cin >> n >> m;

    parent_.resize(n);
    sz.assign(n,1);
    color.assign(n,-1);

    for(int i=0;i<n;i++)
        parent_[i]=i;

    while(m--){

        int u,v,c;
        cin >> u >> v >> c;

        u--;
        v--;

        int ru = find(u);
        int rv = find(v);

        // already same team
        if(ru == rv){

            if(color[ru] != -1)
                remove_color(color[ru]);

            color[ru] = c;

            add_color(c);
        }

        // different teams
        else{

            if(color[ru] != -1)
                remove_color(color[ru]);

            if(color[rv] != -1)
                remove_color(color[rv]);

            // union by size
            if(sz[ru] < sz[rv])
                swap(ru, rv);

            parent_[rv] = ru;
            sz[ru] += sz[rv];

            color[ru] = c;

            add_color(c);
        }
    }

    cout << freq.size() << "\n";
    
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