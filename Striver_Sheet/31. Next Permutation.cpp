class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
        for(auto x:nums){
            cout<<x<<" ";
        }
    }
};


/*
 -> Solution

 I used the basic method which took 3ms . next_permuatation function to update the array to it it next laxographically largest of the current array form. that is first to 2nd form that all.


 -> Note

 permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container.


*/