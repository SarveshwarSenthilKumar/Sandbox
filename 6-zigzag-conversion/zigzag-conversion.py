class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows <= 1 or len(s) <= numRows:
            return s
        rows = [''] * numRows
        current_row = 0
        step = -1
        for char in s:
            rows[current_row] += char
            if current_row == 0 or current_row == numRows - 1:
                step = -step
            current_row += step
        return ''.join(rows)