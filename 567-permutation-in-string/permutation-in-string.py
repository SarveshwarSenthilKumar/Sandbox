class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        iterator=0
        while iterator+len(s1)<=len(s2):
            tempS1 = s1
            substring=s2[iterator:iterator+len(s1)]
            for letter in substring:
                if letter in tempS1:
                    tempS1=tempS1.replace(letter,"",1)
                else:
                    break
            if len(tempS1) == 0:
                return True
            iterator+=1
        return False