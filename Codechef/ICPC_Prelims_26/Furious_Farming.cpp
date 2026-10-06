#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
================================================================================
C - Furious Farming
================================================================================

After a long think about what career you would like to pursue, you have decided
to take up farming. Unfortunately, you overlooked a crucial detail - a farmer's
livelihood depends heavily on rain, and the rain this year has been quite poor!
So, you decide to take things into your own hands.

You have n fields, numbered 1 to n from left to right.

Using the power of cloud seeding, you have managed to create m rainclouds.
Initially, the i-th raincloud is directly above field number x_i.
It is guaranteed that all x_i are pairwise distinct.

You have also managed to, somehow, figure out a way to move the clouds by
creating a strong enough wind system. However, the system is primitive, and so
on each day, you can only either:
    - move ALL clouds left by one step, or
    - move ALL clouds right by one step.
Note that all clouds move simultaneously in the same direction on each day.

For your farming venture to be a success, every field must receive some rain -
that is, for each 1 <= i <= n, there must exist some day such that there is a
raincloud above field i.

Given that you choose the directions for cloud movements optimally, find the
minimum number of days needed to ensure that every field is visited by a
raincloud at least once.
Note that this includes the initial configuration as well, i.e. every field x_i
is considered visited even before any days have passed.
Also note that it is allowed for clouds to leave the interval [1, n] if
necessary.

--------------------------------------------------------------------------------
Input Format
--------------------------------------------------------------------------------
The first line contains a single integer t - the number of test cases.
The description of the test cases follows.

The first line of each test case contains two integers n and m - the number of
fields and the number of clouds.

The second line of each test case contains m distinct integers
x1, x2, ..., xm - the initial positions of the clouds.

--------------------------------------------------------------------------------
Output Format
--------------------------------------------------------------------------------
For each test case, print a single integer - the minimum number of days needed
to ensure that every field is visited by a raincloud at least once.

--------------------------------------------------------------------------------
Constraints
--------------------------------------------------------------------------------
1 <= t <= 2 * 10^4
1 <= m <= n <= 2 * 10^5
1 <= x_i <= n
The x_i are all distinct within each test case.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.
================================================================================
*/

int main() {
    // your code goes here
    ll T;
    cin >> T;
    while (T--) {
        ll N, M;
        cin >> N >> M;
        std::vector < ll > arr(M);
        for (ll i = 0; i < M; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        ll sumMin = 0;
        for (ll i = 0; i + 1 < M; i++) {
            sumMin = max(sumMin, arr[i + 1] - arr[i] - 1);
        }
        const ll MinL = arr[0] - 1,
            MinR = N - arr[M - 1];

        if (sumMin <= MinL + MinR) {
            cout << min(2 * MinL + MinR, 2 * MinR + MinL) << endl;
        } else {
            ll ans = LLONG_MAX;
            const ll sumDiff = sumMin - MinL - MinR;
            ll L = MinL, R = MinR + sumDiff;

            ans = min(ans, 2 * L + R);
            ans = min(ans, 2 * R + L);

            L = MinL + sumDiff, R = MinR;

            ans = min(ans, 2 * L + R);
            ans = min(ans, 2 * R + L);

            cout << ans << endl;
        }

    }
}