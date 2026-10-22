class Solution:
    def intToRoman(self, num: int) -> str:
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        
        final_str = []
        for val, sym in zip(values, symbols):
            if num == 0:
                break
            count = num // val
            if count:
                final_str.append(sym * count)
                num %= val
                
        return "".join(final_str)