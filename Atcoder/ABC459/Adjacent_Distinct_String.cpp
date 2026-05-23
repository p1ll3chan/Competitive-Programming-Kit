#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define int long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0)

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> freq(26, 0);

    for(char c : s)
        freq[c - 'a']++;

    int mx = *max_element(freq.begin(), freq.end());

    if(mx > (n + 1) / 2) {
        cout << "NO\n";
        return;
    }

    priority_queue<pair<int,char>> pq;

    for(int i = 0; i < 26; i++) {
        if(freq[i])
            pq.push({freq[i], char('a' + i)});
    }

    string ans = "";

    pair<int,char> prev = {0, '#'};

    while(!pq.empty()) {

        auto [cnt, ch] = pq.top();
        pq.pop();

        ans += ch;
        cnt--;

        // push previous back
        if(prev.first > 0)
            pq.push(prev);

        prev = {cnt, ch};
    }

    cout << "YES\n";
    cout << ans << '\n';
}

int32_t main() {
    fastio();

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}