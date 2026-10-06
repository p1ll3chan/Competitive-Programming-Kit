#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++) freq[nums[i]]++;
        for(auto &it:freq){
            if(it.second>n/2){
                return it.first;
        }
    }
         return -1;
    }
};

int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    vector<int> v;
    while(ss>>s){
        v.push_back(stoi(s));
    }
    Solution Sol;
    cout<<Sol.majorityElement(v)<<endl;
    return 0;
}

/*
The Boyer-Moore Voting Algorithm is an optimal, highly efficient streaming algorithm used to find the majority element in a sequence—defined as an element that appears more than \(\lfloor N/2 \rfloor\) times. 

Algorithum:
Initialize candidate to any value and count to 0.
Iterate through each element in the array:
    If count is 0, set the current element as the new candidate and set count to 1.
    Otherwise, if the current element equals candidate, increment count.
    Otherwise, decrement count.
Return candidate.
*/