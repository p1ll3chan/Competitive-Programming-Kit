class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1; 
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++,mid++;
            }else if(nums[mid]==1){
                mid++;
            }else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

/*
    We used the Dutch-Flag partition sorting algorithum

    just like the colors RED,White,Blue.... We take 0,1,2

    We will have 3 operational swapping in 3 condition. but will be considering the swapping for only 2 entities,the '0' and '2'
    Reason is that since the goal is sorting we only need make minimum at left most side and maximum at right most side and the middle entity can remain as it is since no work is needed there.
    Thuse we apply the two pointer method for the job.

*/