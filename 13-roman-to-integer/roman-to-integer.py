class Solution:
    def romanToInt(self, s: str) -> int:
        numerals = "IVXLCDM"
        values = [1, 5, 10, 50, 100, 500, 1000]  # Removed duplicate 50
        prefixers = "IXC"
        total = 0
        i = 0

        while i < len(s):
            if (
                s[i] in prefixers
                and i + 1 < len(s)
                and 0 < numerals.index(s[i + 1]) - numerals.index(s[i]) <= 2
            ):
                total += values[numerals.index(s[i + 1])] - values[numerals.index(s[i])]
                i += 2 
            else:
                total += values[numerals.index(s[i])]  
                i += 1

        return total