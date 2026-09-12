class Solution(object):
    def two_sum(self, nums, target):
        freq={}

        for i, num in enumerate(nums):
            compl = target - num

            if compl in freq:
                return [freq[compl], i]
            freq[num]=i

solution=Solution()

nums=[3,2,4]
target=6

   
    
print(solution.two_sum(nums,target))

