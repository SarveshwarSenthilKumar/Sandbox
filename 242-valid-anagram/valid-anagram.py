class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        for i in t:
            if i in s:
                s=s.replace(i, "", 1)
            else:
                return False
        if len(s) > 0:
            return False
        return True