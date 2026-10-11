class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        if not digits:
            return []

        # Index 0 is "2", index 1 is "3", ..., index 7 is "9"
        letters = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

        result = [""]

        for digit in digits:
            idx = int(digit) - 2
            temp = []
            for combo in result:
                for letter in letters[idx]:
                    temp.append(combo + letter)
            result = temp

        return result