#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int N,K;cin>>N>>K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin>>arr[i];
        }

        vector<long long> pref(N+1,0);

        pref[0]=0;
        for (int i = 0; i < N; i++)
        {
            pref[i+1]=pref[i]+arr[i];
        }
        // [(pref[r+1]-pref[l])%K=0] -> THIS IS THE 
        // So if we formula the expression further

                            // pref[r+1]%K = pref[l]%K

        /*
        It is stated that R-L+1 = K+1, where K+1 is the least range to search
        quantify the form,
        R-L = K
        then if we fix the search for R from K -> N, by math
                        L <= R-K

        Thus we can reduce the search complexity to frequency array with this idea over the R run
        
        */
        long long ans = 0;
        vector<long long> freq(K, 0);
        // L <= R - K
        for(int r = K; r < N; r++) {

            int l = r-K;
            freq[pref[l] % K]++;
            ans += freq[pref[r+1] % K];
        }

        /*
        freq[x] stores how many eligible starting positions have prefix remainder x.
        pref[r+1] % K is the remainder of the current ending prefix.
        Matching remainders mean the subarray sum is divisible by K.
        
        */

        //Why don't we need to remove old prefix remainders from freq[]
        //-> Every prefix remainder inserted remains eligible for all subsequent right endpoints bcz, 
                // L <= R - K, L is dependent to R and range will never decrease but always expand and is visible.

        cout<<ans<<endl;
    }
    return 0;
}