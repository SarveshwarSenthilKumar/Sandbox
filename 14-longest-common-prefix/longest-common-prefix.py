class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        substring=strs[0]
        for word in strs:
            while substring not in word[:len(substring)]:
                substring=substring[:-1]
                if len(substring) == 0:
                    break
        return substring