class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            checker = target - nums[i]
            if checker in nums[i+1:len(nums)]:
                 return [i, nums[i+1:len(nums)].index(checker)+i+1]