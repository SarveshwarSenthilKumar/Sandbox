class Solution:
    def maxArea(self, heights: List[int]) -> int:
        maxArea=0
        leftSide=0
        rightSide=1
        while (leftSide!=len(heights)-rightSide):
            area=((len(heights)-rightSide)-leftSide)*min(heights[leftSide], heights[-rightSide])

            if area > maxArea:
                maxArea = area
            if heights[leftSide]<heights[-rightSide]:
                leftSide+=1
            else:
                rightSide+=1
        return maxArea
        