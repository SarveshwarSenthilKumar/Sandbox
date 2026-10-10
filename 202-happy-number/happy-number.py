class Solution:
    def isHappy(self, n: int) -> bool:
        seenNumbers=[1]
        while n not in seenNumbers[:-1]:
            n=str(n)
            total=0
            for i in range(len(n)):
                total+=int(n[i])*int(n[i])
            n=int(total)
            seenNumbers.append(n)
        if n == 1:
            return True
        return False