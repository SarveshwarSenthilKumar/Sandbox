class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        nums.sort()
        longest = 1
        current = 1

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                continue  
            elif nums[i] == nums[i - 1] + 1:
                current += 1
            else:
                current = 1  
            longest = max(longest, current)
        if len(nums) < 2:
            return len(nums)
        return longest