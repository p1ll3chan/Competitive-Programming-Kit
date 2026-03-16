#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<int> seen(n+1,0);
        seen[1]=1;
        for (int i = 2; i*i < n; i++)
        {
            if(seen[i])continue;
            for (int j = i*i; j <= n; j+=i)
            {
                seen[j]=1;
            } 
        }
        vector<int> ans;
        for (int i = 2; i < n; i++)
        {
            if(!seen[i]) ans.push_back(i);
        }
        return ans.size();
    }
};


int main(){
    int n;cin>>n;
    Solution s;
    cout<<s.countPrimes(n)<<endl;
    return 0;
}