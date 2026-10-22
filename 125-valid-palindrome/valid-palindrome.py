class Solution:
    def isPalindrome(self, s: str) -> bool:
        newStr=""
        for i in s:
            if i.isalnum():
                newStr+=i.lower()
        return newStr[::-1] == newStr