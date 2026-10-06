#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
B - Cyclic Shift
================================================================================

You are given an array a = [a1, a2, ..., an] of n integers.

For any array b = [b1, b2, ..., bn] of length n, define

        f(b) = max( |b1 - b2|, |b2 - b3|, ..., |b_{n-1} - b_n| )

i.e. f(b) is the maximum absolute difference between two adjacent elements of b.

A cyclic shift of a is an array of the form

        [a_k, a_{k+1}, ..., a_n, a_1, a_2, ..., a_{k-1}]

for some 1 <= k <= n. In particular, choosing k = 1 leaves the array unchanged.

Task: Find the minimum possible value of f(b) over all cyclic shifts b of a.

        Answer = min over k in [1, n] of f( cyclic_shift(a, k) )
================================================================================
*/

int main() {
	// your code goes here
	int T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    vector<int> arr(N);
	    for (int i = 0; i < N; i++) {
	        cin>>arr[i];
	    }
	    vector<int> new_arr;
	    for (int i = 0; i < N; i++) {
	        int a_val=(i+1==N?arr[0]:arr[i+1]);
	        new_arr.push_back(abs(arr[i]-a_val));
	    }
	    sort(new_arr.begin(),new_arr.end());
	    cout<<new_arr[N-2]<<endl;
	}

}
