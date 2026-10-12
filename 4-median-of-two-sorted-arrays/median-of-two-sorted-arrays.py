class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        totalNums = nums1 + nums2
        totalNums.sort()
        n = len(totalNums)
        
        mid = n // 2
        if n % 2 == 1:
            return float(totalNums[mid])
        else:
            return (totalNums[mid - 1] + totalNums[mid]) / 2.0