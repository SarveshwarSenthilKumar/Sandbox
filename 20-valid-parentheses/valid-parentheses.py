class Solution:
    def isValid(self, s: str) -> bool:
        brackets="()[]{}"
        openBrackets=[]
        for bracket in s:
            if (brackets.index(bracket)+1)%2!=0:
                openBrackets.append(bracket)
            else:
                if (len(openBrackets) == 0):
                    return False
                elif (brackets[brackets.index(bracket)-1] == openBrackets[-1]):
                    openBrackets = openBrackets[:-1]
                else:
                    return False
        return len(openBrackets) == 0