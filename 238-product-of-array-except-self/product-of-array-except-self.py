class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        updatedValues=[1]*len(nums)
        for i in range(1,len(nums)):
            updatedValues[0]*=nums[i]
        for i in range(1,len(nums)):
            if nums[i]!=0:
                updatedValues[i]=int(updatedValues[0]*nums[0]/nums[i])
            else:
                for j in range(0,len(nums)):
                    if j!=i:
                        updatedValues[i]*=nums[j]
        return updatedValues