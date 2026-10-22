class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = set()
        start = 0
        largest = 0

        for end in range(len(s)):
            while s[end] in seen:
                seen.remove(s[start])
                start += 1

            seen.add(s[end])
            largest = max(largest, end - start + 1)

        return largest