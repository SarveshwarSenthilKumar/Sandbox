class Solution:
    def longestPalindrome(self, s: str) -> str:
        curr_longest = ""
        n = len(s)
        
        for start in range(n):
            for end in range(start + 1, n + 1):
                sub = s[start:end]
                if sub == sub[::-1] and len(sub) > len(curr_longest):
                    curr_longest = sub
                    
        return curr_longest