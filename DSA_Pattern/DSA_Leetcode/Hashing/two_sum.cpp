#include <bits/stdc++.h>
using namespace std;

vector<int> two_sum(vector<int>& v, int target){
  //Cerate a hasing platform -> Purpose : To Process the search in a single linear search for the given traget value
  unordered_map<int,int> freq;

  for (int i = 0; i < (int)v.size(); i++) {
    // State the value that is need to search here
    int val=target-v[i];
    // If that value is found before output shows "There isn't any value for our interest, return the answer "
    if(freq.find(val)!=freq.end()){
      return {freq[val],i};
    }
    // hashing is done for the given loop in the background [it not the else statement to be clear]
    freq[v[i]]=i;
  }
  // else we output this to show we got nothing
  return {-1,-1};
}

void solve() {
   vector<int>v {3,2,4};
   int target=6;
   vector<int> ans=two_sum(v,target);
   for(auto i: ans) cout<<i<<" ";
   cout<<endl;
}

void test() {
    int t;
    cin >> t;
    while (t--) solve();
}

int32_t main() {
    //fastio();
    // test();
    solve();
    return 0;
}


