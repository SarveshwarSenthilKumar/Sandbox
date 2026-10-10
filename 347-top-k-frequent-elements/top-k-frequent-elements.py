class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequent = {}
        for num in nums:
            frequent[num] = frequent.get(num, 0) + 1
        sorted_frequent = dict(sorted(frequent.items(), key=lambda item: item[1], reverse=True))
        top_keys = list(sorted_frequent.keys())[:k]
        return top_keys
