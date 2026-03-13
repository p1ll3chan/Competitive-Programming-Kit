#include<bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         int maxx=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(prices[j]>prices[i]) maxx=max(maxx,prices[j]-prices[i]);
//             }
//         }
//         return maxx;
//     }
// };



class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy=prices[0];
        int profit=0;
        for (int i = 0; i < prices.size(); i++)
        {
            if(prices[i]<buy){
                buy=prices[i];
            }else if(prices[i]-buy>profit){
                profit=(prices[i]-buy);
            }
        }
        return profit;
    }
};


int main(){
    
    vector<int> v={ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    Solution sol;
    int maxxx=sol.maxProfit(v);
    cout<<maxxx<<endl;
    return 0;
}

