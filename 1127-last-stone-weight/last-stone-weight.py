class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1:
            stones.sort()
            y=stones[-1]
            x=stones[-2]
            if x==y:
                stones=stones[:-2]
            elif x<y:
                stones=stones[:-1]
                stones[-1] = y-x
        if len(stones) == 1:
            return stones[0]
        else:
            return 0