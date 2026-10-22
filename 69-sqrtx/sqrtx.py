class Solution:
    def mySqrt(self, x: int) -> int:
        lowestInteger=0
        for i in range(x+1):
            if i*i<=x:
                lowestInteger=i
            else:
                break
        return lowestInteger