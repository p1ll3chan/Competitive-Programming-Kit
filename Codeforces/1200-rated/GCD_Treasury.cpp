#include <bits/stdc++.h>
#define ll long long

const int N = 3e5 + 12;
using namespace std;

int n, x, a[N], p[N];
ll cnt[N];

vector <int> vc[N];

void solve()
{
	cin >> n >> x;
	
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		int r = a[i];
		a[i] = __gcd(a[i], x);
		
		for(auto j : vc[a[i]])
		{
			cnt[j] += r;
		}
	}
	ll ans = 0;
	
	for(auto j : vc[x])
	{
		ans = max(ans, cnt[j]);
	}
	for(int i = 1; i <= n; i ++)
	{
		for(auto j : vc[a[i]]) cnt[j] = 0;
	}
	cout << ans << '\n';
}
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	for(int i = 2; i <= N - 12; i ++)
	{
		if(!p[i])
		{
			for(int j = i; j <= N - 12; j += i)
			{
				p[j] = 1;
				vc[j].push_back(i);
			}
		}
	}
	int test = 0;
	if(!test) cin >> test;
	while(test --) solve();
}
// solved by KluydQ